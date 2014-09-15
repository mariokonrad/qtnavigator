cmake_minimum_required(VERSION 2.8.11)
project(TestPlugin)
message(STATUS "TARGET: TestPlugin (plugin)")
message(STATUS ". CMAKE_BUILD_TYPE       : ${CMAKE_BUILD_TYPE}")
message(STATUS ". CMAKE_CXX_COMPILER     : ${CMAKE_CXX_COMPILER}")
message(STATUS ". CMAKE_CXX_FLAGS        : ${CMAKE_CXX_FLAGS}")
message(STATUS ". CMAKE_CXX_FLAGS_DEBUG  : ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS ". CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")

# set correct output directory also for builds
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/plugins")

# RPATH handling
set(CMAKE_SKIP_BUILD_RPATH false)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib:$ORIGIN/../lib:$$ORIGIN/../lib:$ORIGIN/..:$$ORIGIN/..")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

add_definitions(-DQT_PLUGIN)

include_directories(${plugin_core_INCLUDE_DIRS})

add_library(TestPlugin SHARED
	TestPlugin.cpp
	)

target_link_libraries(TestPlugin
	plugin_core
	Qt5::Core
	)

install(
	TARGETS TestPlugin
	DESTINATION lib/plugins
	)

