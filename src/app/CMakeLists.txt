find_package(Qt6 REQUIRED COMPONENTS Core LinguistTools)

file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE XLP_TS_FILES ${xplotter_SOURCE_DIR}/src/lang/*.ts)


get_target_property(QT_LUPDATE_EXECUTABLE Qt::lupdate IMPORTED_LOCATION)
add_custom_target(xp_update_translations
                    COMMAND ${QT_LUPDATE_EXECUTABLE} -extensions ui,c,c++,cc,cpp,cxx,ch,h,h++,hh,hpp,hxx
                                                     ${xplotter_SOURCE_DIR}
                                                     -ts ${XP_TS_FILES}
                    WORKING_DIRECTORY "${xplotter_SOURCE_DIR}"
                    VERBATIM
                    COMMAND_EXPAND_LISTS)

set_source_files_properties(${XP_TS_FILES} PROPERTIES OUTPUT_LOCATION "${xplotter_BINARY_DIR}/src/lang")
qt6_add_translation(XLP_QM_FILES ${XP_TS_FILES} OPTIONS -removeidentical -silent)
configure_file("${xplotter_SOURCE_DIR}/src/lang/lang.qrc" "${xplotter_BINARY_DIR}/src/lang/lang.qrc" COPYONLY)

message("================= APP_CMAKE =================")

message("${headers}")
message("${sources}")
message("${XP_TS_FILES}")

message("================= APP_CMAKE =================")

add_executable(xp_app)

target_sources(xp_app PRIVATE
    ${headers}
    ${sources}
    # ${XP_QM_FILES}
    # "${xplotter_BINARY_DIR}/src/lang/lang.qrc"
)


set_target_properties(xp_app PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set_target_properties(xp_app PROPERTIES OUTPUT_NAME xplotter)


target_link_libraries(xp_app PRIVATE xp_gui)


install(TARGETS xp_app
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    BUNDLE  DESTINATION .
    COMPONENT runtime
)

if (MSVC)
    install(FILES $<TARGET_PDB_FILE:xp_app>
        DESTINATION ${CMAKE_INSTALL_BINDIR}
        OPTIONAL
    )
endif()


