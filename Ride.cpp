#include "Ride.h"
#include <iostream>


Ride::Ride(int sizeOfParty, bool includesPets, string pickupLocation, string dropoffLocation, time_t pickupTime, string note, bool handicapable)
        : sizeOfParty(sizeOfParty), includesPets(includesPets), pickupLocation(pickupLocation),
          dropOffLocation(dropoffLocation), pickupTime(pickupTime), note(note), handicapable(handicapable) {

}

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

void Ride::setPickupLocation(const string &location) {
    pickupLocation = location;
}

string Ride::getDropOffLocation() const {
    return dropOffLocation;
}

void Ride::setDropOffLocation(const string &location) {
    dropOffLocation = location;
}

string Ride::getPickupTime() const {
    struct tm* timeInfo;
    timeInfo = localtime(&pickupTime);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeInfo);
    return string(buffer);
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

void Ride::getPickupLocationAndTime() const {

}

void Ride::completeRide() {

}

const string &Ride::getNote() const {
    return note;
}

void Ride::setNote(const string &note) {
    this->note = note;
}

bool Ride::getHandicapped() const {
    return handicapped;
}

void Ride::setHandicapped() {
    handicapped = !handicapped;

}

