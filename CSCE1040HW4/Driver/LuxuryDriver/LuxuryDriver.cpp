

#include "LuxuryDriver.h"

void LuxuryDriver::setVehicleCapacity() {

}

void LuxuryDriver::setCargoCapacity() {

}

void LuxuryDriver::setAmenities() {

}

LuxuryDriver::LuxuryDriver() {

}

LuxuryDriver::~LuxuryDriver() {

}

void LuxuryDriver::addLuxuryParameters() {
    int i;
    cout << "Enter vehicle capacity (8+): " << endl;
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
    }


    cout << "Please choose amenities needed: " << endl;

    cout << "Bottle service (Y/N): " << endl;
    if (option == 'Y' || option == 'y'){
        amenities.emplace_back("bottle");
    };
    cout << "VIP Club Entrance (Y/N): " << endl;
    if (option == 'Y' || option == 'y'){
        amenities.emplace_back("club");
    };
    cout << "Female Entertainment (Y/N): " << endl;
    if (option == 'Y' || option == 'y'){
        amenities.emplace_back("female");
    };
    cout << "Bodyguard (Y/N): " << endl;
    if (option == 'Y' || option == 'y'){
        amenities.emplace_back("bodyguard");
    };



}
