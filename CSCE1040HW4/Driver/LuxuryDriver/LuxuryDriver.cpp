

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
    amenities.push_back(amenity);
}

LuxuryDriver::LuxuryDriver() = default;

LuxuryDriver::~LuxuryDriver() = default;

void LuxuryDriver::addLuxuryParameters() {
    int i;

    // Input validation loop for vehicle capacity
    while (true) {
        cout << "* Enter vehicle capacity (7+): " ;
        cin >> i;
        cout << "*****************************" << endl;

        if (cin.fail() || i < 7) {
            cout << "Invalid input. Please enter a number that is 8 or greater." ;
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

    // Input validation loops for amenities
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
        cout << "VIP Club Entrance (Y/N): " ;
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

void LuxuryDriver::readLuxuryProperties(const string &basicString) {
    istringstream dataStream(basicString);
    string temp;

    getline(dataStream, temp, ',');
    {};
    getline(dataStream, temp, ',');
    {
        this->firstName = temp;
    };
    getline(dataStream, temp, ',');
    {
        this->lastName = temp;
    };
    getline(dataStream, temp, ',');
    {
        this->password = temp;
        cout << "this password " << this->password << endl;
    };
    getline(dataStream, temp, ',');
    {
        this->vehicleType = static_cast<VehicleType>(stoi(temp));

    };

    getline(dataStream, temp, ',');
    {
        this->vehicleType = static_cast<Driver::VehicleType>(stoi(temp));
        cout << "Vehicle type temp: " << static_cast<int>(this->vehicleType) << endl;
    };

    getline(dataStream, temp, ',');
    {
        (this)->vehicleCapacity = stoi(temp);
        cout << "this->vehicleCapacity: " << (this)->vehicleCapacity  << endl;
    };
    getline(dataStream, temp, ',');
    {
        cout << "cargo capacity temp: " << temp << endl;
        (this)->cargoCapacity = temp;
    };
    if ((this)->cargoCapacity != "0") {
        getline(dataStream, temp, ',');
        {
            cout << "new cargo capacity temp: " << temp << endl;

            (this)->cargoCapacity = temp;
        };
    }

    getline(dataStream, temp, ',');
    {
        this->id = stoi(temp);
    };

    getline(dataStream, temp, ',');
    {
        temp = std::to_string(1 ? this->petsAllowed = true : this->petsAllowed = false);
    };
    getline(dataStream, temp, ',');
    {
        temp = std::to_string(1 ? this->handicappedCapable = true : this->handicappedCapable = false);
    };

    getline(dataStream, temp, ',');
    {
        this->available = true;
    };


    getline(dataStream, temp, ',');
    {
        this->driverRating = stof(temp);
    };

    getline(dataStream, temp, '\n');
    {
        for (char i : temp) {
            cout <<"adding i: "<< i << '\n';
        }
    };
    while (getline(dataStream, temp, ',')) {
        int tripID = stoi(temp);
        cout << "tripID: " << tripID << '\n';
        if (!rides.empty()) {
            rides.back().setId(tripID);
        }
    }


    cout << "Type name " << this->getTypeName() << endl;

}
