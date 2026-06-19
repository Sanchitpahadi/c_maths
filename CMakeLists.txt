cmake_minimum_required(VERSION 3.10)

project(MathProject)

add_library(MathLib STATIC
    src/Vec3.c
    src/Mat4.c
    src/Sphere.c
    src/AABB.c
    src/test.c


)

target_include_directories(MathLib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(math
    src/main.c
)

target_link_libraries(math PRIVATE MathLib m)