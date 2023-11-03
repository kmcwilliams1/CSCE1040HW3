
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

Driver::VehicleType Driver::getVehicleType() const {
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

bool Driver::isPetsAllowed() const  {
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
    for (auto it = rides.begin(); it != rides.end();) {
        if (it->rideStatus == Ride::RideStatus::Completed || it->rideStatus == Ride::RideStatus::Cancelled) {
            this->rides.erase(it);
        }
    }
}

void Driver::readDriverProperties(const string &basicString) {

}

void Driver::writeDriverProperties(ostream &dataFile) {
    dataFile << "Driver,";
    dataFile << firstName << ",";
    dataFile << lastName << ",";
    dataFile << id << ",";
    dataFile << available << ","; // isAvailable
    dataFile << vehicleCapacity << ",";
    dataFile << handicappedCapable << ",";
    dataFile << static_cast<int>(vehicleType) << ",";
    dataFile << petsAllowed << ",";
    dataFile << driverRating << ","; // driverRating
    dataFile << password << "\n";
    for (const Ride& ride : rides) {
        dataFile << ride.getId() << ",";
    }
}

void Driver::getCompletedRides() const {
    for (const Ride& ride : rides) {
        if(ride.rideStatus == Ride::RideStatus::Completed) {
            cout << ride.pickupLocation << " -> " << ride.dropOffLocation << endl;
            cout << ride.pickupTime << endl;
        }
    }
}

void Driver::getCancelledRides() const {
    for (const Ride& ride : rides) {
        if(ride.rideStatus == Ride::RideStatus::Cancelled) {
            cout << ride.pickupLocation << " -> " << ride.dropOffLocation << endl;
            cout << ride.pickupTime << endl;
        }
    }
}

void Driver::editInfo() {
    char option;
    string str;
    int i;
    cout << "*************************************" << endl;
    cout << "           Driver Edit Menu          " << endl;
    cout << "*************************************" << endl;
    cout << "What would you like to edit?" << endl;
    cout << "A: Vehicle Capacity : " << this->getVehicleCapacity() << endl;
    cout << "B: Handicapped Capable: " << this->isHandicappedCapable() << endl;
    cout << "C: Pets Allowed : " << this->isPetsAllowed() << endl;
    cout << "D: First Name : " << this->getFirstName() << endl;
    cout << "E: Last Name : " << this->getLastName() << endl;
    cout << "F: Vehicle Type : " << static_cast<int>(this->getVehicleType()) << endl;

    cin >> option;

    switch (option) {
        case 'A':
            cout << "New capacity: " << endl;
            cin >> i;
            this->setVehicleCapacity(i);
            break;

        case 'B':
            this->setHandicappedCapable();
            cout << "New handicapable: " << endl;
            this->isHandicappedCapable();
            break;

        case 'C':
            cout << "New pet policy: " << endl;
            this->setPetsAllowed();
            break;

        case 'D':

            cout << "New first name: " << endl;
            cin >> str;
            this->setFirstName(str);
            break;

        case 'E':

            cout << "New Last Name: " << endl;
            cin >> str;
            this->setLastName(str);
            break;

        case 'F':

            cout << "New Vehicle Type (1-5): " << endl;
            cin >> i;
            this->setVehicleType(static_cast<Driver::VehicleType>(i));
            break;

        default:
            cout << "Invalid option, try again." << endl;
            cin >> option;

    }
}

