
message("@@ ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_BUILD_TYPE       : ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_C_COMPILER       : ${CMAKE_C_COMPILER}")
message(STATUS "CMAKE_C_FLAGS          : ${CMAKE_C_FLAGS}")
message(STATUS "CMAKE_C_FLAGS_DEBUG    : ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "CMAKE_C_FLAGS_RELEASE  : ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "CMAKE_CXX_COMPILER     : ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CXX_FLAGS        : ${CMAKE_CXX_FLAGS}")
message(STATUS "CMAKE_CXX_FLAGS_DEBUG  : ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "CMAKE_INSTALL_PREFIX   : ${CMAKE_CMAKE_INSTALL_PREFIX}")

file(GLOB_RECURSE TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")
message(STATUS "Tests found: ${TEST_NAME}")
foreach(TEST_FILE ${TEST_SRC})
	string(REGEX REPLACE ".*src_test/" "" TEST_NAME ${TEST_FILE})
	message(STATUS ":  ${TEST_NAME}")
endforeach(TEST_FILE)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(testrunner
	${TEST_SRC}
	${CMAKE_SOURCE_DIR}/src/chart/gshhs/Point.cpp
	${CMAKE_SOURCE_DIR}/src/chart/gshhs/Polygon.cpp
	${CMAKE_SOURCE_DIR}/src/chart/gshhs/Reader.cpp
	)

target_link_libraries(testrunner
	gmock
	pthread
	)

run_unittest(testrunner)

