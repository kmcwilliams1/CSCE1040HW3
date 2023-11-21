

#include <limits>
#include <sstream>
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
        cout << "Enter vehicle capacity (2-4): ";

        // Check if input is an integer and within the specified range
        if (!(cin >> i) || (i < 2 || i > 4)) {
            cout << "Invalid input. Please enter a number between 2 and 4." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            setVehicleCapacity(i);
            break;
        }
    }

    cout << "*************************************" << endl;


    char option;
    string str;

    while (true) {
        cout << "Will you be bringing luggage? (Y/N) ";
        cin >> option;

        if (option == 'Y' || option == 'y') {
            cout << "Enter description of luggage: ";
            cin >> str;
            setCargoCapacity(str);
            break;
        } else if (option == 'N' || option == 'n') {
            setCargoCapacity("no luggage");
            break;
        } else {
            cout << "Not a valid input, please try again: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "*************************************" << endl;


}


void BasicDriver::getInfo() const {
    Driver::getInfo();

    cout << "Vehicle Capacity: " << vehicleCapacity << endl;
    cout << "Cargo Capacity: " << cargoCapacity << endl;
    cout << endl;
}

void BasicDriver::editInfo() {}

void BasicDriver::readBasicProperties(const string &basicString) {


    istringstream dataStream(basicString);
    string temp;

    cout << "Input string: " << basicString << endl;
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
        id = stoi(temp);
    };

    getline(dataStream, temp, ',');
    {
        temp = to_string(1 ? petsAllowed = true : petsAllowed = false);
    };
    getline(dataStream, temp, ',');
    {
        temp = to_string(1 ? handicappedCapable = true : handicappedCapable = false);
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


