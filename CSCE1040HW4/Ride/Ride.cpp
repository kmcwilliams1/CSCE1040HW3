
#include <limits>
#include <iostream>
#include <ctime>
#include <random>
#include "Ride.h"


Ride::Ride() = default;

Ride::~Ride() = default;


int Ride::getSizeOfParty() const {
    return sizeOfParty;
}

void Ride::setSizeOfParty(int partySize) {
    sizeOfParty = partySize;
}

bool Ride::getIncludesPets() const {
    return includesPets;
}

void Ride::setIncludesPets() {
        includesPets = !includesPets;
}

Ride::RideStatus Ride::getStatus() const {
    return rideStatus;
}

void Ride::setStatus(Ride::RideStatus newStatus) {
    rideStatus = newStatus;
}

float Ride::getRating() const {
    return rating;
}

void Ride::setRating(float rideRating) {
    rating = rideRating;
}

int Ride::getId() const {
    return id;
}

void Ride::setId() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 20000);
    int random_number = distribution(generator);
    id = random_number;
}

string Ride::getPickupLocation() const {
    return pickupLocation;
}

void Ride::setPickupLocation(const string &location) {
    pickupLocation = location;
}

string Ride::getDropOffLocation() const {
    return dropOffLocation;
}

void Ride::setDropOffLocation(const string &location) {
    dropOffLocation = location;
}

string Ride::getPickupTime() const {
    struct tm *timeInfo;
    timeInfo = localtime(&pickupTime);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeInfo);
    return buffer;
}

void Ride::setPickupTime() {
    //time
    struct tm timeInfo{};
    time_t userTime;
    int month, day, hour, minute;
    char inputChar;

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
    pickupTime = userTime;
}

string Ride::getDropOffTime() const {
    struct tm *timeInfo;
    timeInfo = localtime(&dropOffTime);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeInfo);
    return buffer;
}

void Ride::setDropOffTime()  {
    //time
    struct tm timeInfo{};
    time_t userTime;
    int month, day, hour, minute;
    char inputChar;

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

    cout << "Dropoff Hour (0-23): ";
    cin >> hour;

    while (hour < 0 || hour > 23) {
        cout << "Invalid input. Please enter an hour between 0 and 23: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> hour;
    }

    cout << "Dropoff Minute (0-59): ";
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
    dropOffTime = userTime;
}


const string &Ride::getNote() const {
    return note;
}

void Ride::setNote(const string &newNote) {
    note = newNote;
}

bool Ride::getHandicapped() const {
    return handicapable;
}

void Ride::setHandicapped() {
    handicapable = !handicapable;
}




void Ride::writeRideProperties(ostream &dataFile) const {
    dataFile << "Ride,";
    dataFile << static_cast<int>(rideStatus) << ",";

    dataFile << sizeOfParty << ",";

    dataFile << pickupLocation << ",";

    dataFile << dropOffLocation << ",";

    dataFile << pickupTime << ",";

    dataFile << note << ",";

    dataFile << (handicapable ? "1" : "0") << ",";

    dataFile << (includesPets ? "1" : "0") << ",";

    dataFile << id << ",";

    dataFile << assignedPassengerId << ",";

    dataFile << assignedDriverId<< ",";

    dataFile << rating<< "," << endl;
}

int Ride::getAssignedDriverId() const {
    return assignedDriverId;
}

void Ride::setAssignedDriverId(int driverId) {
    assignedDriverId = driverId;
}

int Ride::getAssignedPassengerId() const {
    return assignedPassengerId;
}

void Ride::setAssignedPassengerId(int passengerId) {
    assignedPassengerId = passengerId;
}



