find_package(Qt6 ${minQt6Version} REQUIRED COMPONENTS Widgets LinguistTools)

file(GLOB_RECURSE headers       ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE sources       ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)


message("================= GUI_CMAKE =================")
message("${headers}")
message("${sources}")

message("================= GUI_CMAKE =================")


add_library(xp_core STATIC ${sources} ${headers})


# If needed qrc files
# target_sources(xp_gui INTERFACE about.qrc)


# UI headers will be generated in ${CMAKE_CURRENT_BINARY_DIR}
target_include_directories(xp_core PRIVATE ${CMAKE_CURRENT_BINARY_DIR})


target_link_libraries(xp_core
        PRIVATE
            glaze::glaze

)
