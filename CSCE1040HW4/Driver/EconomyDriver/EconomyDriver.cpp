

#include <sstream>
#include "EconomyDriver.h"
#include "../LuxuryDriver/LuxuryDriver.h"
#include "../BasicDriver/BasicDriver.h"
#include "../GroupDriver/GroupDriver.h"

void EconomyDriver::setVehicleCapacity(int capacity) {
    vehicleCapacity = capacity;

}


void EconomyDriver::setCargoCapacity(const string &cargo) {
    cargoCapacity = cargo;
}


EconomyDriver::EconomyDriver() = default;

EconomyDriver::~EconomyDriver() = default;

void EconomyDriver::addEconomyParameters() {

    int i;
    cout << "Enter vehicle capacity (2-4): " << endl;
    cin >> i;
    vehicleCapacity = i;

    char option;
    string str;
    cout << "Will you be bringing luggage? (Y/N)" << endl;
    cin >> option;
    if (option == 'Y' || option == 'y') {
        cout << "Enter description of luggage: " << endl;
        cin >> str;
        cargoCapacity = str;
    } else {
        cargoCapacity = "no luggage";
    };


}

void EconomyDriver::getInfo() const {
    Driver::getInfo();

    cout << "Vehicle Capacity: " << vehicleCapacity << endl;
    cout << "Cargo Capacity: " << cargoCapacity << endl;
    cout << endl;
}

void EconomyDriver::editInfo() {
    char option;
    string str;
    int i;
    cout << "*************************************" << endl;
    cout << "           Driver Edit Menu          " << endl;
    cout << "*************************************" << endl;
    cout << "* What would you like to edit?      *" << endl;
    cout << "* B: Handicapped Capable:      " << isHandicappedCapable() << endl;
    cout << "* C: Pets Allowed :            " << isPetsAllowed() << endl;
    cout << "* D: First Name :              " << getFirstName() << endl;
    cout << "* E: Last Name :               " << getLastName() << endl;
    cout << "* F: Vehicle Type :            " << static_cast<int>(getVehicleType()) << endl;
    cout << "* G: Vehicle Capacity:         " << getVehicleCapacity() << endl;
    cout << "* H: Cargo Capacity:           " << getCargoCapacity() << endl;
    cout << endl;
    cout << "*************************************" << endl;

    cin >> option;


    switch (option) {


        case 'B':
            cout << "Driving a handicapable vehicle? (Y/N): " <<
                 endl;
            cin >>
                option;
            if (option == 'Y' || option == 'y') {
                setHandicappedCapable(true);
            } else if (option == 'N' || option == 'n') {
                setHandicappedCapable(false);

            } else {
                cout << "Not a proper answer, try again" << endl;
                cin >> option;
            }
            break;

        case 'C':
            cout << "New pet policy (Y/N): " << endl;
            cin >> option;
            if (option == 'Y' || option == 'y') {
                setPetsAllowed(true);
            } else if (option == 'N' || option == 'n') {
                setPetsAllowed(false);

            } else {
                cout << "Not a proper answer, try again" << endl;
                cin >> option;
            }
            break;

        case 'D':

            cout << "New first name: " << endl;
            cin >> str;
            setFirstName(str);
            break;

        case 'E':

            cout << "New Last Name: " << endl;
            cin >> str;
            setLastName(str);
            break;

        case 'F': {
            cout << "New Vehicle Type (1-4): " << endl;
            cin >> i;
            if (static_cast<Driver::VehicleType>(i) != getVehicleType()) {
                Driver *newDriver = nullptr;
                switch (i) {
                    case 1: {
                        newDriver = new BasicDriver;
                        dynamic_cast<BasicDriver *>(newDriver)->

                                addBasicParameters();

                        break;
                    }
                    case 2: {
                        newDriver = new EconomyDriver;
                        dynamic_cast<EconomyDriver *>(newDriver)->

                                addEconomyParameters();

                        break;
                    }
                    case 3: {
                        newDriver = new GroupDriver;
                        dynamic_cast<GroupDriver *>(newDriver)->

                                addGroupParameters();

                        break;
                    }
                    case 4:
                        cout << "You are already this vehicle." << endl;
                        break;
                    default:
                        break;
                }
                if (newDriver) {
                    newDriver->copyPropertiesFrom(this);
                    newDriver->setVehicleType(static_cast<Driver::VehicleType>(i)
                    );

                } else {
                    cout << "Memory allocation failed." << endl;
                }
            } else {
                cout << "You are already this type of vehicle!" << endl;
            }
            break;
        }


        case 'G': {

            cout << "New Vehicle Capacity: " << endl;
            cin >> i;
            setVehicleCapacity(i);

            break;
        }

        case 'H':

            cout << "New Cargo Capacity: " << endl;
            cin >> str;
            setCargoCapacity(str);

            break;


        default:
            cout << "Invalid option, try again." << endl;
            cin >> option;

    }
}


void EconomyDriver::readEconomyProperties(const string &basicString) {


    istringstream dataStream(basicString);
    string temp;

    dataStream.clear();
    dataStream.seekg(0);

    getline(dataStream, temp, ',');
    {/*this line reads the word Driver*/};

    getline(dataStream, temp, ',');
    {
        vehicleType = static_cast<VehicleType>(stoi(temp));

    };
    getline(dataStream, temp, ',');
    {
        firstName = temp;
    };
    getline(dataStream, temp, ',');
    {
        lastName = temp;
    };
    getline(dataStream, temp, ',');
    {
        password = temp;
    };


    getline(dataStream, temp, ',');
    {
        vehicleCapacity = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        cargoCapacity = temp;
    };
    if (cargoCapacity != "0") {
        getline(dataStream, temp, ',');
        {
            cargoCapacity = temp;
        };
    }

    getline(dataStream, temp, ',');
    {
        id = stoi(temp);
    };

    getline(dataStream, temp, ',');
    {
        if (temp == "1") { petsAllowed = true; } else { petsAllowed = false; };
    };
    getline(dataStream, temp, ',');
    {
        if (temp == "1") { handicappedCapable = true; } else { handicappedCapable = false; };
    };

    getline(dataStream, temp, ',');
    {
        available = true;
    };


    getline(dataStream, temp, ',');
    {
        driverRating = stof(temp);
    };

    getline(dataStream, temp, '\n');
    {
        int tripID = 0;
        for (char i: temp) {
            if (i != ',') {
                tripID = tripID * 10 + (i - '0');
            } else {
                rideIds.push_back(tripID);
                tripID = 0;

            }
        }
    }


}

void EconomyDriver::writeDriverProperties(ostream &dataFile) {
    dataFile << "Driver,";

    dataFile << static_cast<int>(vehicleType) << ",";

    dataFile << firstName << ",";

    dataFile << lastName << ",";

    dataFile << id << ",";

    dataFile << vehicleCapacity << ",";

    dataFile << cargoCapacity << ",";

    cargoCapacity == "1" && dataFile << cargoCapacity << ",";

    dataFile << handicappedCapable << ",";

    dataFile << petsAllowed << ",";

    dataFile << driverRating << ",";

    cout << "Now reading" << password << endl;

    for (const Ride &ride: rides) {
        dataFile << ride.getId() << ",";
    }
    dataFile << "\n";
}