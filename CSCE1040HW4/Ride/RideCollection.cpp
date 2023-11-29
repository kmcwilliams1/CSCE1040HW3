

#include <limits>
#include <random>
#include <sstream>
#include "RideCollection.h"
#include "Ride.h"

Ride* RideCollection::addRide(Ride* newRide) {
    char inputChar;
    char confirm;

    do {
        cout << "\n\n\n\n\n\n\n\n\n";
        cout << "********************************" << endl;
        cout << "********************************" << endl;
        cout << "    _   _                \n"
                "   | \\ | | _____      __ \n"
                "   |  \\| |/ _ \\ \\ /\\ / / \n"
                "   | |\\  |  __/\\ V  V /  \n"
                "   |_|_\\_|\\___| \\_/\\_/   \n"
                "   |  _ \\(_) __| | ___   \n"
                "   | |_) | |/ _` |/ _ \\  \n"
                "   |  _ <| | (_| |  __/  \n"
                "   |_| \\_\\_|\\__,_|\\___|  " << endl;

        cout << "********************************" << endl;
        cout << "********************************" << endl << endl << endl;

        cout << "********************************" << endl;
        cout << "*     Personal Information:    *" << endl;
        cout << "********************************" << endl;
        int i;
        string string1;

        cout << "*************************************" << endl;
        cout << "How many passengers? ";
        cin >> i;

        while (cin.fail()) {
            cout << "Requires a number. Try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> i;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        newRide->sizeOfParty = i;

        cout << "*************************************" << endl;
        cout << "Enter pickup location: ";
        getline(cin, string1);
        newRide->pickupLocation = string1;

        cout << "*************************************" << endl;
        cout << "Enter drop-off location: ";
        getline(cin, string1);
        newRide->dropOffLocation = string1;

        cout << "*************************************" << endl;
        cout << "Enter note: ";
        getline(cin, string1);
        newRide->note = string1;

        cout << "*************************************" << endl;
        cout << "Do you need a handicapable vehicle (Y/N): ";
        cin >> inputChar;

        while (inputChar != 'Y' && inputChar != 'y' && inputChar != 'N' && inputChar != 'n') {
            cout << "Invalid input. Please enter 'Y' or 'N': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> inputChar;
        }

        newRide->handicapable = (inputChar == 'Y' || inputChar == 'y');

        cout << "*************************************" << endl;
        cout << "Do you have pets (Y/N): ";
        cin >> inputChar;

        while (inputChar != 'Y' && inputChar != 'y' && inputChar != 'N' && inputChar != 'n') {
            cout << "Invalid input. Please enter 'Y' or 'N': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> inputChar;
        }

        newRide->includesPets = (inputChar == 'Y' || inputChar == 'y');

        newRide->assignedDriverId = 0;
        newRide->rideStatus = Ride::RideStatus::Active;

        //time
        newRide->setPickupTime();

        //true random number generator

        newRide->setId();

        cout << "*************************************" << endl;
        cout << "Current Ride" << endl;
        cout << newRide->sizeOfParty << (newRide->sizeOfParty == 1 ? " person" : " people") << endl;
        cout << newRide->pickupLocation << " -> " << newRide->dropOffLocation << endl;
        if (newRide->handicapable) cout << "Handicapable ";
        if (newRide->handicapable && newRide->includesPets) cout << "& ";
        if (newRide->includesPets) {
            cout << "Has Pets ";
            cout << endl;
            cout << newRide->getPickupTime() << endl;

            cout << "*************************************" << endl;
            cout << "Confirm ride information (Y/N): ";
            cin >> confirm;

            if (confirm == 'Y' || confirm == 'y') {
                this->rides.push_back(newRide);
                cout << "*************************************" << endl;
                cout << "Ride Added" << endl;
            } else {
                cout << "Ride information not confirmed. Please enter the details again." << endl;
            }

        }
        cout << "\n\n\n";
    } while (confirm != 'Y' && confirm != 'y');

    return newRide;
}


void RideCollection::assignSchedule(Driver &driver) {
    bool found = false;

    for (Ride *currentRide: this->rides) {
        if (currentRide->rideStatus == Ride::RideStatus::Active &&
            currentRide->assignedDriverId == 0 &&
            currentRide->includesPets && driver.petsAllowed &&
            currentRide->handicapable && driver.handicappedCapable &&
            currentRide->rating >= driver.driverRating) {

            driver.rides.push_back(currentRide);
            currentRide->setAssignedDriverId(driver.id);
            found = true;
        }
    }

    if (!found) {
        cout << "No active rides meet your vehicle's options." << endl;
    } else {
        cout << "Rides Assigned!" << endl;
    }
}


void RideCollection::readRideProperties(const string &basicString) {

    istringstream dataStream(basicString);
    string temp;
    auto *ride = new Ride;

    getline(dataStream, temp, ',');
    {
    }
    getline(dataStream, temp, ',');
    if (temp == "12") {
        ride->rideStatus = Ride::RideStatus::Active;
    } else if (temp == "13") {
        ride->rideStatus = Ride::RideStatus::Completed;
    } else {
        ride->rideStatus = Ride::RideStatus::Cancelled;
    }
    getline(dataStream, temp, ',');
    {
        ride->sizeOfParty = stoi(temp);
    }
    getline(dataStream, temp, ',');
    {
        ride->pickupLocation = temp;
    }
    getline(dataStream, temp, ',');
    {
        ride->dropOffLocation = temp;
    }
    getline(dataStream, temp, ',');
    {
        ride->pickupTime = stoi(temp);
    }
    getline(dataStream, temp, ',');
    {
        ride->note = temp;
    }
    getline(dataStream, temp, ',');
    {
        temp == "1" ? ride->handicapable = true : ride->handicapable = false;
    }
    getline(dataStream, temp, ',');
    {
        temp == "1" ? ride->includesPets = true : ride->includesPets = false;
    }
    getline(dataStream, temp, ',');
    {
        ride->id = stoi(temp);
    }
    getline(dataStream, temp, ',');
    {
        ride->assignedPassengerId = stoi(temp);
    }
    getline(dataStream, temp, ',');
    {
        ride->assignedDriverId = stoi(temp);
    }
    getline(dataStream, temp, ',');
    {
        ride->rating = stof(temp);

    }

    this->rides.push_back(ride);
}
