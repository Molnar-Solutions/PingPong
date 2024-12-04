# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(PingPongGame VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directories for third-party libraries
include_directories(
    ${CMAKE_SOURCE_DIR}/library/Include/glad        # Glad headers
    ${CMAKE_SOURCE_DIR}/library/Include/GLFW        # GLFW headers
    ${CMAKE_SOURCE_DIR}/library/Include/glm         # glm headers
    ${CMAKE_SOURCE_DIR}/library/Include/KHR         # KHR headers
    ${CMAKE_SOURCE_DIR}/library/Include/stb         # stb headers
    ${CMAKE_SOURCE_DIR}/src                        # Project source code
)
 
# Add all source files from the `src` directory
file(GLOB SOURCES
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*/*.cpp  # Includes subdirectories in src
)

# Add glad.c to the sources, which compiles the OpenGL loader
list(APPEND SOURCES ${CMAKE_SOURCE_DIR}/library/Include/glad/glad.c)
   
# Create the executable from the main source files and glad source
add_executable(PingPongGame ${SOURCES})   
 
# Link GLFW and other third-party libraries to the executable
target_link_libraries(PingPongGame 
    ${CMAKE_SOURCE_DIR}/library/Lib/glfw3.lib  # Linking glfw3 library
    opengl32  # Linking OpenGL library (for Windows)
)

# Ensure that glad initializes OpenGL loader correctly
target_compile_definitions(PingPongGame PRIVATE GLAD_GL_IMPLEMENTATION)

# Set the output directory for the executable
set_target_properties(PingPongGame PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/out"
)

# Optional: Add Debug or Release build type
# set(CMAKE_BUILD_TYPE Debug)

# Optional: Add compile options
if(MSVC)
  # Remove or replace /wextra for MSVC compatibility
  add_compile_options(/W4)  # Or /Wall for all warnings
else()
  # GCC/Clang case
  add_compile_options(-wextra) 
endif()
 