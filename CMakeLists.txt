cmake_minimum_required(VERSION 3.0)
project(LBlocks)
set(CMAKE_INSTALL_PREFIX d:/projects/lib)
# set(BUILD_TEST 1)
if(BUILD_TEST)
    message("-- Build test of simple pd control for a mass system")
    add_executable(test src/test/main.cpp)
    target_include_directories(test PUBLIC ./include)
endif()

install(DIRECTORY include/LBlocks DESTINATION include)

set(LBlocks_include_dirs ${CMAKE_INSTALL_PREFIX}/include)
configure_file(
    LBlocksConfig.cmake.in
    "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/LBlocksConfig.cmake" @ONLY
)
install(
    FILES
    "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/LBlocksConfig.cmake"
    DESTINATION share/LBlocks/cmake COMPONENT dev
)