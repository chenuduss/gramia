project(cpp-test)
cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)

aux_source_directory(. SRC_LIST)

list(APPEND SRC_LIST "../srv/orderlist.cpp")
list(APPEND SRC_LIST "../srv/orderlist.hpp")
list(APPEND SRC_LIST "../srv/order.cpp")
list(APPEND SRC_LIST "../srv/order.hpp")
list(APPEND SRC_LIST "../srv/orderarray.cpp")
list(APPEND SRC_LIST "../srv/orderarray.hpp")
list(APPEND SRC_LIST "../srv/floatnumber.cpp")
list(APPEND SRC_LIST "../srv/floatnumber.hpp")


add_executable(${PROJECT_NAME} ${SRC_LIST})

