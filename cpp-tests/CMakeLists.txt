project(cpp-test)
cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)

aux_source_directory(. SRC_LIST)

list(APPEND SRC_LIST "../srv/orderlist.cpp")
list(APPEND SRC_LIST "../srv/orderlist.hpp")
list(APPEND SRC_LIST "../srv/order.cpp")
list(APPEND SRC_LIST "../srv/order.hpp")
list(APPEND SRC_LIST "../srv/baseorderarray.cpp")
list(APPEND SRC_LIST "../srv/baseorderarray.hpp")
list(APPEND SRC_LIST "../srv/floatnumber.cpp")
list(APPEND SRC_LIST "../srv/floatnumber.hpp")
list(APPEND SRC_LIST "../srv/exchangecore.cpp")
list(APPEND SRC_LIST "../srv/exchangecore.hpp")
list(APPEND SRC_LIST "../srv/completedorder.cpp")
list(APPEND SRC_LIST "../srv/completedorder.hpp")
list(APPEND SRC_LIST "../srv/completedorderarray.cpp")
list(APPEND SRC_LIST "../srv/completedorderarray.hpp")

list(APPEND SRC_LIST "../srv/idgenerator.cpp")
list(APPEND SRC_LIST "../srv/idgenerator.hpp")



add_executable(${PROJECT_NAME} ${SRC_LIST})

