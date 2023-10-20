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

void RideCollection::addRide(int sizeOfParty, bool includesPets, string pickupLocation, string dropOffLocation, time_t pickupTime) {
    Ride newRide;
    newRide.setSizeOfParty(sizeOfParty);
    newRide.setIncludesPets(includesPets);
    newRide.setPickupLocation(pickupLocation);
    newRide.setDropOffLocation(dropOffLocation);
    newRide.setPickupTime(pickupTime);

    // Add the new ride to the collection
    rides.push_back(newRide);
}

void RideCollection::updateRide(string pickupLocation, string dropOffLocation, time_t pickupTime, time_t dropOffTime) {
    // Implement this function to update an existing ride if needed
}

int RideCollection::showActiveRides(RideStatus status) {
    // Implement this function to display active rides and return the count
}

void RideCollection::completeRide(int id, string dropOffLocation, time_t dropOffTime, RideStatus status) {
    // Implement this function to mark a ride as completed and update its details
}

void RideCollection::getPickupLocationAndTime() const {
    // Implement this function to retrieve pickup location and time if needed
}

void RideCollection::printCurrentAssignments(time_t pickupTime) const {
    // Implement this function to print current ride assignments
}
