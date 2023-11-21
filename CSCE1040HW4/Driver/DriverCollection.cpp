

#include "DriverCollection.h"
#include "Driver.h"
#include "LuxuryDriver/LuxuryDriver.h"
#include "BasicDriver/BasicDriver.h"
#include "EconomyDriver/EconomyDriver.h"
#include "GroupDriver/GroupDriver.h"
#include <iostream>
#include <limits>
#include <random>
#include <sstream>

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


    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "********************************" << endl;
    cout << "********************************" << endl;
    cout << "      ___          __   __          ___  __  \n"
            "|\\ | |__  |  |    |  \\ |__) | \\  / |__  |__) \n"
            "| \\| |___ |/\\|    |__/ |  \\ |  \\/  |___ |  \\ \n"
            "                                             " << endl;

    cout << "********************************" << endl;
    cout << "********************************" << endl << endl << endl;


    cout << "********************************" << endl;
    cout << "*     Personal Information:    *" << endl;
    cout << "********************************" << endl;
    cout << "*  First Name: ";
    cin >> firstName;
    newDriver->firstName = firstName;
    cout << "*  Last Name: ";
    cin >> lastName;
    newDriver->lastName = lastName;
    cout << "*  Password: ";
    cin >> password;
    newDriver->password = password;
    cout << "********************************" << endl;
    cout << "\n";


    while (true) {
        cout << "********************************" << endl;
        cout << "*      Vehicle Information:    *" << endl;
        cout << "********************************" << endl;
        cout << "*      Enter Vehicle Type:     *" << endl;
        cout << "*1. Economy - (2 or less seats)*" << endl;
        cout << "*     2. Basic - (2-4 seats)   *" << endl;
        cout << "*    3. Group - (5-7 seats)    *" << endl;
        cout << "*   4. Luxury - (Limo-style)   *" << endl;
        cout << "********************************" << endl;
        cout << "* Type: ";

        // Check if input is an integer
        if (!(cin >> vehicleType) || (vehicleType < 1 || vehicleType > 4)) {
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    switch (vehicleType) {
        case 1:  // Economy Driver
        {
            auto *economyDriver = new EconomyDriver;
            economyDriver->addEconomyParameters();
            economyDriver->copyPropertiesFrom(newDriver);
            newDriver = economyDriver;
            break;
        }
        case 2:  // Basic Driver
        {
            auto *basicDriver = new BasicDriver;
            basicDriver->addBasicParameters();
            basicDriver->copyPropertiesFrom(newDriver);
            newDriver = basicDriver;
            break;
        }
        case 3:  // Group Driver
        {
            auto *groupDriver = new GroupDriver;
            groupDriver->addGroupParameters();
            groupDriver->copyPropertiesFrom(newDriver);
            newDriver = groupDriver;
            break;
        }
        case 4:  // Luxury Driver
        {
            auto *luxuryDriver = new LuxuryDriver;
            luxuryDriver->addLuxuryParameters();
            luxuryDriver->copyPropertiesFrom(newDriver);
            newDriver = luxuryDriver;
            break;
        }
        default:
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
    }

    newDriver->setVehicleType(static_cast<Driver::VehicleType>(vehicleType));


    char option;

    while (true) {
        cout << "Is Vehicle Handicapable? (Y/N): ";
        cin >> option;

        if (option == 'Y' || option == 'y') {
            newDriver->setHandicappedCapable(true);
            break;
        } else if (option == 'N' || option == 'n') {
            newDriver->setHandicappedCapable(false);
            break;
        } else {
            cout << "Not a valid input, please try again: " << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    cout << "*************************************" << endl;

    while (true) {
        cout << "Are Pets Allowed? (Y/N): ";
        cin >> option;

        if (option == 'Y' || option == 'y') {
            newDriver->setPetsAllowed(true);
            break;
        } else if (option == 'N' || option == 'n') {
            newDriver->setPetsAllowed(false);
            break;
        } else {
            cout << "Not a valid input, please try again: " << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    cout << "************************************* \n\n\n\n\n\n";


    /*true random number*/
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 20000);
    int random_number = distribution(generator);
    newDriver->id = random_number;

    newDriver->setAvailable(true);
    newDriver->setDriverRating(0);


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
    cout << "* What would you like to edit?      *" << endl;
    cout << "* B: Handicapped Capable:      " << driver->isHandicappedCapable() << endl;
    cout << "* C: Pets Allowed :            " << driver->isPetsAllowed() << endl;
    cout << "* D: First Name :              " << driver->getFirstName() << endl;
    cout << "* E: Last Name :               " << driver->getLastName() << endl;
    cout << "* F: Vehicle Type :            " << static_cast<int>(driver->getVehicleType()) << endl;


    switch (static_cast<int>(driver->getVehicleType())) {
        case 1: {
            auto *economyDriver = dynamic_cast<EconomyDriver *>(driver);
            cout << "* G: Vehicle Capacity:         " << economyDriver->getVehicleCapacity() << endl;
            cout << "* H: Cargo Capacity:           " << economyDriver->getCargoCapacity() << endl;

            break;
        }
        case 2: {
            auto *basicDriver = dynamic_cast<BasicDriver *>(driver);
            cout << "* G: Vehicle Capacity:         " << basicDriver->getVehicleCapacity() << endl;
            cout << "* H: Cargo Capacity:           " << basicDriver->getCargoCapacity() << endl;

            break;
        }

        case 3: {
            auto *groupDriver = dynamic_cast<GroupDriver *>(driver);
            cout << "* G: Vehicle Capacity:         " << groupDriver->getVehicleCapacity() << endl;
            cout << "* H: Cargo Capacity:           " << groupDriver->getCargoCapacity() << endl;

            break;
        }
        case 4: {
            auto *luxuryDriver = dynamic_cast<LuxuryDriver *>(driver);
            cout << "* G: Vehicle Capacity:         " << luxuryDriver->getVehicleCapacity() << endl;
            cout << "* H: Cargo Capacity:           " << luxuryDriver->getCargoCapacity() << endl;
            cout << "* I: Amenities:                ";
            for (const string &amenity: luxuryDriver->getAmenities()) {
                cout << amenity << ", ";
            }
            break;
        }
    }


    cout << "*************************************" << endl;

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

                Driver *newDriver;
                newDriver->createDriverOfType(i);


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
                delete driver;
                return newDriver;


            } else {
                cout << "You are already this type of vehicle!" << endl;
            }
            break;
        }


        case 'G':

            if (static_cast<int>(driver->getVehicleType()) > 0) {
                auto *luxuryDriver = dynamic_cast<LuxuryDriver *>(driver);
                if (luxuryDriver) {
                    cout << "New Vehicle Capacity: " << endl;
                    cin >> i;
                    luxuryDriver->setVehicleCapacity(i);
                }
            }

            break;

        case 'H':

            if (static_cast<int>(driver->getVehicleType()) > 0) {
                auto *luxuryDriver = dynamic_cast<LuxuryDriver *>(driver);
                if (luxuryDriver) {
                    cout << "New Cargo Capacity: " << endl;
                    cin >> str;
                    luxuryDriver->setCargoCapacity(str);
                }
            }

            break;

        case 'I':

            if (static_cast<int>(driver->getVehicleType()) == 4) {
                auto *luxuryDriver = dynamic_cast<LuxuryDriver *>(driver);
                if (luxuryDriver) {
                    cout << "New Vehicle Capacity: " << endl;
                    cin >> i;
                    luxuryDriver->setVehicleCapacity(i);
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

void DriverCollection::readDriverProperties(string basicString) {
    istringstream dataStream(basicString);
    string temp;


    getline(dataStream, temp, ',');
    {/*the string that says "Driver" goes here */};

    getline(dataStream, temp, ',');
    {
        int subClass = stoi(temp);
        switch (subClass) {
            case 1: {
                auto *economyDriver = new EconomyDriver;
                economyDriver->readEconomyProperties(basicString);
                break;
            }
            case 2: {
                auto *basicDriver = new BasicDriver;
                basicDriver->readBasicProperties(basicString);
                this->drivers.push_back(basicDriver);
                break;
            }
            case 3: {
                auto *groupDriver = new GroupDriver;
                groupDriver->readGroupProperties(basicString);
                break;
            }
            case 4: {
                auto *luxuryDriver = new LuxuryDriver;
                luxuryDriver->readLuxuryProperties(basicString);
                break;
            }
            default:
                break;


        }


    };


}




