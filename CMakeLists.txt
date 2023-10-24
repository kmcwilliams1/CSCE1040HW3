cmake_minimum_required(VERSION 3.26)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled main.cpp Driver.cpp DriverCollection.cpp  PassengerCollection.cpp Passenger.cpp  RideCollection.cpp Ride.cpp)
