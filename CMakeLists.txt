# CMakeList.txt : CMake project for VenWorld, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(PROJECT_NAME VenWorld)
project (${PROJECT_NAME})

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "VenWorld.cpp" "VenWorld.h")


# glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)


# glad
add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

# TODO: Add tests and install targets if needed.
