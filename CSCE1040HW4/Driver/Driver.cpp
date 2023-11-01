
#include "Driver.h"



Driver::~Driver() = default;

Driver::Driver() = default;




int Driver::getVehicleCapacity() const {
    return vehicleCapacity;
}

void Driver::setVehicleCapacity(int capacity) {
    vehicleCapacity = capacity;
}

bool Driver::isHandicappedCapable() const {
    return handicappedCapable;
}

void Driver::setHandicappedCapable() {
    handicappedCapable = !handicappedCapable;
}

Driver::VehicleType Driver::getVehicleType() {
    return vehicleType;
}

void Driver::setVehicleType(VehicleType type) {
    vehicleType = type;
}

float Driver::getDriverRating() const {
    return driverRating;
}

void Driver::setDriverRating(float rating) {
    driverRating = rating;
}

bool Driver::isPetsAllowed()  {
    return petsAllowed;
}

void Driver::setPetsAllowed() {
    petsAllowed = !petsAllowed;
}

bool Driver::isAvailable() const {
    return available;
}

void Driver::setAvailable() {
    available = !available;
}

int Driver::getId() const {
    return id;
}

void Driver::setId(int newId) {
    id = newId;
}

const string &Driver::getFirstName() const {
    return firstName;
}

void Driver::setFirstName(const string &first) {
    firstName = first;
}

const string &Driver::getLastName() const {
    return lastName;
}

void Driver::setLastName(const string &last) {
    lastName = last;
}

int Driver::getCompletedRides() const {
    return completedRides;
}

void Driver::setCompletedRides() {
    int i;
    for(Ride &ride : rides) {
        if(ride.getStatus() == Ride::RideStatus::Active){
            cout << ride.pickupLocation << " -> " << ride.dropOffLocation << endl;
            cout << ride.id << endl;
        }
    }
    cout << "Which ride ID do you want to complete?" << endl;
    cin >> i;

    for(Ride &ride : rides) {
        if(ride.id == i) {
            ride.setStatus(Ride::RideStatus::Completed);
        }
    }

}

int Driver::getCancelledRides() const {
    return cancelledRides;
}

void Driver::setCancelledRides() {
    int i;
    for(Ride &ride : rides) {
        if(ride.getStatus() == Ride::RideStatus::Active){
            cout << ride.pickupLocation << " -> " << ride.dropOffLocation << endl;
            cout << ride.id << endl;
        }
    }
    cout << "Which ride ID do you want to cancel?" << endl;
    cin >> i;

    for(Ride &ride : rides) {
        if(ride.id == i) {
            ride.setStatus(Ride::RideStatus::Cancelled);
        }
    }
}

const vector<Ride> &Driver::getRides() const {
    return rides;
}

void Driver::addNewRide(Ride *ride) {

}

const string &Driver::getPassword() const {
    return password;
}

void Driver::setPassword(const string &pass) {
    password = pass;
}

void Driver::getSchedule() {

}

void Driver::getInfo() {

}

void Driver::deleteCancelledAndCompletedRides() {

}

void Driver::readDriverProperties(const string &basicString) {

}

void Driver::writeDriverProperties(ostream &dataFile) {

}

