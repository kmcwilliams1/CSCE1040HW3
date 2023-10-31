

#include "Ride.h"


Ride::Ride() = default;

Ride::~Ride() = default;



int Ride::getSizeOfParty() const {
    return sizeOfParty;
}

void Ride::setSizeOfParty(int partySize) {

}

bool Ride::getIncludesPets() const {
    return includesPets;
}

void Ride::setIncludesPets() {

}

Ride::RideStatus Ride::getStatus() const {
    return rideStatus;
}

void Ride::setStatus(Ride::RideStatus status) {

}

float Ride::getRating() const {
    return rating;
}

void Ride::setRating(float rideRating) {

}

int Ride::getId() const {
    return id;
}

void Ride::setId(int rideId) {

}

string Ride::getPickupLocation() const {
    return pickupLocation;
}

void Ride::setPickupLocation(const string &location) {

}

string Ride::getDropOffLocation() const {
    return dropOffLocation;
}

void Ride::setDropOffLocation(const string &location) {

}

string Ride::getPickupTime() const {
    struct tm *timeInfo;
    timeInfo = localtime(&pickupTime);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeInfo);
    return buffer;
};

void Ride::setPickupTime(time_t time) {

}

time_t Ride::getDropOffTime() const {
    return dropOffTime;
}

void Ride::setDropOffTime(time_t time) {

}

const string &Ride::getNote() const {
    return note;
}

void Ride::setNote(const string &note) {

}

bool Ride::getHandicapped() const {
    return handicapable;
}

void Ride::setHandicapped() {
    handicapable = !handicapable;
}

void Ride::readRideProperties(string basicString) {

}


void Ride::writeRideProperties(ostream &dataFile) {

}



