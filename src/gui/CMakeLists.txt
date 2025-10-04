find_package(Qt6 ${minQt6Version} REQUIRED COMPONENTS Widgets LinguistTools)

file(GLOB_RECURSE headers       ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE sources       ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE ui_headers    ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)

message("================= GUI_CMAKE =================")
message("${headers}")
message("${sources}")
message("${ui_headers}")



qt_wrap_ui(UI_HEADERS ${ui_headers})
message("${UI_HEADERS}")

message("================= GUI_CMAKE =================")


add_library(xp_gui STATIC ${sources} ${headers} ${UI_HEADERS})


# If needed qrc files
# target_sources(xp_gui INTERFACE about.qrc)


# UI headers will be generated in ${CMAKE_CURRENT_BINARY_DIR}
target_include_directories(xp_gui PRIVATE ${CMAKE_CURRENT_BINARY_DIR})


target_link_libraries(xp_gui
    PUBLIC
        Qt::Gui Qt::Widgets
)
