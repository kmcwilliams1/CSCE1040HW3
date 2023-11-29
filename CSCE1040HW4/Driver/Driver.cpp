
#include <sstream>
#include <limits>
#include "Driver.h"



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

    for (Ride *ride: rides) {
        cout << "-------------------------------------------" << endl;
        if (ride->getStatus() == Ride::RideStatus::Active) {
            cout << "Destination: " << ride->pickupLocation << " -> " << ride->dropOffLocation << endl;
            cout << "ID: " << ride->id << endl;
            cout << "Time: " << ride->getPickupTime() << endl;
            cout << "-------------------------------------------" << endl;

        }
    }

    cout << endl << "Which ride ID do you want to complete?" << endl;
    cin >> i;

    for (Ride *ride: rides) {
        if (ride->id == i) {
            ride->rideStatus = (Ride::RideStatus::Completed);


            cout<< "After update: " << static_cast<int>(ride->rideStatus) << endl;
        }
    }



}


void Driver::setCancelledRides() {
    int i;
    cout << "-------------------------------------------" << endl;

    for (Ride *ride: rides) {
        if (ride->getStatus() == Ride::RideStatus::Active) {
            cout << "Destination: " << ride->pickupLocation << " -> " << ride->dropOffLocation << endl;
            cout << "ID: " << ride->id << endl;
            cout << "Time: " << ride->getPickupTime() << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << "Which ride ID do you want to cancel?" << endl;
    cin >> i;

    while (cin.fail() || i < 0) {
        cout << "Invalid input. Please enter a valid ride ID : " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> i;
    }


    for (Ride *ride: rides) {
        if (ride->id == i) {
            ride->rideStatus = (Ride::RideStatus::Cancelled);
        }
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
        for (const Ride *ride: rides) {
            if (ride->getStatus() == Ride::RideStatus::Active) {
                cout << "Pickup Location: " << ride->getPickupLocation() << endl;
                cout << "Drop-Off Location: " << ride->getDropOffLocation() << endl;
                cout << "Pickup Time: " << ride->getPickupTime() << endl;
                cout << "Passenger ID: " << ride->getAssignedPassengerId() << endl;
                cout << "---------------------------------------" << endl;
            }
        }
    } else {
        cout << "No rides available for this passenger." << endl;
    }

}


void Driver::deleteCancelledAndCompletedRides() {
    for (auto it = rides.begin(); it != rides.end();) {
        if ((*it)->rideStatus == Ride::RideStatus::Completed || (*it)->rideStatus == Ride::RideStatus::Cancelled) {
            rides.erase(it);
        }else {
            ++it;
        }
    }
}


void Driver::writeDriverProperties(ostream &dataFile)  {

}

void Driver::getCompletedRides() const {
    if (!rides.empty()) {
        cout << "Previous Rides:" << endl;
        cout << "---------------------------------------" << endl;
        for (const Ride *ride: rides) {
            if (ride->getStatus() != Ride::RideStatus::Completed) {
                cout << "Pickup Location: " << ride->getPickupLocation() << endl;
                cout << "Drop-Off Location: " << ride->getDropOffLocation() << endl;
                cout << "Pickup Time: " << ride->getPickupTime() << endl;
                cout << "---------------------------------------" << endl;
            }
        }
    } else {
        cout << "No rides available for this passenger." << endl;
    }
}

void Driver::getCancelledRides() const {
    if (!rides.empty()) {
        cout << "Previous Rides:" << endl;
        cout << "---------------------------------------" << endl;
        for (const Ride *ride: rides) {
            if (ride->getStatus() != Ride::RideStatus::Cancelled) {
                cout << "Pickup Location: " << ride->getPickupLocation() << endl;
                cout << "Drop-Off Location: " << ride->getDropOffLocation() << endl;
                cout << "Pickup Time: " << ride->getPickupTime() << endl;
                cout << "---------------------------------------" << endl;
            }
        }
    } else {
        cout << "No rides available for this passenger." << endl;
    }
}

void Driver::getInfo() const {
    cout << "*************************************" << endl;
    cout << "*        Personal Information       *" << endl;
    cout << "*************************************" << endl;
    cout <<             firstName << " " << lastName << endl;
    cout << "*   Password:                  " << password << endl;
    cout << "*   Rating:                         " << driverRating << endl;
    cout << "*   Total rides:                    " << rideIds.size() << endl;


}

void Driver::editInfo() {}

void Driver::copyPropertiesFrom(const Driver *otherDriver) {

    if (otherDriver) {
        setHandicappedCapable(otherDriver->isHandicappedCapable());
        setPetsAllowed(otherDriver->isPetsAllowed());
        setDriverRating(otherDriver->getDriverRating());
        setId(otherDriver->getId());
        setFirstName(otherDriver->getFirstName());
        setLastName(otherDriver->getLastName());
        setPassword(otherDriver->getPassword());

    };
    rides.clear();
    for (auto &&ride: otherDriver->rides) {
        rides.push_back(ride);
    }


}

