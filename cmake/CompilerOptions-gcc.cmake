
set(C_COMMON   "-fPIC -std=c11")
set(CXX_COMMON "-fPIC -std=c++11")

set(C_WARN_FLAGS   "-Wall -Wextra")
set(CXX_WARN_FLAGS "-Wall -Wextra")

set(CXX_WARN_FLAGS "${CXX_WARN_FLAGS} -Wold-style-cast")
set(CXX_WARN_FLAGS "${CXX_WARN_FLAGS} -Wunreachable-code")
set(CXX_WARN_FLAGS "${CXX_WARN_FLAGS} -Woverloaded-virtual")
set(CXX_WARN_FLAGS "${CXX_WARN_FLAGS} -Wuninitialized")
#set(CXX_WARN_FLAGS "${CXX_WARN_FLAGS} -Wmissing-declarations")
#set(CXX_WARN_FLAGS "${CXX_WARN_FLAGS} -Winit-self")

set(CMAKE_C_FLAGS                  "${C_WARN_FLAGS} ${C_COMMON} -O2")
set(CMAKE_C_FLAGS_DEBUG            "${C_WARN_FLAGS} ${C_COMMON} -O0 -ggdb")
set(CMAKE_C_FLAGS_MINSIZEREL       "${C_WARN_FLAGS} ${C_COMMON} -O2")
set(CMAKE_C_FLAGS_RELEASE          "${C_WARN_FLAGS} ${C_COMMON} -O3")
set(CMAKE_C_FLAGS_RELWITHDEBINFO   "${C_WARN_FLAGS} ${C_COMMON} -O3 -ggdb")

set(CMAKE_CXX_FLAGS                "${CXX_WARN_FLAGS} ${CXX_COMMON} -O2")
set(CMAKE_CXX_FLAGS_DEBUG          "${CXX_WARN_FLAGS} ${CXX_COMMON} -O0 -ggdb")
set(CMAKE_CXX_FLAGS_MINSIZEREL     "${CXX_WARN_FLAGS} ${CXX_COMMON} -O2")
set(CMAKE_CXX_FLAGS_RELEASE        "${CXX_WARN_FLAGS} ${CXX_COMMON} -O3")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CXX_WARN_FLAGS} ${CXX_COMMON} -O3 -ggdb")

set(CMAKE_EXE_LINKER_FLAGS         "-O2 -Wall -Wextra")
set(CMAKE_SHARED_LINKER_FLAGS      "-O2 -Wall -Wextra")
set(CMAKE_MODULE_LINKER_FLAGS      "-O2 -Wall -Wextra")

