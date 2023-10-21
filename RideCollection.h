#ifndef INC_1040HOMEWORK_RIDECOLLECTION_H
#define INC_1040HOMEWORK_RIDECOLLECTION_H

#include <vector>
#include "Ride.h"

using namespace std;

class RideCollection {
public:
    enum class RideStatus {
        Active,
        Completed,
        Cancelled
    };

    RideCollection();
    ~RideCollection();

    void getRides() const;
    Ride* addRide(int sizeOfParty, bool includesPets, string pickupLocation, string dropOffLocation, time_t pickupTime, string note, bool handicapable);
    int showActiveRides(RideStatus status);


    std::vector<Ride> rides;
};

#endif // INC_1040HOMEWORK_RIDECOLLECTION_H
