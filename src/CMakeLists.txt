include_directories(cstates)
add_executable(netanomy main.cpp)

SET(ZMQ_INCLUDE ${ZMQ_INCLUDE} CACHE STRING "Location of ZeroMQ headers.")
SET(ZMQ_LIBRARY ${ZMQ_LIBRARY} CACHE STRING "ZeroMQ libraries to link in.")

include_directories(${ZMQ_INCLUDE})
target_link_libraries(netanomy ${ZMQ_LIBRARY})
