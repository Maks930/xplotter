file(GLOB_RECURSE TEST_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)


add_executable(core_test ${CMAKE_CURRENT_SOURCE_DIR}/CoreTests.cpp)
target_link_libraries(core_test gtest gtest_main xp_core glaze::glaze)