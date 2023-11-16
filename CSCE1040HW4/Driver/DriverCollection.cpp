

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
                auto *basicDriver = new BasicDriver;
                basicDriver->addBasicParameters();
                newDriver = basicDriver;
                break;
            }
            case 2:  // Economy Driver
            {
                auto *economyDriver = new EconomyDriver;
                economyDriver->addEconomyParameters();
                newDriver = economyDriver;
                break;
            }
            case 3:  // Group Driver
            {
                auto *groupDriver = new GroupDriver;
                groupDriver->addGroupParameters();
                newDriver = groupDriver;
                break;
            }
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
    newDriver->setVehicleType(static_cast<Driver::VehicleType>(vehicleType));

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
    cout << "updateVehicleType Driver type: " << driver->getTypeName()  << endl;
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

            if (static_cast<Driver::VehicleType>(i) != driver->getVehicleType()) {

                Driver *newDriver = createDriverOfType(i);
                cout << "driverCollection case F Driver type: " << driver->getTypeName() << endl;
                cout << "driverCollection case F newDriver type: " << newDriver->getTypeName() << endl;
                switch (i) {
                    case 1:
                        dynamic_cast<BasicDriver *>(newDriver)->addBasicParameters();
                        break;
                    case 2:
                        dynamic_cast<EconomyDriver *>(newDriver)->addEconomyParameters();
                        break;
                    case 3:
                        dynamic_cast<GroupDriver *>(newDriver)->addGroupParameters();
                        break;
                    case 4:
                        dynamic_cast<LuxuryDriver *>(newDriver)->addLuxuryParameters();
                        break;
                    default:
                        break;
                }
                newDriver->copyPropertiesFrom(driver);
                newDriver->setVehicleType(static_cast<Driver::VehicleType>(i));
                cout << "finished updating driver" << endl;
                delete driver;
                return newDriver;


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

Driver *DriverCollection::createDriverOfType(int type) {
    switch (type) {
        case 1:
            cout << "Creating BasicDriver..." << endl;
            return new BasicDriver;
        case 2:
            cout << "Creating EconomyDriver..." << endl;
            return new EconomyDriver;
        case 3:
            cout << "Creating GroupDriver..." << endl;
            return new GroupDriver;
        case 4:
            cout << "Creating LuxuryDriver..." << endl;
            return new LuxuryDriver;
        default:
            cout << "Unsupported driver type!" << endl;
            return nullptr; // Handle unsupported types
    }
}


