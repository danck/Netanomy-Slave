set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_definitions(-DNTY_PLUGINS_DIR="/usr/lib/nty-slave")
add_executable(netanomy-slave main.cpp plugin.cpp plugin.hpp null_plugin.cpp null_plugin.hpp plugins.cpp plugins.hpp statehandler.hpp statehandler.cpp context.cpp context.hpp request.cpp request.hpp zhelpers.hpp
${CMAKE_CURRENT_SOURCE_DIR}/states/execreplystate.cpp
${CMAKE_CURRENT_SOURCE_DIR}/states/execreplystate.hpp
${CMAKE_CURRENT_SOURCE_DIR}/states/state.cpp
${CMAKE_CURRENT_SOURCE_DIR}/states/state.hpp
${CMAKE_CURRENT_SOURCE_DIR}/states/termstate.hpp
${CMAKE_CURRENT_SOURCE_DIR}/states/waitordersstate.cpp
${CMAKE_CURRENT_SOURCE_DIR}/states/waitordersstate.hpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

SET(ZMQ_INCLUDE ${ZMQ_INCLUDE} CACHE STRING "Location of ZeroMQ headers.")
SET(ZMQ_LIBRARY ${ZMQ_LIBRARY} CACHE STRING "ZeroMQ libraries to link in.")

include_directories(${ZMQ_INCLUDE})
target_link_libraries(netanomy-slave ${ZMQ_LIBRARY})