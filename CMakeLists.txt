cmake_minimum_required(VERSION 3.17)
project(object_detection)

set(CMAKE_CXX_STANDARD 14)

set(VENDOR_PATH ${CMAKE_CURRENT_SOURCE_DIR}/vendors)
set(OpenCV_DIR ${VENDOR_PATH}/opencv-4.5.0/build/install/x64/vc16/lib)
#add_subdirectory(${VENDOR_PATH}/event_bus-3.0.0/lib)

find_package(OpenCV REQUIRED)


set(app_SRC
    src/main.cpp
)
#set(app_HEADERS
#
#)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(app ${app_SRC})

target_link_libraries(app ${OpenCV_LIBS})
#target_link_libraries(app PRIVATE Dexode::EventBus)
