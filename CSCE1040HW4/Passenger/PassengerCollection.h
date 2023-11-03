

#ifndef CSCE1040HW4_PASSENGERCOLLECTION_H
#define CSCE1040HW4_PASSENGERCOLLECTION_H


#include "Passenger.h"

class PassengerCollection {

public:

    vector <Passenger> passengers;

    void deletePassenger(const Passenger& passenger);

    Passenger addPassenger(Passenger passenger);
};


#endif //CSCE1040HW4_PASSENGERCOLLECTION_H
