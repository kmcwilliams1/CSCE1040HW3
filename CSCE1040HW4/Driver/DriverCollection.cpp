

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


Driver *DriverCollection::addDriver() {

    auto *newDriver = new Driver;
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
                newDriver = new BasicDriver;
                break;
            case 2:  // Economy Driver
                newDriver = new EconomyDriver;
                break;
            case 3:  // Group Driver
                newDriver = new GroupDriver;
                break;
            case 4:  // Luxury Driver
            {
                auto *luxuryDriver = new LuxuryDriver;
                luxuryDriver->addLuxuryParameters();
                newDriver = luxuryDriver;
                break;
            }
            default:
                cout << "Invalid input. Please enter a number between 1 and 4." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

Driver *DriverCollection::updateVehicleType(Driver *driver) {
    char option;
    string str;
    int i;

    cout << "*************************************" << endl;
    cout << "           Driver Edit Menu          " << endl;
    cout << "*************************************" << endl;
    cout << "What would you like to edit?" << endl;
    cout << "B: Handicapped Capable: " << driver->isHandicappedCapable() << endl;
    cout << "C: Pets Allowed : " << driver->isPetsAllowed() << endl;
    cout << "D: First Name : " << driver->getFirstName() << endl;
    cout << "E: Last Name : " << driver->getLastName() << endl;
    cout << "F: Vehicle Type : " << static_cast<int>(driver->getVehicleType()) << endl;


    if (driver->getVehicleType() == Driver::VehicleType::LuxuryDriver) {
        auto *luxuryDriver = dynamic_cast<LuxuryDriver *>(driver);
        if (luxuryDriver) {
            cout << "G: Vehicle Capacity: " << luxuryDriver->getVehicleCapacity() << endl;
            cout << "H: Cargo Capacity: " << luxuryDriver->getCargoCapacity() << endl;
            cout << "I: Amenities: ";
            for (const string &amenity: luxuryDriver->getAmenities()) {
                cout << amenity << " ";
            }
        }
    }

    cin >> option;


    switch (option) {


        case 'B':
            cout << "Driving a handicapable vehicle? (Y/N): " << endl;
            cin >> option;
            if (option == 'Y' || option == 'y') {
                driver->setHandicappedCapable(true);
            } else if (option == 'N' || option == 'n') {
                driver->setHandicappedCapable(false);

            } else {
                cout << "Not a proper answer, try again" << endl;
                cin >> option;
            }
            break;

        case 'C':
            cout << "New pet policy (Y/N): " << endl;
            cin >> option;
            if (option == 'Y' || option == 'y') {
                driver->setPetsAllowed(true);
            } else if (option == 'N' || option == 'n') {
                driver->setPetsAllowed(false);

            } else {
                cout << "Not a proper answer, try again" << endl;
                cin >> option;
            }
            break;

        case 'D':

            cout << "New first name: " << endl;
            cin >> str;
            driver->setFirstName(str);
            break;

        case 'E':

            cout << "New Last Name: " << endl;
            cin >> str;
            driver->setLastName(str);
            break;

        case 'F': {
            cout << "New Vehicle Type (1-4): " << endl;
            cin >> i;
            auto newVehicleType = static_cast<Driver::VehicleType>(i);

            if (newVehicleType != driver->getVehicleType()) {
                Driver *newDriver = nullptr;

                switch (newVehicleType) {
                    case Driver::VehicleType::BasicDriver:
                        newDriver = new BasicDriver;
                        if (auto *basicDriver = dynamic_cast<BasicDriver *>(newDriver)) {
                            basicDriver->addBasicParameters();
                        }
                        break;
                    case Driver::VehicleType::EconomyDriver:
                        newDriver = new EconomyDriver;
                        if (auto *economyDriver = dynamic_cast<EconomyDriver *>(newDriver)) {
                            economyDriver->addEconomyParameters();
                        }
                        break;
                    case Driver::VehicleType::GroupDriver:
                        newDriver = new GroupDriver;
                        if (auto *groupDriver = dynamic_cast<GroupDriver *>(newDriver)) {
                            groupDriver->addGroupParameters();
                        }
                        break;
                    case Driver::VehicleType::LuxuryDriver:
                        newDriver = new LuxuryDriver;
                        if (auto *luxuryDriver = dynamic_cast<LuxuryDriver *>(newDriver)) {
                            luxuryDriver->addLuxuryParameters();
                        }
                        break;
                    default:
                        cout << "Unknown input, please try again." << endl;
                        cin >> i;
                        break;
                }

                if (newDriver) {
                    newDriver->copyPropertiesFrom(driver);
                    this->replaceDriver(driver, newDriver);
                    driver = newDriver;
                }


            } else {
                cout << "You are already this type of vehicle!" << endl;
            }
            break;
        }


        case 'G':

            if (driver->getVehicleType() == Driver::VehicleType::LuxuryDriver) {
                auto *luxuryDriver = dynamic_cast<LuxuryDriver *>(driver);
                if (luxuryDriver) {
                    cout << "New Vehicle Capacity: " << endl;
                    cin >> i;
                    luxuryDriver->setVehicleCapacity(i);
                }
            }

            break;

        case 'H':

            if (driver->getVehicleType() == Driver::VehicleType::LuxuryDriver) {
                auto *luxuryDriver = dynamic_cast<LuxuryDriver *>(driver);
                if (luxuryDriver) {
                    cout << "New Cargo Capacity: " << endl;
                    cin >> str;
                    luxuryDriver->setCargoCapacity(str);
                }
            }

            break;

        default:
            cout << "Invalid option, try again." << endl;
            cin >> option;

    }
    return driver;
}

void DriverCollection::replaceDriver(Driver *oldDriver, Driver *newDriver) {

    for (auto &driver: drivers) {
        if (driver == oldDriver) {
            delete driver;
            driver = newDriver;
            return;
        }
    }
    drivers.push_back(newDriver);
}


void DriverCollection::removeDriver(Driver &driver) {
    for (auto it = this->drivers.begin(); it != this->drivers.end();) {
        if ((*it)->getId() == driver.getId()) {
            delete *it;
            it = this->drivers.erase(it);
        } else {
            ++it;
        }
    }
}

