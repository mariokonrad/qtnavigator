cmake_minimum_required(VERSION 2.8.11)

# TODO: support for Windows / Visual Studio 2012?

project(qtnavigator)

set(PACKAGE_NAME "qtnavigator")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL)

# TODO: installation of Qt libs

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${Qt5Core_INCLUDE_DIRS})

include(CompilerOptions-gcc)

include(ExternalProject)
include(ExternGmock)
include(GitInformation)

add_subdirectory(src/plugin_core)
add_subdirectory(plugins/TestPlugin)
add_subdirectory(src)

add_dependencies(TestPlugin plugin_core)

# --- tests

add_custom_target(unittest)
macro(run_unittest unittest_target)
	add_custom_target(${unittest_target}_runtest
		COMMAND bin/${unittest_target} --data-root ${CMAKE_SOURCE_DIR}/data
		DEPENDS ${unittest_target}
		WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
		)
	add_dependencies(unittest ${unittest_target}_runtest)
endmacro()

add_subdirectory(src_test)

# --- data

file(GLOB GSHHS_RESOURCES "${CMAKE_CURRENT_SOURCE_DIR}/data/gshhs/*")
install(FILES ${GSHHS_RESOURCES}
	DESTINATION
		share/${PACKAGE_NAME}/gshhs
	PERMISSIONS
		OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
	)

# --- packaging

set(VERSION_MAJOR "0")
set(VERSION_MINOR "0")
set(VERSION_PATCH "0")

set(CPACK_PACKAGE_VERSION_MAJOR ${VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${VERSION_PATCH})
set(CPACK_PACKAGE_VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
set(CPACK_PACKAGE_NAME "${PACKAGE_NAME}")
set(CPACK_PACKAGE_VENDOR "Mario Konrad")
set(CPACK_PACKAGE_CONTACT "Mario Konrad <mario.konrad@gmx.net>")
set(CPACK_PACAKGE_DESCRIPTION "${PACKAGE_NAME}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Nautical navigation software")
set(CPACK_MONOLITHIC_INSTALL 1)
set(CPACK_PACKAGE_EXECUTABLES "${PACKAGE_NAME}" "${PACKAGE_NAME}")
set(CPACK_STRIP_FILES true)

# --- tar package

# TODO

# --- zip package

# TODO

# --- debian package

set(CPACK_DEBIAN_PACKAGE_NAME ${CPACK_DEBIAN_PACKAGE_NAME})
set(CPACK_DEBIAN_PACKAGE_MAINTAINER ${CPACK_PACKAGE_CONTACT})
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION ${CPACK_PACAKGE_DESCRIPTION})
set(CPACK_DEBIAN_PACKAGE_DEPENDS
	"libc6 (>= 2.17-0ubuntu5)"
	)
set(CPACK_DEBIAN_PACKAGE_SECTION "misc")
if (CMAKE_SIZEOF_VOID_P MATCHES "8")
        set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
else()
        set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "i386")
endif()

# --- general packaging

include(CPack)
