cmake_minimum_required (VERSION 3.8)

project (learn_cmake)

add_subdirectory(libs/wxWidgets-3.2.5)

add_executable(myapp src/main.cpp)

target_link_libraries(myapp wx::net wx::core wx::base)
