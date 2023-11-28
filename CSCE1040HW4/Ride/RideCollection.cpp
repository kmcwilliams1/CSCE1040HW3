

#include <limits>
#include <fstream>
#include <random>
#include <sstream>
#include "RideCollection.h"
#include "Ride.h"
#include "../Passenger/Passenger.h"

Ride *RideCollection::addRide(Ride* newRide) {
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
    char inputChar;
    cout << "*************************************" << endl;
    cout << "How many passengers? ";
    cin >> i;
   newRide->sizeOfParty = i;
    cin.ignore();


    while (cin.fail()) {
        cout << "Requires a number. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> i;
    }
    cout << "*************************************" << endl;
    cout << "Enter pickup location: ";
    getline(cin,string1);
   newRide->pickupLocation = string1;

    cout << "*************************************" << endl;
    cout << "Enter drop off location: ";
    getline(cin,string1);
   newRide->dropOffLocation = string1;

    cout << "*************************************" << endl;
    cout << "Enter note: ";
    getline(cin,string1);
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
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 20000);
    int random_number = distribution(generator);
   newRide->id = random_number;


    this->rides.push_back(newRide);

    cout << "*************************************" << endl;
    cout << "Ride Added" << endl;
    cout <<newRide->pickupLocation << " -> " <<newRide->dropOffLocation << endl;
    cout <<newRide->pickupTime << endl;
    cout << "*************************************" << endl;
    cout << "\n\n\n" ;

    return newRide;
}

void RideCollection::assignSchedule(Driver &driver) {
    for (Ride *currentRide : this->rides) {
        if (currentRide->rideStatus == Ride::RideStatus::Active &&
           currentRide->assignedDriverId == 0 &&
           currentRide->includesPets && driver.petsAllowed &&
           currentRide->handicapable && driver.handicappedCapable &&
           currentRide->rating >= driver.driverRating) {

            driver.rides.push_back(*currentRide);
           currentRide->setAssignedDriverId(driver.id);
        }

    }

    cout << "Rides Assigned! " << endl;
}

void RideCollection::readRideProperties(const string& basicString) {

    istringstream dataStream(basicString);
    string temp;
    auto *ride = new Ride;

    getline(dataStream, temp, ',');
    {
    };
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
    };
    getline(dataStream, temp, ',');
    {
        ride->pickupLocation = temp;
    };
    getline(dataStream, temp, ',');
    {
        ride->dropOffLocation = temp;
    };
    getline(dataStream, temp, ',');
    {
        ride->pickupTime = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        ride->note = temp;
    };
    getline(dataStream, temp, ',');
    {
        temp == "1" ? ride->handicapable = true : ride->handicapable = false;
    };
    getline(dataStream, temp, ',');
    {
        temp == "1" ? ride->includesPets = true : ride->includesPets = false;
    };
    getline(dataStream, temp, ',');
    {
        ride->id = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        ride->assignedPassengerId = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        ride->assignedDriverId = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        ride->rating = stof(temp);
        cout << ride->id << " reading rating " << ride->rating << endl;

    };

    this->rides.push_back(ride);
}
