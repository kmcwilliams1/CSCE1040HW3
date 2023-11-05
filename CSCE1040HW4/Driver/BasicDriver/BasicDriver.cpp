

#include "BasicDriver.h"

void BasicDriver::setVehicleCapacity() {

}

void BasicDriver::setCargoCapacity() {

}

void BasicDriver::setAmenities() {

}

BasicDriver::~BasicDriver() {

}

BasicDriver::BasicDriver() {

}

void BasicDriver::addBasicParameters() {

    int i;
    cout << "Enter vehicle capacity (2-4): " << endl;
    cin >> i;
    vehicleCapacity = i;

    char option;
    string str;
    cout << "Will you be bringing luggage? " << endl;
    if (option == 'Y' || option == 'y'){
        cout << "Enter description of luggage: " << endl;
        cin >> str;
        cargoCapacity = str;
    } else {
        cargoCapacity = "no luggage";
    };


}
