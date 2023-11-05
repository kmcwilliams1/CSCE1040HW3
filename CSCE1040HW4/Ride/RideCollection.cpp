

#include <limits>
#include <fstream>
#include <random>
#include "RideCollection.h"
#include "Ride.h"
#include "../Passenger/Passenger.h"

Ride RideCollection::addRide(Ride newRide) {

    int i;
    string string1;
    char inputChar;

    cout << "How many passengers would you like?" << endl;
    cin >> i;
    newRide.sizeOfParty = i;

    /*this while loop protects edge cases, doesnt allow for non type specific characters*/

    while (cin.fail()) {
        cout << "Requires an integer. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> i;
    }

    cout << "Enter pickup location: " << endl;
    cin >> string1;
    newRide.pickupLocation = string1;

    cout << "Enter drop off location: " << endl;
    cin >> string1;
    newRide.dropOffLocation = string1;

    cout << "Enter note: " << endl;
    cin >> string1;
    newRide.note = string1;

    cout << "Do you need a handicapable vehicle (Y/N): " << endl;
    cin >> inputChar;

    while (inputChar != 'Y' && inputChar != 'y' && inputChar != 'N' && inputChar != 'n') {
        cout << "Invalid input. Please enter 'Y' or 'N': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> inputChar;
    }

    newRide.handicapable = (inputChar == 'Y' || inputChar == 'y');

    cout << "Do you have pets (Y/N): " << endl;
    cin >> inputChar;

    while (inputChar != 'Y' && inputChar != 'y' && inputChar != 'N' && inputChar != 'n') {
        cout << "Invalid input. Please enter 'Y' or 'N': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> inputChar;
    }

    newRide.includesPets = (inputChar == 'Y' || inputChar == 'y');

    newRide.assignedDriverId = 0;
    newRide.rideStatus = Ride::RideStatus::Active;

    //time
    newRide.setPickupTime();

    //true random number generator
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 20000);
    int random_number = distribution(generator);
    newRide.id = random_number;


    this->rides.push_back(newRide);


    cout << "Ride Added" << endl;
    cout << newRide.pickupLocation << " -> " << newRide.dropOffLocation << endl;
    cout << newRide.pickupTime << endl;


    cout << endl;
    return newRide;
}

void RideCollection::assignSchedule(Driver &driver) {
    for (Ride &currentRide : this->rides) {
        if (currentRide.rideStatus == Ride::RideStatus::Active &&
            currentRide.assignedDriverId == 0 &&
            currentRide.includesPets && driver.petsAllowed &&
            currentRide.handicapable && driver.handicappedCapable &&
            currentRide.rating >= driver.driverRating) {

            driver.rides.push_back(currentRide);
            currentRide.assignedDriverId = driver.id;
        }

    }

    cout << "Rides Assigned! " << endl;
}


