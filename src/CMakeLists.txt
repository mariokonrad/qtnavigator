cmake_minimum_required(VERSION 2.8.11)
message(STATUS "TARGET: qtnavigator (executable)")
message(STATUS ". CMAKE_BUILD_TYPE       : ${CMAKE_BUILD_TYPE}")
message(STATUS ". CMAKE_CXX_COMPILER     : ${CMAKE_CXX_COMPILER}")
message(STATUS ". CMAKE_CXX_FLAGS        : ${CMAKE_CXX_FLAGS}")
message(STATUS ". CMAKE_CXX_FLAGS_DEBUG  : ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS ". CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")

# RPATH handling
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH true)

add_executable(qtnavigator
	main.cpp
	MainWindow.cpp
	MapWidget.cpp
	ChartModel.cpp
	plugin/DefaultManager.cpp
	action/ExitApplication.cpp
	action/Fullscreen.cpp
	action/About.cpp
	action/AboutQt.cpp
	action/ZoomIn.cpp
	action/ZoomOut.cpp
	utils/range.cpp
	geo/Position.cpp
	chart/Factory.cpp
	chart/FactoryRegistry.cpp
	chart/Chart.cpp
	chart/Renderer.cpp
	chart/gshhs/Point.cpp
	chart/gshhs/Polygon.cpp
	chart/gshhs/Factory.cpp
	chart/gshhs/Chart.cpp
	chart/gshhs/Reader.cpp
	chart/gshhs/Renderer.cpp
	)

target_link_libraries(qtnavigator
	Qt5::Widgets
	Qt5::OpenGL
	plugin_core
	)

install(
	TARGETS qtnavigator
	RUNTIME DESTINATION bin
	COMPONENT applications
	)

