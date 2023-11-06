

#include "DriverCollection.h"
#include "Driver.h"
#include "LuxuryDriver/LuxuryDriver.h"
#include "BasicDriver/BasicDriver.h"
#include "EconomyDriver/EconomyDriver.h"
#include "GroupDriver/GroupDriver.h"
#include <iostream>
#include <limits>
#include <random>

using namespace std;


Driver * DriverCollection::addDriver() {

    auto* newDriver = new Driver;
    int vehicleCapacity;
    bool handicappedCapable;
    int vehicleType;
    bool petsAllowed;
    string firstName;
    string lastName;
    vector<Ride> rides;
    string password;

    while (true) {
        cout << "Enter Vehicle Type (1 for Basic, 2 for Economy, 3 for Group, 4 for Luxury): ";
        cin >> vehicleType;

        switch (vehicleType) {
            case 1:  // Basic Driver
            {
                BasicDriver basicDriver;
                break;
            }
            case 2:  // Economy Driver
            {
                EconomyDriver economyDriver;
                break;
            }
            case 3:  // Group Driver
            {
                GroupDriver groupDriver;
                break;
            }
            case 4:  // Luxury Driver
            {
                LuxuryDriver luxuryDriver;
                break;
            }
            default:
                cout << "Invalid input. Please enter a number between 1 and 4." << endl;
                cin.clear();
                cin >> vehicleType;
        }

        if (vehicleType >= 1 && vehicleType <= 4) {
            break;
        }
    }

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
    newDriver->handicappedCapable = handicappedCapable;

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
    newDriver->petsAllowed = petsAllowed;


    cout << "Enter First Name: ";
    cin >> firstName;
    newDriver->firstName = firstName;

    cout << "Enter Last Name: ";
    cin >> lastName;
    newDriver->lastName = lastName;

    cout << "Enter Password: ";
    cin >> password;
    newDriver->password = password;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 20000);
    int random_number = distribution(generator);
    newDriver->id = random_number;


    this->drivers.push_back(newDriver);
    return newDriver;


}

void DriverCollection::removeDriver(const Driver& driver) {
    for (auto it = this->drivers.begin(); it != this->drivers.end(); ) {
        if ((*it)->getId() == driver.getId()) {
            delete *it;
            it = this->drivers.erase(it);
        } else {
            ++it;
        }
    }
}

