project(net)

file(GLOB_RECURSE source *.cc)
file(GLOB_RECURSE header *.hh *.hxx)

add_library(${PROJECT_NAME} ${source} ${header})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
