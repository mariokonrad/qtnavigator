
add_executable(qtnavigator
	main.cpp
	MainWindow.hpp
	MainWindow.cpp
	MapWidget.hpp
	MapWidget.cpp
	plugins/Plugin.hpp
	plugins/Manager.hpp
	plugins/DefaultManager.hpp
	plugins/DefaultManager.cpp
	action/ExitApplication.hpp
	action/ExitApplication.cpp
	action/Fullscreen.hpp
	action/Fullscreen.cpp
	action/About.hpp
	action/About.cpp
	action/AboutQt.hpp
	action/AboutQt.cpp
	chart/gshhs/Point.hpp
	chart/gshhs/Point.cpp
	chart/gshhs/Polygon.hpp
	chart/gshhs/Polygon.cpp
	chart/gshhs/Chart.hpp
	chart/gshhs/Chart.cpp
	chart/gshhs/Reader.hpp
	chart/gshhs/Reader.cpp
	)

target_link_libraries(qtnavigator
	Qt5::Widgets
	Qt5::OpenGL
	)

install(
	TARGETS qtnavigator
	DESTINATION bin
	COMPONENT applications
	)

