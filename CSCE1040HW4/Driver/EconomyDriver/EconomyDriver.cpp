

#include "EconomyDriver.h"

void EconomyDriver::setVehicleCapacity() {

}


void EconomyDriver::setCargoCapacity() {

}

void EconomyDriver::setAmenities() {

}

EconomyDriver::EconomyDriver() {

}

EconomyDriver::~EconomyDriver() {

}

void EconomyDriver::addEconomyParameters() {

    int i;
    cout << "Enter vehicle capacity (2-4): " << endl;
    cin >> i;
    vehicleCapacity = i;

    char option;
    string str;
    cout << "Will you be bringing luggage? (Y/N)" << endl;
    if (option == 'Y' || option == 'y'){
        cout << "Enter description of luggage: " << endl;
        cin >> str;
        cargoCapacity = str;
    } else {
        cargoCapacity = "no luggage";
    };


}

void EconomyDriver::readEconomyProperties(const string &basicString) {

}
