cmake_minimum_required(VERSION 3.20)
project(HDoc C)

add_subdirectory(external/raylib)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB SRC CONFIGURE_DEPENDS *.c)
add_executable(HDoc ${SRC})
target_compile_options(
    HDoc PRIVATE
    -Wall -Wextra -Werror
    -Wdisabled-optimization
)

target_link_libraries(
    HDoc PRIVATE
    raylib
)

