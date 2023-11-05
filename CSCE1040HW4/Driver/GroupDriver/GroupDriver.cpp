

#include "GroupDriver.h"

void GroupDriver::setAmenities() {

}

void GroupDriver::setCargoCapacity() {

}

void GroupDriver::setVehicleCapacity() {

}


GroupDriver::GroupDriver() {

}

GroupDriver::~GroupDriver() {

}

void GroupDriver::addGroupParameters() {

    int i;
    cout << "Enter vehicle capacity (5-7): " << endl;
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
