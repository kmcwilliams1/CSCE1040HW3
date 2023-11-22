

#include <sstream>
#include "GroupDriver.h"



void GroupDriver::setCargoCapacity(const string &cargo) {
    cargoCapacity = cargo;

}

void GroupDriver::setVehicleCapacity(int capacity) {
    vehicleCapacity = capacity;

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
    cout << "Will you be bringing luggage? (Y/N) " << endl;
    if (option == 'Y' || option == 'y'){
        cout << "Enter description of luggage: " << endl;
        cin >> str;
        cargoCapacity = str;
    } else {
        cargoCapacity = "no luggage";
    };





}

void GroupDriver::readGroupProperties(const string &basicString) {


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
