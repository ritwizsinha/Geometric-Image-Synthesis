cmake_minimum_required(VERSION 3.22)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp Shapes/Shape.cpp Shapes/Shape.h Shapes/Rectangle.cpp Shapes/Rectangle.h Shapes/Triangle.cpp Shapes/Triangle.h Shapes/RegularPolygon.cpp Shapes/RegularPolygon.h utility/BoundingBox.cpp utility/BoundingBox.h Strategies/PointInPolygonStrategy.cpp Strategies/PointInPolygonStrategy.h)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-system sfml-window sfml-audio)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")