#include <algorithm>
#include "Driver.h"
#include "Ride.h"

Driver::Driver(int capacity, bool handicapped, VehicleType vType, bool pets, string fName, string lName)
        : vehicleCapacity(capacity), handicappedCapable(handicapped), vehicleType(vType),
          driverRating(0.0), petsAllowed(pets), available(true), id(0), firstName(fName),
          lastName(lName), completedRides(0) {
}

Driver::Driver() {}

Driver::~Driver() {}

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

    sort(rides.begin(), rides.end(), [](const Ride& a, const Ride&) {
        return a.getPickupTime() < a.getPickupTime();
    });

    for (Ride ride : rides) {
        cout << "Party size: " << ride.getSizeOfParty() << endl;
        cout << "Pick up at: " << ride.getPickupLocation() << endl;
        cout << "By: " << ride.getPickupTime() << endl;
        cout << "Drop off at: " << ride.getDropOffLocation() << endl;
        cout << "Notes: " << ride.getNote() << endl;
        string statusString;
        switch (ride.getStatus()) {
            case Ride::RideStatus::Active:
                statusString = "Active";
                break;
            case Ride::RideStatus::Completed:
                statusString = "Completed";
                break;
            case Ride::RideStatus::Cancelled:
                statusString = "Cancelled";
                break;
            default:
                statusString = "Unknown";
                break;
        }

        cout << "Driver.cpp::getSchedule Status: " << statusString << endl;
       cout << "----------------------------------------" << endl;

    }
}


float Driver::updateDriverRating() {
    float currentRating;
    for(Ride ride : this->rides) {
        ride.rating++;
        currentRating = ride.rating ++;
    }
    return currentRating;
}

bool Driver::toggleAvailability() {
    return !this->available;
}

void Driver::addNewRide(Ride* ride) {
}

void Driver::addCompletedRide() {
    completedRides++;
}

void Driver::addCancelledRide() {
    canceledRides++;
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
    float currentRating;
    for(Ride ride : this->rides) {
        ride.rating++;
        currentRating = ride.rating ++;
    }
    cout << "Rating: " << currentRating << endl;
}



void Driver::deleteCancelledAndCompletedRides() {
    auto it = rides.begin();

    while (it != rides.end()) {
        if (it->getStatus() == Ride::RideStatus::Cancelled || it->getStatus() == Ride::RideStatus::Completed) {
            it = rides.erase(it);
        } else {
            ++it;
        }
    }
}

// Driver.cpp

#include "Driver.h"

void Driver::setDriverProperties(std::string data) {
    size_t pos = 0;
    while ((pos = data.find(", ")) != std::string::npos) {
        std::string token = data.substr(0, pos);
        data.erase(0, pos + 2);

        // Extract the property name from the token
        size_t propNameEnd = token.find(": ");
        if (propNameEnd == std::string::npos) {
            continue;
        }
        std::string propName = token.substr(0, propNameEnd);

        // Now, use a switch statement to assign the token to the appropriate member variable
        if (propName == "id") {
            id = std::stoi(token.substr(propNameEnd + 2));
        } else if (propName == "vehicleCapacity") {
            vehicleCapacity = std::stoi(token.substr(propNameEnd + 2));
        } else if (propName == "isHandicapable") {
            handicappedCapable = (std::stoi(token.substr(propNameEnd + 2)) == 1);
        } else if (propName == "vehicleType") {
            vehicleType = static_cast<VehicleType>(std::stoi(token.substr(propNameEnd + 2)));
        } else if (propName == "petsAllowed") {
            petsAllowed = (std::stoi(token.substr(propNameEnd + 2)) == 1);
        } else if (propName == "driverRating") {
            driverRating = std::stof(token.substr(propNameEnd + 2));
        } else if (propName == "Complete Rides") {
            completedRides = std::stoi(token.substr(propNameEnd + 2));
        } else if (propName == "Cancelled Rides") {
            canceledRides = std::stoi(token.substr(propNameEnd + 2));
        } else if (propName == "firstName") {
            firstName = token.substr(propNameEnd + 2);
        } else if (propName == "lastName") {
            lastName = token.substr(propNameEnd + 2);
        }
    }
}










