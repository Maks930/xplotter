file(GLOB_RECURSE headers       ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE sources       ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

project(lib_lua LANGUAGES C)

add_library(lib_lua STATIC ${sources} ${headers} )

target_include_directories(lib_lua PUBLIC include)