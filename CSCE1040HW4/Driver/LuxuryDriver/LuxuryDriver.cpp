

#include <limits>
#include <sstream>
#include "LuxuryDriver.h"
#include "../BasicDriver/BasicDriver.h"
#include "../DriverCollection.h."

void LuxuryDriver::setVehicleCapacity(int capacity) {
    vehicleCapacity = capacity;
}


void LuxuryDriver::setCargoCapacity(const string &cargo) {
    cargoCapacity = cargo;
}


void LuxuryDriver::setAmenities(const string &amenity) {
    char option;

    cout << "Please choose amenities needed: " << endl;

    while (true) {
        cout << "Bottle service (Y/N): ";
        cin >> option;

        cin.ignore();
        if (option == 'Y' || option == 'y') {
            amenities.emplace_back("bottle");
            break;
        } else if (option == 'N' || option == 'n') {
            break;
        } else {
            cout << "Invalid input. Please enter either Y or N." << endl;
            cin >> option;
            cout << "*****************************" << endl;

        }
    }

    while (true) {
        cout << "VIP Club Entrance (Y/N): ";
        cin >> option;

        cin.ignore();
        if (option == 'Y' || option == 'y') {
            amenities.emplace_back("club");
            break;
        } else if (option == 'N' || option == 'n') {
            break;
        } else {
            cout << "Invalid input. Please enter either Y or N." << endl;
            cin >> option;
            cout << "*****************************" << endl;
        }
    }

    while (true) {
        cout << "Female Entertainment (Y/N): ";
        cin >> option;

        cin.ignore();
        if (option == 'Y' || option == 'y') {
            amenities.emplace_back("female");
            break;
        } else if (option == 'N' || option == 'n') {
            break;
        } else {
            cout << "Invalid input. Please enter either Y or N." << endl;
            cin >> option;
            cout << "*****************************" << endl;
        }
    }

    while (true) {
        cout << "Bodyguard (Y/N): ";
        cin >> option;

        cin.ignore();
        if (option == 'Y' || option == 'y') {
            amenities.emplace_back("bodyguard");
            break;
        } else if (option == 'N' || option == 'n') {
            break;
        } else {
            cout << "Invalid input. Please enter either Y or N." << endl;
            cin >> option;
            cout << "*****************************" << endl;
        }
    }
}

LuxuryDriver::LuxuryDriver() = default;

LuxuryDriver::~LuxuryDriver() = default;

void LuxuryDriver::addLuxuryParameters() {
    int i;

    // Input validation loop for vehicle capacity
    while (true) {
        cout << "* Enter vehicle capacity (7+): ";
        cin >> i;
        cout << "*****************************" << endl;

        if (cin.fail() || i < 7) {
            cout << "Invalid input. Please enter a number that is 8 or greater.";
            cin >> i;
            cout << "*****************************" << endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            vehicleCapacity = i;
            cin.ignore();
            break;
        }
    }

    char option;
    string str;

    while (true) {
        cout << "Will you be bringing luggage? (Y/N): ";
        cin >> option;
        cout << "*****************************" << endl;
        cin.ignore();
        if (option == 'Y' || option == 'y') {
            cout << "Enter description of luggage: " << endl;
            cin >> str;
            cargoCapacity = str;
            cout << "*****************************" << endl;

            break;
        } else if (option == 'N' || option == 'n') {
            cargoCapacity = "no luggage";
            break;
        } else {
            cout << "Invalid input. Please enter either Y or N." << endl;
        }
    }

    cout << "Please choose amenities needed: " << endl;

    while (true) {
        cout << "Bottle service (Y/N): ";
        cin >> option;

        cin.ignore();
        if (option == 'Y' || option == 'y') {
            amenities.emplace_back("bottle");
            break;
        } else if (option == 'N' || option == 'n') {
            break;
        } else {
            cout << "Invalid input. Please enter either Y or N." << endl;
            cin >> option;
            cout << "*****************************" << endl;

        }
    }

    while (true) {
        cout << "VIP Club Entrance (Y/N): ";
        cin >> option;

        cin.ignore();
        if (option == 'Y' || option == 'y') {
            amenities.emplace_back("club");
            break;
        } else if (option == 'N' || option == 'n') {
            break;
        } else {
            cout << "Invalid input. Please enter either Y or N." << endl;
            cin >> option;
            cout << "*****************************" << endl;
        }
    }

    while (true) {
        cout << "Female Entertainment (Y/N): ";
        cin >> option;

        cin.ignore();
        if (option == 'Y' || option == 'y') {
            amenities.emplace_back("female");
            break;
        } else if (option == 'N' || option == 'n') {
            break;
        } else {
            cout << "Invalid input. Please enter either Y or N." << endl;
            cin >> option;
            cout << "*****************************" << endl;
        }
    }

    while (true) {
        cout << "Bodyguard (Y/N): ";
        cin >> option;

        cin.ignore();
        if (option == 'Y' || option == 'y') {
            amenities.emplace_back("bodyguard");
            break;
        } else if (option == 'N' || option == 'n') {
            break;
        } else {
            cout << "Invalid input. Please enter either Y or N." << endl;
            cin >> option;
            cout << "*****************************" << endl;
        }
    }
}


void LuxuryDriver::getInfo() const {
    Driver::getInfo();
    cout << "LuxDriver version " << endl;

    cout << "Vehicle Capacity: " << vehicleCapacity << endl;
    cout << "Cargo Capacity: " << cargoCapacity << endl;
    cout << "Amenities: ";
    for (const string &amenity: amenities) {
        cout << amenity << ", ";
    }
    cout << endl;
}

void LuxuryDriver::editInfo() {}

void LuxuryDriver::readLuxuryProperties(const string &basicString) {


    istringstream dataStream(basicString);
    string temp;

    dataStream.clear();
    dataStream.seekg(0);

    getline(dataStream, temp, ',');
    {
    };

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
        if (temp == "1")amenities.emplace_back("bottle");
    }
    getline(dataStream, temp, ',');
    {
        if (temp == "1")amenities.emplace_back("vip");
    }
    getline(dataStream, temp, ',');
    {
        if (temp == "1")amenities.emplace_back("female");
    }
    getline(dataStream, temp, ',');
    {
        if (temp == "1")amenities.emplace_back("bodyguard");
    }



    getline(dataStream, temp, ',');
    {
        id = stoi(temp);
    };

    getline(dataStream, temp, ',');
    {
        if (stoi(temp) == '1') { petsAllowed = true; } else { petsAllowed = false; };
    };
    getline(dataStream, temp, ',');
    {
        if (stoi(temp) == '1') { handicappedCapable = true; } else { handicappedCapable = false; };
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
                cout << "Adding tripID: " << tripID << '\n';
                rideIds.push_back(tripID);
                tripID = 0;

            }
        }
    }


}



