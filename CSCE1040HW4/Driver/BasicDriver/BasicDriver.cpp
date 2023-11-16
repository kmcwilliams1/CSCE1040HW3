

#include <limits>
#include "BasicDriver.h"

void BasicDriver::setVehicleCapacity(int capacity) {
    vehicleCapacity = capacity;
}

void BasicDriver::setCargoCapacity(const string &cargo) {
    cargoCapacity = cargo;

}


BasicDriver::~BasicDriver() = default;

BasicDriver::BasicDriver() = default;

void BasicDriver::addBasicParameters() {

    int i;
    while (true) {
        cout << "Enter vehicle capacity (2-4): " << endl;
        cin >> i;
        if (cin.fail() || i < 2 || i > 4) {
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


}


void BasicDriver::getInfo() const {
    Driver::getInfo();
    cout << "Basic Driver version " << endl;

    cout << "Vehicle Capacity: " << vehicleCapacity << endl;
    cout << "Cargo Capacity: " << cargoCapacity << endl;
    cout << endl;
}

void BasicDriver::editInfo() {}


