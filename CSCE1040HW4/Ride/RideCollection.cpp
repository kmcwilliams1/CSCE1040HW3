

#include <limits>
#include <fstream>
#include "RideCollection.h"
#include "Ride.h"
#include "../Passenger/Passenger.h"

void RideCollection::addRide(Ride newRide) {

    ofstream fout("RideShareData.dat", ios::app);


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

    cout << "Ride Information Below: " << endl;

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



    //time
    newRide.setPickupTime();

    this->rides.push_back(newRide);

    newRide.writeRideProperties(fout);

    cout << "Ride Added" << endl;
    cout << endl;
    fout.flush();
}

void RideCollection::assignSchedule(const Driver &driver) {

}
