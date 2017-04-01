cmake_minimum_required(VERSION 3.6)
project(snippets_cpp)

#find_package(Boost COMPONENTS system filesystem REQUIRED)
#IF (Boost_FOUND)
#    include_directories(${Boost_INCLUDE_DIR})
#endif()

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main.cpp)
#add_executable(Vector src/Vector_container.cpp src/List_container.h)
#add_executable(VirtualFunc src/Shape.h src/Point.h src/Circle.h src/Face.cpp src/Triangle.h)
#add_executable(user_defined_hash_func src/user_defined_hash_func_function.cpp)
#add_executable(user_defined_hash_func src/user_defined_hash_func_lambda.cpp)
add_executable(user_defined_hash_func src/user_defined_hash_func_functor.cpp)
