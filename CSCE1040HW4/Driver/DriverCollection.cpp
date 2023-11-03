

#include "DriverCollection.h"
#include "Driver.h"
#include <iostream>
#include <limits>

using namespace std;


Driver DriverCollection::addDriver(Driver newDriver) {

    enum class VehicleType {
        BasicDriver = 1,
        EconomyDriver,
        GroupDriver,
        LuxuryDriver,
        Other
    };
    int vehicleCapacity;
    bool handicappedCapable;
    VehicleType vehicleType;
    float driverRating = 0;
    bool petsAllowed;
    bool available = false;
    int id;
    string firstName;
    string lastName;
    int completedRides = 0;
    int cancelledRides = 0;
    vector<Ride> rides;
    string password;


    while (true) {
        cout << "Enter Vehicle Type: ";
        cin >> vehicleCapacity;
        if (cin.fail() || vehicleCapacity < 0) {
            cout << "Invalid input. Please enter a non-negative integer for Vehicle Capacity." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    newDriver.vehicleCapacity = vehicleCapacity;


    while (true) {
        cout << "Is Handicapped Capable (1 for true, 0 for false): ";
        cin >> handicappedCapable;
        if (cin.fail() || (handicappedCapable != 0 && handicappedCapable != 1)) {
            cout << "Invalid input. Please enter either 0 for false or 1 for true." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    newDriver.handicappedCapable = handicappedCapable;


    while (true) {
        cout << "Enter Vehicle Type (1 for Compact2Dr, 2 for Sedan4Dr, 3 for SUV, 4 for Van, 5 for Other): ";
        cin >> reinterpret_cast<int &>(vehicleType);
        if (cin.fail() || static_cast<int>(vehicleType) < 1 || static_cast<int>(vehicleType) > 5) {
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    newDriver.vehicleType = static_cast<Driver::VehicleType>(vehicleType);


    while (true) {
        cout << "Are Pets Allowed (1 for true, 0 for false): ";
        cin >> petsAllowed;
        if (cin.fail() || (petsAllowed != 0 && petsAllowed != 1)) {
            cout << "Invalid input. Please enter either 0 for false or 1 for true." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    newDriver.petsAllowed = petsAllowed;


    cout << "Enter First Name: ";
    cin >> firstName;
    newDriver.firstName = firstName;

    cout << "Enter Last Name: ";
    cin >> lastName;
    newDriver.lastName = lastName;

    cout << "Enter Password: ";
    cin >> password;
    newDriver.password = password;

    this->drivers.push_back(newDriver);

    return newDriver;


}

void DriverCollection::removeDriver(const Driver& driver) {

    for (auto it = this->drivers.begin(); it != this->drivers.end(); it++) {
        if (it->id == driver.id) {
            this->drivers.erase(it);
            break;
        } else {
            it++;
        }

    }

}
