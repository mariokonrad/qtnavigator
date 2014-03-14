cmake_minimum_required(VERSION 2.8.11)

project(TestPlugin)

add_definitions(-DQT_PLUGIN)

add_library(TestPlugin SHARED
	TestPlugin.cpp
	TestPlugin.hpp
	)

install(
	TARGETS TestPlugin
	DESTINATION lib/plugins
	)

