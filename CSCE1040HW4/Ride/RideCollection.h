

#ifndef CSCE1040HW4_RIDECOLLECTION_H
#define CSCE1040HW4_RIDECOLLECTION_H


#include "../Passenger/Passenger.h"
#include "../Driver/Driver.h"

class RideCollection {

public:
    void addRide(Passenger passenger);
    vector<Ride> rides;

    void assignSchedule(const Driver& driver);
};


#endif //CSCE1040HW4_RIDECOLLECTION_H
