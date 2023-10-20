#include "Ride.h"
#include <iostream>

Ride::Ride() {
    // Initialize your Ride instance if needed
}

Ride::~Ride() {
    // Cleanup any resources if needed
}

int Ride::getSizeOfParty() const {
    return sizeOfParty;
}

void Ride::setSizeOfParty(int partySize) {
    sizeOfParty = partySize;
}

bool Ride::getIncludesPets() const {
    return includesPets;
}

void Ride::setIncludesPets(bool pets) {
    includesPets = pets;
}

Ride::RideStatus Ride::getStatus() const {
    return status;
}

void Ride::setStatus(RideStatus rideStatus) {
    status = rideStatus;
}

float Ride::getRating() const {
    return rating;
}

void Ride::setRating(float rideRating) {
    rating = rideRating;
}

int Ride::getId() const {
    return id;
}

void Ride::setId(int rideId) {
    id = rideId;
}

string Ride::getPickupLocation() const {
    return pickupLocation;
}

void Ride::setPickupLocation(const string& location) {
    pickupLocation = location;
}

string Ride::getDropOffLocation() const {
    return dropOffLocation;
}

void Ride::setDropOffLocation(const string& location) {
    dropOffLocation = location;
}

time_t Ride::getPickupTime() const {
    return pickupTime;
}

void Ride::setPickupTime(time_t time) {
    pickupTime = time;
}

time_t Ride::getDropOffTime() const {
    return dropOffTime;
}

void Ride::setDropOffTime(time_t time) {
    dropOffTime = time;
}

void Ride::printCurrentAssignment(time_t pickupTime) const {
    // Implement this function to print information about the current ride assignment
    // You can access the ride's properties using the getter methods
}
