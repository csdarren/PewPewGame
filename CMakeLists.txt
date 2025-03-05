cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(PewPewGame C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



# Dependencies
set(RAYLIB_VERSION 5.5)
set(raylib_DIR "C:/dev/GitHub/raylib/cmake")
include_directories("C:/dev/CPP/PewPewGame/include")
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
#if (NOT raylib_FOUND) # If there's none, fetch and build raylib
#  include(FetchContent)
#  FetchContent_Declare(
#    raylib
#    DOWNLOAD_EXTRACT_TIMESTAMP OFF
#    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
#  )
#  FetchContent_GetProperties(raylib)
#  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
#    set(FETCHCONTENT_QUIET NO)
#    FetchContent_MakeAvailable(raylib)
#    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
#  endif()
#endif()
#
# Our Project

add_executable(PewPewGame src/main.cpp)
#set(raylib_VERBOSE 1)

add_library(raylib STATIC IMPORTED)
set_target_properties(raylib PROPERTIES IMPORTED_LOCATION "C:/dev/GitHub/raylib/build/raylib/raylib.lib")
target_link_libraries(PewPewGame PRIVATE raylib winmm)
