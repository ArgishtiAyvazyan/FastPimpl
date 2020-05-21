cmake_minimum_required(VERSION 3.0.0)
project(FP_LIB VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(
        -Wall
        -Wextra
        -pedantic
        -Werror
        -Wfloat-equal
        -Wshadow
        -Wpointer-arith
        -ftrapv
        -fverbose-asm
        -finstrument-functions
        -Wcast-align
        -Wstrict-overflow=5
        -Wwrite-strings
        -Wcast-qual
        -Wswitch-default
        -Wswitch-enum
        -Wconversion
        -Wunreachable-code
    )
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

add_library(FP_LIB INTERFACE)

target_include_directories(FP_LIB
    INTERFACE
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


add_subdirectory(test)
