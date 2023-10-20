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

    void getRide() const;
    void addRide(int sizeOfParty, bool includesPets, string pickupLocation, string dropOffLocation, time_t pickupTime);
    void updateRide(string pickupLocation, string dropOffLocation, time_t pickupTime, time_t dropOffTime);
    int showActiveRides(RideStatus status);
    void completeRide(int id, string dropOffLocation, time_t dropOffTime, RideStatus status);
    void getPickupLocationAndTime() const;
    void printCurrentAssignments(time_t pickupTime) const;

private:
    vector<Ride> rides;
};

#endif // INC_1040HOMEWORK_RIDECOLLECTION_H
