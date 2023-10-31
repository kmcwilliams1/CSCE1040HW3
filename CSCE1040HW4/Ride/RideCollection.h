

#ifndef CSCE1040HW4_RIDECOLLECTION_H
#define CSCE1040HW4_RIDECOLLECTION_H


#include "../Passenger/Passenger.h"

class RideCollection {

public:
    void addRide(Passenger passenger);
    vector<Ride> rides;
};


#endif //CSCE1040HW4_RIDECOLLECTION_H
