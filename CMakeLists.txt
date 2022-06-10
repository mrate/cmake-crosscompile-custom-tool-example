cmake_minimum_required(VERSION 3.18.1)

project(somnium_compositor LANGUAGES C CXX)

# Subproject approach

#add_subdirectory(tool)

# External project approach

include(ExternalProject)

# CMAKE_DISABLE_SOURCE_CHANGES breaks ExternalProject with source dir inside source folder.
# https://gitlab.kitware.com/cmake/cmake/-/issues/18811
set(SOURCE_CHANGES_VALUE ${CMAKE_DISABLE_SOURCE_CHANGES})
set(CMAKE_DISABLE_SOURCE_CHANGES OFF)

ExternalProject_Add(somnium_tool
    PREFIX "${CMAKE_CURRENT_BINARY_DIR}/somnium_tool"
    CMAKE_ARGS
        -DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_CURRENT_BINARY_DIR}
        -DCMAKE_BUILD_TYPE=Release
    SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tool"
    BUILD_IN_SOURCE 0
)

# Restore previous value
set(CMAKE_DISABLE_SOURCE_CHANGES ${CMAKE_DISABLE_SOURCE_CHANGES})

# Run custom command

set(TOOL_INPUT ${CMAKE_CURRENT_SOURCE_DIR}/source/test.txt)
set(TOOL_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/output.h)

add_custom_command(
    COMMAND
    bin/somnium_tool
    ${TOOL_INPUT}
    ${TOOL_OUTPUT}
    ${CMAKE_SYSTEM_NAME}
  OUTPUT ${TOOL_OUTPUT}
  DEPENDS somnium_tool ${TOOL_INPUT}
  COMMENT "Running tool"
)

# Build target

add_executable(
	${PROJECT_NAME}
	source/main.cpp
    ${TOOL_OUTPUT}
)

if (ANDROID)
    target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
            android
            log
    )
endif()