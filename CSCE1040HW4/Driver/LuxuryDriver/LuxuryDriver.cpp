

#include <limits>
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
    amenities.push_back(amenity);
}

LuxuryDriver::LuxuryDriver() = default;

LuxuryDriver::~LuxuryDriver() = default;

void LuxuryDriver::addLuxuryParameters() {
    int i;

    // Input validation loop for vehicle capacity
    while (true) {
        cout << "Enter vehicle capacity (8+): " << endl;
        cin >> i;
        if (cin.fail() || i < 8) {
            cout << "Invalid input. Please enter a number that is 8 or greater." << endl;
            cin.clear();
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
        cout << "Will you be bringing luggage? (Y/N): " << endl;
        cin >> option;
        cin.ignore();
        if (option == 'Y' || option == 'y') {
            cout << "Enter description of luggage: " << endl;
            cin >> str;
            cargoCapacity = str;
            break;
        } else if (option == 'N' || option == 'n') {
            cargoCapacity = "no luggage";
            break;
        } else {
            cout << "Invalid input. Please enter either Y or N." << endl;
        }
    }

    cout << "Please choose amenities needed: " << endl;

    // Input validation loops for amenities
    while (true) {
        cout << "Bottle service (Y/N): " << endl;
        cin >> option;
        cin.ignore();
        if (option == 'Y' || option == 'y') {
            amenities.emplace_back("bottle");
            break;
        } else if (option == 'N' || option == 'n') {
            break;
        } else {
            cout << "Invalid input. Please enter either Y or N." << endl;
        }
    }

    while (true) {
        cout << "VIP Club Entrance (Y/N): " << endl;
        cin >> option;
        cin.ignore();
        if (option == 'Y' || option == 'y') {
            amenities.emplace_back("club");
            break;
        } else if (option == 'N' || option == 'n') {
            break;
        } else {
            cout << "Invalid input. Please enter either Y or N." << endl;
        }
    }

    while (true) {
        cout << "Female Entertainment (Y/N): " << endl;
        cin >> option;
        cin.ignore();
        if (option == 'Y' || option == 'y') {
            amenities.emplace_back("female");
            break;
        } else if (option == 'N' || option == 'n') {
            break;
        } else {
            cout << "Invalid input. Please enter either Y or N." << endl;
        }
    }

    while (true) {
        cout << "Bodyguard (Y/N): " << endl;
        cin >> option;
        cin.ignore();
        if (option == 'Y' || option == 'y') {
            amenities.emplace_back("bodyguard");
            break;
        } else if (option == 'N' || option == 'n') {
            break;
        } else {
            cout << "Invalid input. Please enter either Y or N." << endl;
        }
    }
}


void LuxuryDriver::getInfo() const {
    Driver::getInfo();
    cout << "LuxDriver version " <<  endl;

    cout << "Vehicle Capacity: " << vehicleCapacity << endl;
    cout << "Cargo Capacity: " << cargoCapacity << endl;
    cout << "Amenities: ";
    for (const string &amenity: amenities) {
        cout << amenity << ", ";
    }
    cout << endl;
}

void LuxuryDriver::editInfo() {}

