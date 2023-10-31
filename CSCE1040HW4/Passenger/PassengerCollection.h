

#ifndef CSCE1040HW4_PASSENGERCOLLECTION_H
#define CSCE1040HW4_PASSENGERCOLLECTION_H


#include "Passenger.h"

class PassengerCollection {

public:
    void addPassenger();

    vector <Passenger> passengers;

    void deletePassenger(const Passenger& passenger);
};


#endif //CSCE1040HW4_PASSENGERCOLLECTION_H
