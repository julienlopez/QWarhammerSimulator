cmake_minimum_required(VERSION 3.3.0 FATAL_ERROR)

project(QWarhammerSimulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    set(CMAKE_DEBUG_POSTFIX "d")
else()
	add_definitions("-fprofile-arcs")
	add_definitions("-ftest-coverage")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON) 
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(BUILD_SHARED_LIBS "Build libraries as shared as opposed to static" OFF)

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(SETTINGS cppstd=17)
conan_cmake_run(REQUIRES catch2/2.13.3 BASIC_SETUP CMAKE_TARGETS BUILD missing)
conan_cmake_run(REQUIRES tl-expected/20190710 BASIC_SETUP CMAKE_TARGETS BUILD missing)
conan_cmake_run(REQUIRES ms-gsl/3.1.0 BASIC_SETUP CMAKE_TARGETS BUILD missing)

enable_testing()

set(QWS_BUILD_GUI OFF CACHE BOOL "enable GUI building")

add_subdirectory(libs)
add_subdirectory(unit_tests)
if(${QWS_BUILD_GUI})
	add_subdirectory(QWarhammerSimulator)
endif()
