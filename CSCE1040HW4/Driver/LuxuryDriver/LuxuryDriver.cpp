

#include <limits>
#include <sstream>
#include "LuxuryDriver.h"
#include "../BasicDriver/BasicDriver.h"
#include "../EconomyDriver/EconomyDriver.h"
#include "../GroupDriver/GroupDriver.h"


void LuxuryDriver::setVehicleCapacity(int capacity) {
    vehicleCapacity = capacity;
}


void LuxuryDriver::setCargoCapacity(const string &cargo) {
    cargoCapacity = cargo;
}


void LuxuryDriver::setAmenities() {
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
        cout << "Do you have luggage storage? (Y/N): ";
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
    cout << "*************************************" << endl;
    cout << "*            Luxury Car             *" << endl;
    cout << "*************************************" << endl;
    cout << "          Vehicle Information        " << endl;
    cout << "*************************************" << endl;
    cout << "*  Handicapped Capable:             " << isHandicappedCapable() << endl;
    cout << "*  Pets Allowed :                   " << isPetsAllowed() << endl;
    cout << "*  Vehicle Capacity:                " << vehicleCapacity << endl;
    cout << "*  Cargo Capacity:                  " << cargoCapacity << endl;
    cout << "*  Amenities:                 ";
    for (const string &amenity: amenities) {
        cout << amenity << ", ";
    }
    cout << endl;

    cout << "*************************************" << endl;

    cout << endl;
}

void LuxuryDriver::editInfo() {
    char option;
    string str;
    int i;
    cout << "*************************************" << endl;
    cout << "           Driver Edit Menu          " << endl;
    cout << "*************************************" << endl;
    cout << "* What would you like to edit?      *" << endl;
    cout << "* B: Handicapped Capable:      " << isHandicappedCapable() << endl;
    cout << "* C: Pets Allowed :            " << isPetsAllowed() << endl;
    cout << "* D: First Name :              " << getFirstName() << endl;
    cout << "* E: Last Name :               " << getLastName() << endl;
    cout << "* F: Vehicle Type :            " << static_cast<int>(getVehicleType()) << endl;
    cout << "* G: Vehicle Capacity:         " << getVehicleCapacity() << endl;
    cout << "* H: Cargo Capacity:           " << getCargoCapacity() << endl;
    cout << "* I: Amenities:                ";
    for (const string &amenity: getAmenities()) {
        cout << amenity << ", ";
    }
    cout << "* Q: Quit:                     "  << endl;

    cout << endl;
    cout << "*************************************" << endl;

    cin >> option;


    switch (option) {

        case 'b':
        case 'B':
            cout << "Driving a handicapable vehicle? (Y/N): " <<
                 endl;
            cin >>
                option;
            if (option == 'Y' || option == 'y') {
                setHandicappedCapable(true);
            } else if (option == 'N' || option == 'n') {
                setHandicappedCapable(false);

            } else {
                cout << "Not a proper answer, try again" << endl;
                cin >> option;
            }
            break;
        case 'c':
        case 'C':
            cout << "New pet policy (Y/N): " << endl;
            cin >> option;
            if (option == 'Y' || option == 'y') {
                setPetsAllowed(true);
            } else if (option == 'N' || option == 'n') {
                setPetsAllowed(false);

            } else {
                cout << "Not a proper answer, try again" << endl;
                cin >> option;
            }
            break;
        case 'd':
        case 'D':

            cout << "New first name: " << endl;
            cin >> str;
            setFirstName(str);
            break;
        case 'e':
        case 'E':

            cout << "New Last Name: " << endl;
            cin >> str;
            setLastName(str);
            break;
        case 'f':
        case 'F': {
            cout << "New Vehicle Type (1-4): " << endl;
            cin >> i;
            if (static_cast<Driver::VehicleType>(i) != getVehicleType()) {
                Driver *newDriver = nullptr;
                switch (i) {
                    case 1: {
                        newDriver = new BasicDriver;
                        dynamic_cast<BasicDriver *>(newDriver)->

                                addBasicParameters();

                        break;
                    }
                    case 2: {
                        newDriver = new EconomyDriver;
                        dynamic_cast<EconomyDriver *>(newDriver)->

                                addEconomyParameters();

                        break;
                    }
                    case 3: {
                        newDriver = new GroupDriver;
                        dynamic_cast<GroupDriver *>(newDriver)->

                                addGroupParameters();

                        break;
                    }
                    case 4:
                        cout << "You are already this vehicle." << endl;
                        break;
                    default:
                        break;
                }
                if (newDriver) {
                    newDriver->copyPropertiesFrom(this);
                    newDriver->setVehicleType(static_cast<Driver::VehicleType>(i)
                    );

                } else {
                    cout << "Memory allocation failed." << endl;
                }
            } else {
                cout << "You are already this type of vehicle!" << endl;
            }
            break;
        }
        case 'g':
        case 'G': {

            cout << "New Vehicle Capacity: " << endl;
            cin >> i;
            setVehicleCapacity(i);

            break;
        }
        case 'h':
        case 'H':

            cout << "New Cargo Capacity: " << endl;
            cin >> str;
            setCargoCapacity(str);

            break;

        case 'i':
        case 'I':

            cout << "New Amenities: " << endl;
            setAmenities();

            break;

        case 'q':
        case 'Q':
            return;

        default:
            cout << "Invalid option, try again." << endl;
            cin >> option;

    }
}

void LuxuryDriver::readLuxuryProperties(const string &basicString) {


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
        id = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        password = temp;
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


void LuxuryDriver::writeDriverProperties(ostream &dataFile) {
    dataFile << "Driver,";

    dataFile << static_cast<int>(vehicleType) << ",";
    dataFile << firstName << ",";
    dataFile << lastName << ",";
    dataFile << id << ",";
    dataFile << password << ",";
    dataFile << petsAllowed << ",";
    dataFile << handicappedCapable << ",";
    dataFile << available << ",";
    dataFile << driverRating << ",";

    dataFile << vehicleCapacity << ",";
    cargoCapacity != "no luggage" ? dataFile << "1," << cargoCapacity << "," : dataFile << "0,";


    int bottle = 0, club = 0, female = 0, bodyguard = 0;
    for (const string &amenity: amenities) {
        bottle += (amenity == "bottle") ? 1 : 0;
        club += (amenity == "club") ? 1 : 0;
        female += (amenity == "female") ? 1 : 0;
        bodyguard += (amenity == "bodyguard") ? 1 : 0;
    }
    dataFile << bottle << "," << club << "," << female << "," << bodyguard << ",";


    for (const Ride *ride: rides) {
        dataFile << ride->getId() << ",";
    }
    dataFile << "\n";
}

