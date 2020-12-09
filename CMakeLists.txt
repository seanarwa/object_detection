cmake_minimum_required(VERSION 3.17)
project(object_detection)

set(CMAKE_CXX_STANDARD 14)

set(VENDORS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/vendors)

#add_subdirectory(${VENDOR_PATH}/event_bus-3.0.0/lib)

set(OpenCV_DIR ${VENDORS_PATH}/opencv-4.5.0/x64/vc16/staticlib)
set(OpenCV_STATIC ON)
find_package(OpenCV REQUIRED)


set(app_SRC
    src/main.cpp
)
#set(app_HEADERS
#
#)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(app ${app_SRC})

set_property(TARGET app PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

target_link_libraries(app ${OpenCV_LIBS})
#target_link_libraries(app PRIVATE Dexode::EventBus)
