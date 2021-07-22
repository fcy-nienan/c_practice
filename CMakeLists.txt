
cmake_minimum_required(VERSION 3.19)
project(fcy)
set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE mains ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
message(STATUS ${mains})
foreach(mainfile IN LISTS mains)
    get_filename_component(mainname ${mainfile} NAME_WE)
    add_executable(${mainname} ${mainfile})
    target_link_libraries (${mainname} ${PCL_LIBRARIES})
endforeach()