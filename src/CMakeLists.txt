project(browser)

file(GLOB_RECURSE source *.cc)
file(GLOB_RECURSE header *.hh *.hxx)

add_executable(${PROJECT_NAME} ${source} ${header})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE net)
