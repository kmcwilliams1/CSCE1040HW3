

#include <limits>
#include <sstream>
#include "Ride.h"


Ride::Ride() = default;

Ride::~Ride() = default;


int Ride::getSizeOfParty() const {
    return sizeOfParty;
}

void Ride::setSizeOfParty(int partySize) {

}

bool Ride::getIncludesPets() const {
    return includesPets;
}

void Ride::setIncludesPets() {

}

Ride::RideStatus Ride::getStatus() const {
    return rideStatus;
}

void Ride::setStatus(Ride::RideStatus status) {

}

float Ride::getRating() const {
    return rating;
}

void Ride::setRating(float rideRating) {

}

int Ride::getId() const {
    return id;
}

void Ride::setId(int rideId) {

}

string Ride::getPickupLocation() const {
    return pickupLocation;
}

void Ride::setPickupLocation(const string &location) {

}

string Ride::getDropOffLocation() const {
    return dropOffLocation;
}

void Ride::setDropOffLocation(const string &location) {

}

string Ride::getPickupTime() const {
    struct tm *timeInfo;
    timeInfo = localtime(&pickupTime);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeInfo);
    return buffer;
};

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
    this->pickupTime = userTime;
}

time_t Ride::getDropOffTime() const {
    return dropOffTime;
}

void Ride::setDropOffTime(time_t time) {

}

const string &Ride::getNote() const {
    return note;
}

void Ride::setNote(const string &note) {

}

bool Ride::getHandicapped() const {
    return handicapable;
}

void Ride::setHandicapped() {
    handicapable = !handicapable;
}

void Ride::readRideProperties(string basicString) {
    istringstream dataStream(basicString);
    string temp;

    getline(dataStream, temp, ',');
    {
    };
    getline(dataStream, temp, ',');
        if (temp == "12") {
            this->rideStatus = RideStatus::Active;
        } else if (temp == "13") {
            this->rideStatus = RideStatus::Completed;
        } else {
            this->rideStatus = RideStatus::Cancelled;
        }
    getline(dataStream, temp, ',');
    {
        this->sizeOfParty = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        this->pickupLocation = temp;
    };
    getline(dataStream, temp, ',');
    {
        this->dropOffLocation = temp;
    };
    getline(dataStream, temp, ',');
    {
        this->pickupTime = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        this->note = temp;
    };
    getline(dataStream, temp, ',');
    {
        temp == "1" ? this->handicapable = true : this->handicapable = false;
    };
    getline(dataStream, temp, ',');
    {
        temp == "1" ? this->includesPets = true : this->includesPets = false;
    };
    getline(dataStream, temp, ',');
    {
        this->id = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        this->assignedPassengerId = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        this->assignedDriverId = stoi(temp);
    };
}


void Ride::writeRideProperties(ostream &dataFile) const {
    dataFile << "Ride,";
    dataFile << static_cast<int>(rideStatus) << ",";
    dataFile << sizeOfParty << ",";
    dataFile << pickupLocation << ",";
    dataFile << dropOffLocation << ",";
    dataFile << pickupTime << ",";
    dataFile << note << ",";
    dataFile << (handicapable ? "1" : "0") << ","; // Convert to "1" or "0"
    dataFile << (includesPets ? "1" : "0") << ","; // Convert to "1" or "0"
    dataFile << id << ",";
    dataFile << assignedPassengerId << ",";
    dataFile << assignedDriverId<< ",\n" << endl;
}

int Ride::getAssignedDriverId() const {
    return assignedDriverId;
}

void Ride::setAssignedDriverId() {

}

int Ride::getAssignedPassengerId() const {
    return assignedPassengerId;
}

void Ride::setAssignedPassengerId() {

}



