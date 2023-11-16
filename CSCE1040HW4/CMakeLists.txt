cmake_minimum_required(VERSION 3.26)
project(CSCE1040HW4)

set(CMAKE_CXX_STANDARD 11)

add_executable(CSCE1040HW4
        main.cpp
        Driver/Driver.cpp
        Driver/Driver.h
        Passenger/Passenger.cpp
        Passenger/Passenger.h
        Ride/Ride.cpp
        Ride/Ride.h
        Ride/RideCollection.cpp
        Ride/RideCollection.h
        Driver/DriverCollection.cpp
        Driver/DriverCollection.h
        Passenger/PassengerCollection.cpp
        Passenger/PassengerCollection.h
        Passenger/PassengerMenu.h
        Driver/BasicDriver/BasicDriver.cpp
        Driver/BasicDriver/BasicDriver.h
        Driver/EconomyDriver/EconomyDriver.cpp
        Driver/EconomyDriver/EconomyDriver.h
        Driver/GroupDriver/GroupDriver.cpp
        Driver/GroupDriver/GroupDriver.h
        Driver/LuxuryDriver/LuxuryDriver.cpp
        Driver/LuxuryDriver/LuxuryDriver.h
#        testMain.cpp
)
