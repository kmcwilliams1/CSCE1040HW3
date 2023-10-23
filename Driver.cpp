#include <algorithm>
#include <sstream>
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

void Driver::setAvailable() {
    available = !available;
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

void Driver::getSchedule() {

    sort(rides.begin(), rides.end(), [](const Ride &a, const Ride &) {
        return a.getPickupTime() < a.getPickupTime();
    });

    for (Ride ride: rides) {
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
    for (Ride ride: this->rides) {
        ride.rating++;
        currentRating = ride.rating++;
    }
    return currentRating;
}

bool Driver::toggleAvailability() {
    return !this->available;
}

void Driver::addNewRide(Ride *ride) {
}

void Driver::addCompletedRide() {
    completedRides++;
}

void Driver::addCancelledRide() {
    cancelledRides++;
}


int Driver::getCancelledRides() const {
    return cancelledRides;
}

void Driver::printDriver() const {
    cout << this->firstName << " " << this->lastName << endl;
    cout << this->driverRating << " stars." << endl;
    this->handicappedCapable ? cout << "Handicapable" << endl : cout << "Not handicap able" << endl;
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
    cout << " With " << this->vehicleCapacity << " seats." << endl;
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

void Driver::setDriverProperties(const string &data) {
    istringstream dataStream(data);
   string temp;

    getline(dataStream, temp, ',');
    {
        cout << "current role " << temp << endl;
    };
    getline(dataStream, temp, ',');
    {
        this->firstName = temp;
    };
    getline(dataStream, temp, ',');
    {
        this->lastName = temp;
    };
    getline(dataStream, temp, ',');
    {
        this->id = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        this->available = true;
    };
    getline(dataStream, temp, ',');
    {
        this->vehicleCapacity = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        this->vehicleType = static_cast<Driver::VehicleType>(stoi(temp));
    };
    getline(dataStream, temp, ',');
    {
        temp = 1 ? this->petsAllowed = true : this->petsAllowed = false;
    };
    getline(dataStream, temp, ',');
    {
        this->driverRating = stof(temp);
    };
    getline(dataStream, temp, ',');
    {
        this->completedRides = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        this->cancelledRides = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        this->password = temp;
    };
//    getline(dataStream, temp, '\n');
//    {
//        cout << "trip id " << temp << endl;
//        for(int i = 0; i < temp.length(); i++) {}
//    };


}

void Driver::setCancelledRides(int cancelledRides) {
        this->cancelledRides = cancelledRides;
}

string Driver::getPassword() const {
    return password;
}

void Driver::setPassword(string password) {
    this->password = password;
}

void Driver::setCompletedRides(int completedRides) {
        this->completedRides = completedRides;
}









