include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

project(tester)

file(GLOB_RECURSE source *.cc)

add_executable(${PROJECT_NAME} ${source})
target_link_libraries(${PROJECT_NAME} PUBLIC
    net
    GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
