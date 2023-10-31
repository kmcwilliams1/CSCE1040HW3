

#include <limits>
#include <fstream>
#include "RideCollection.h"
#include "Ride.h"
#include "../Passenger/Passenger.h"

void RideCollection::addRide(Passenger passenger) {

    Ride newRide;
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
    struct tm timeInfo{};
    time_t userTime;
    int month, day, hour, minute;

    cout << "Is it this month (Y/N): ";
    cin >> inputChar;

    while (inputChar != 'Y' && inputChar != 'y' && inputChar != 'N' && inputChar != 'n') {
        cout << "Invalid input. Please enter 'Y' or 'N': ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> inputChar;
    }

    if (inputChar == 'N' || inputChar == 'n') {
        cout << "Enter month (1-12): ";
        cin >> month;

        while (month < 1 || month > 12) {
            cout << "Invalid input. Please enter a month between 1 and 12: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> month;
        }
    }

    cout << "Enter Day: ";
    cin >> day;

    while (day < 1 || day > 31) {
        cout << "Invalid input. Please enter a day between 1 and 31: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> day;
    }

    cout << "Pickup Hour (0-23): ";
    cin >> hour;

    while (hour < 0 || hour > 23) {
        cout << "Invalid input. Please enter an hour between 0 and 23: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> hour;
    }

    cout << "Pickup Minute (0-59): ";
    cin >> minute;

    while (minute < 0 || minute > 59) {
        cout << "Invalid input. Please enter a minute between 0 and 59: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> minute;
    }

    cout << endl;

    time_t now;
    time(&now);
    timeInfo = *localtime(&now);

    /* Previous months are 'next year', so add +1 to the year */
    if (inputChar == 'N' || inputChar == 'n') {
        if (month < timeInfo.tm_mon + 1) {
            timeInfo.tm_year++;
        }
        timeInfo.tm_mon = month - 1;
    }

    timeInfo.tm_mday = day;
    timeInfo.tm_hour = hour;
    timeInfo.tm_min = minute;
    timeInfo.tm_sec = 0;
    timeInfo.tm_isdst = -1;

    userTime = mktime(&timeInfo);

    this->rides.push_back(newRide);

    passenger.addRide(newRide);

    newRide.writeRideProperties(fout);

    cout << "Ride Added" << endl;
    cout << endl;
    fout.flush();
}
