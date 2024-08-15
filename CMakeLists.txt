cmake_minimum_required(VERSION 3.28)
project(AsteroidBelt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(PROJECT_ROOT ${CMAKE_SOURCE_DIR})

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_executable(AsteroidBelt Sources/main.cpp
        Sources/Registry.cpp
        Sources/UIButton.cpp
        Headers/UI/Button/UIButton.h
        Headers/Registry.h
        Sources/Registry.cpp
        Headers/Scene/Scene.h
        Headers/Scene/MakeScene.h
        Sources/MakeScene.cpp
        Sources/Scene.cpp
        Headers/UI/Button/UIDynamicButton.h
        Headers/UI/Button/UIStaticButton.h
        Sources/UIStaticButton.cpp
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(C:/SFML-2.6.1/include/SFML)


set(VLD_DIR "C:/Program Files (x86)/Visual Leak Detector")
include_directories(${VLD_DIR}/include)
target_link_directories(AsteroidBelt PRIVATE ${VLD_DIR}/lib/Win64)
add_definitions(-DVLDBUILD)


target_link_libraries(AsteroidBelt PRIVATE sfml-system sfml-window sfml-graphics sfml-audio vld)
target_compile_features(AsteroidBelt PRIVATE cxx_std_23)
