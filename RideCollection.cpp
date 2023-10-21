#include "RideCollection.h"
#include <iostream>

RideCollection::RideCollection() {
    // Initialize your RideCollection if needed
}

RideCollection::~RideCollection() {
    // Cleanup any resources if needed
}

void RideCollection::getRide() const {
    // Implement this function to retrieve a ride if needed
}



int RideCollection::showActiveRides(RideCollection::RideStatus status) {
    return 0;
}

Ride *RideCollection::addRide(int sizeOfParty, bool includesPets, string pickupLocation, string dropOffLocation,
                              time_t pickupTime) {
    Ride *ride = new Ride(sizeOfParty, includesPets, pickupLocation, dropOffLocation, pickupTime);
    rides.push_back(*ride);
    return ride;
}

