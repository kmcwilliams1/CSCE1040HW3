
#include <sstream>
#include "Driver.h"
#include "BasicDriver/BasicDriver.h"
#include "EconomyDriver/EconomyDriver.h"
#include "GroupDriver/GroupDriver.h"
#include "LuxuryDriver/LuxuryDriver.h"


Driver::~Driver() = default;

Driver::Driver() = default;


bool Driver::isHandicappedCapable() const {
    return handicappedCapable;
}

void Driver::setHandicappedCapable(bool isHandicappedCapable) {
    handicappedCapable = isHandicappedCapable;
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

bool Driver::isPetsAllowed() const {
    return petsAllowed;
}

void Driver::setPetsAllowed(bool isPetsAllowed) {
    petsAllowed = isPetsAllowed;
}

bool Driver::isAvailable() const {
    return available;
}

void Driver::setAvailable(bool isAvailable) {
    available = isAvailable;
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

    for (Ride &ride: rides) {
        cout << "-------------------------------------------" << endl;
        if (ride.getStatus() == Ride::RideStatus::Active) {
            cout << "Destination: " << ride.pickupLocation << " -> " << ride.dropOffLocation << endl;
            cout << "ID: " << ride.id << endl;
            cout << "Time: " << ride.getPickupTime() << endl;
        }
    }

    cout << endl << "Which ride ID do you want to complete?" << endl;
    cin >> i;

    for (Ride &ride: rides) {
        if (ride.id == i) {
            ride.setStatus(Ride::RideStatus::Completed);
        }
    }

}


void Driver::setCancelledRides() {
    int i;

    for (Ride &ride: rides) {
        cout << "-------------------------------------------" << endl;
        if (ride.getStatus() == Ride::RideStatus::Active) {
            cout << "Destination: " << ride.pickupLocation << " -> " << ride.dropOffLocation << endl;
            cout << "ID: " << ride.id << endl;
            cout << "Time: " << ride.getPickupTime() << endl;
        }
    }
    cout << "Which ride ID do you want to cancel?" << endl;
    cin >> i;

    for (Ride &ride: rides) {
        if (ride.id == i) {
            ride.setStatus(Ride::RideStatus::Cancelled);
        }
    }
}

void Driver::getRides() const {
    if (!rides.empty()) {
        cout << "Previous Rides:" << endl;
        cout << "---------------------------------------" << endl;
        for (const Ride &ride: rides) {
            if (ride.getStatus() != Ride::RideStatus::Active) {
                cout << "Pickup Location: " << ride.getPickupLocation() << endl;
                cout << "Drop-Off Location: " << ride.getDropOffLocation() << endl;
                cout << "Pickup Time: " << ride.getPickupTime() << endl;
                cout << "---------------------------------------" << endl;
            }
        }
    } else {
        cout << "No rides available for this passenger." << endl;
    }
}

const string &Driver::getPassword() const {
    return password;
}

void Driver::setPassword(const string &pass) {
    password = pass;
}

void Driver::getSchedule() {
    if (!rides.empty()) {
        cout << "Rides:" << endl;
        cout << "---------------------------------------" << endl;
        for (const Ride &ride: rides) {
            if (ride.getStatus() == Ride::RideStatus::Active) {
                cout << "Pickup Location: " << ride.getPickupLocation() << endl;
                cout << "Drop-Off Location: " << ride.getDropOffLocation() << endl;
                cout << "Pickup Time: " << ride.getPickupTime() << endl;
                cout << "---------------------------------------" << endl;
            }
        }
    } else {
        cout << "No rides available for this passenger." << endl;
    }

}


void Driver::deleteCancelledAndCompletedRides() {
    for (auto it = rides.begin(); it != rides.end();) {
        if (it->rideStatus == Ride::RideStatus::Completed || it->rideStatus == Ride::RideStatus::Cancelled) {
            this->rides.erase(it);
        }else {
            ++it;
        }
    }
}


void Driver::writeDriverProperties(ostream &dataFile)  {

}

void Driver::getCompletedRides() const {
    for (const Ride &ride: rides) {
        if (ride.rideStatus == Ride::RideStatus::Completed) {
            cout << ride.pickupLocation << " -> " << ride.dropOffLocation << endl;
            cout << ride.pickupTime << endl;
        }
    }
}

void Driver::getCancelledRides() const {
    for (const Ride &ride: rides) {
        if (ride.rideStatus == Ride::RideStatus::Cancelled) {
            cout << ride.pickupLocation << " -> " << ride.dropOffLocation << endl;
            cout << ride.pickupTime << endl;
        }
    }
}

void Driver::getInfo() const {
    cout << "*************************************" << endl;
    cout << this->firstName << " " << this->lastName << endl;

}

void Driver::editInfo() {}

void Driver::copyPropertiesFrom(const Driver *otherDriver) {

    if (otherDriver) {
        this->setHandicappedCapable(otherDriver->isHandicappedCapable());
        this->setPetsAllowed(otherDriver->isPetsAllowed());
        this->setDriverRating(otherDriver->getDriverRating());
        this->setId(otherDriver->getId());
        this->setFirstName(otherDriver->getFirstName());
        this->setLastName(otherDriver->getLastName());
        this->setPassword(otherDriver->getPassword());

    };
    this->rides.clear();
    for (auto &&ride: otherDriver->rides) {
        this->rides.push_back(ride);
    }


}

