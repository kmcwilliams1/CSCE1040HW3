#include "Driver.h"
#include "Ride.h"

Driver::Driver(int capacity, bool handicapped, VehicleType vType, bool pets, string fName, string lName)
        : vehicleCapacity(capacity), handicappedCapable(handicapped), vehicleType(vType),
          driverRating(0.0), petsAllowed(pets), available(true), id(0), firstName(fName),
          lastName(lName), completedRides(0) {
}

Driver::Driver() {

}

Driver::~Driver() {
    // Destructor implementation
}

int Driver::getId() const {
    return id;
}

void Driver::setId(int newId) {
    id = newId;
}

void Driver::setDriverRating(float rating) {
    driverRating = rating;
}

bool Driver::isAvailable() const {
    return available;
}

void Driver::setAvailable(bool status) {
    available = status;
}

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

Driver::VehicleType Driver::getVehicleType() const {
    return vehicleType;
}

void Driver::setVehicleType(VehicleType type) {
    vehicleType = type;
}

bool Driver::isPetsAllowed() const {
    return petsAllowed;
}

void Driver::setPetsAllowed() {
    petsAllowed = !petsAllowed;
}

const string& Driver::getNotes() const {
    return notes;
}

void Driver::setNotes(const string& driverNotes) {
    notes = driverNotes;
}

const string& Driver::getFirstName() const {
    return firstName;
}

void Driver::setFirstName(const string& first) {
    firstName = first;
}

const string& Driver::getLastName() const {
    return lastName;
}

void Driver::setLastName(const string& last) {
    lastName = last;
}

int Driver::getCompletedRides() const {
    return completedRides;
}

void Driver::getSchedule() {
    for (Ride* ride : rides) {
        ride->getPickupTime();
    }
}


float Driver::updateDriverRating(float driverRating) {
    // Implementation of updateDriverRating
    return 0.0; // Replace with actual logic
}

bool Driver::toggleAvailability() {
    // Implementation of toggleAvailability
    return false; // Replace with actual logic
}

void Driver::addNewRide(Ride* ride) {
    // Implementation of addNewRide
}

void Driver::addCompletedRide(Ride* ride) {
    // Implementation of addCompletedRide
}

void Driver::addCancelledRide(Ride* ride) {
    // Implementation of addCancelledRide
}


int Driver::getCancelledRides() const {
    return canceledRides;
}

void Driver::printDriver() const {
    cout << this->firstName << " " << this->lastName << endl;
    cout << this->driverRating << " stars." << endl;
    this->handicappedCapable ? cout << "Handicap able" << endl : cout << "Not handicap able" << endl;
    this->petsAllowed ? cout << "Pets allowed" << endl : cout << "No pets allowed" << endl;

    string vehicleTypeStr;
    switch (this->vehicleType) {
        case VehicleType::Compact2Dr:
            vehicleTypeStr = "Compact 2-Door";
            break;
        case VehicleType::Sedan4Dr:
            vehicleTypeStr = "Sedan 4-Door";
            break;
        case VehicleType::SUV:
            vehicleTypeStr = "SUV";
            break;
        case VehicleType::Van:
            vehicleTypeStr = "Van";
            break;
        case VehicleType::Other:
            vehicleTypeStr = "Other";
            break;
    }

    cout << "Vehicle Type: " << vehicleTypeStr;
    cout << " With "<<this->vehicleCapacity << " seats." << endl;

}

void Driver::deleteCancelledAndCompletedRides() const {

}





