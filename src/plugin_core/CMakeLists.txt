cmake_minimum_required(VERSION 2.8.11)
project(plugin_core)
message(STATUS "TARGET: plugin_core (library)")
message(STATUS ". CMAKE_BUILD_TYPE       : ${CMAKE_BUILD_TYPE}")
message(STATUS ". CMAKE_CXX_COMPILER     : ${CMAKE_CXX_COMPILER}")
message(STATUS ". CMAKE_CXX_FLAGS        : ${CMAKE_CXX_FLAGS}")
message(STATUS ". CMAKE_CXX_FLAGS_DEBUG  : ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS ". CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")

# RPATH handling
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

add_library(plugin_core SHARED
	Plugin.cpp
	Plugin.hpp
	Renderer.hpp
	)

set_target_properties(plugin_core
	PROPERTIES VERSION 0.0.1
	SOVERSION 0.0.1
	)

target_link_libraries(plugin_core
	Qt5::Core
	)

install(
	TARGETS plugin_core
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	)

install(
	FILES
		Manager.hpp
		Plugin.hpp
		Renderer.hpp
	DESTINATION
		include/qtnavigator/plugin
	)

set(plugin_core_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}")

