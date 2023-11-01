
#include <sstream>
#include "Passenger.h"

using namespace std;


Passenger::~Passenger() = default;

Passenger::Passenger() = default;


void Passenger::readPassengerProperties(string &readingLine) {
    istringstream dataStream(readingLine);
    string temp;

    getline(dataStream, temp, ',');
    {
    };
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
        this->id = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        this->requiredRating = stof(temp);
    };
    getline(dataStream, temp, ',');
    {
        this->hasPets = (temp == "true");
    };
    getline(dataStream, temp, ',');
    {
        this->paymentPreference = static_cast<PaymentPreference>(stoi(temp));
    };
    getline(dataStream, temp, ',');
    {
        this->password = temp;
    }

    getline(dataStream, temp, '\n');
    cout << "Temp " << temp << endl;


    string rideId;
    char currentChar;

    for (char i: temp) {
        currentChar = i;
        if (currentChar != ',') {
            rideId.push_back(currentChar);
        } else {
            this->rideIds.push_back(stoi(rideId));
            rideId = "";
        }
    };
    cout << "RideIDs size " << this->rideIds.size() << endl;

}

void Passenger::writePassengerProperties(ostream &dataFile) {
    dataFile << "Passenger,";
    dataFile << firstName << ",";
    dataFile << lastName << ",";
    dataFile << id << ",";
    dataFile << requiredRating << ",";
    dataFile << (hasPets ? "true" : "false") << ",";
    dataFile << static_cast<int>(paymentPreference) << ",";
    dataFile << password << ",";
    for (auto &ride: rides) {
        dataFile << ride.id << ",";
    };
}

void Passenger::addRide(const Ride &ride) {
    rides.push_back(ride);
}

void Passenger::getInfo() const {

}

void Passenger::deleteCancelledAndCompletedRides() {

}

float Passenger::getRequiredRating() const {
    return requiredRating;
}

void Passenger::setRequiredRating(float rating) {

}

bool Passenger::getHasPets() const {
    return hasPets;
}

void Passenger::setHasPets() {

}

Passenger::PaymentPreference Passenger::getPaymentPreference() const {
    return paymentPreference;
}

void Passenger::setPaymentPreference(Passenger::PaymentPreference pref) {

}

int Passenger::getId() const {
    return id;
}

void Passenger::setId(int id) {

}

string Passenger::getFirstName() const {
    return firstName;
}

void Passenger::setFirstName(const string &first) {

}

string Passenger::getLastName() const {
    return lastName;
}

void Passenger::setLastName(const string &last) {

}

void Passenger::getRides() const {

}

void Passenger::cancelRide() {

}


void Passenger::rateRide() {
    float flo;
    int i;
    for (const Ride &ride: rides) {
        cout << ride.pickupLocation << "-> " << ride.dropOffLocation << endl;
        cout << ride.id << endl;
    }

    cout << "Enter Ride ID: " << endl;
    cin >> i;

    for (Ride ride: rides) {
        if (i == ride.id) {
            cout << "Enter Rating: " << endl;
            cin >> flo;
            ride.setRating(flo);
        }
    }


}


void Passenger::editRide() {

    for (const Ride &ride: rides) {
        cout << ride.pickupLocation << "-> " << ride.dropOffLocation << endl;
        cout << ride.id << endl;
    }

    cout << "Enter Ride ID: " << endl;
    int i;
    string str;
    char option;
    cin >> i;

    for (Ride &ride: rides) {
        if (ride.id == i) {
            while (true) {

                cout << "*************************************" << endl;
                cout << "               Ride Edit             " << endl;
                cout << "*************************************" << endl;
                cout << "** A: Size of Party: " << ride.sizeOfParty << "**" << endl;
                cout << "** B: Including Pets: " << ride.includesPets << "**" << endl;
                cout << "** C: Pickup Location: " << ride.pickupLocation << "**" << endl;
                cout << "** D: Drop Off Location: " << ride.dropOffLocation << "**" << endl;
                cout << "** F: Pickup Time: " << ride.pickupTime << "**" << endl;
                cout << "** G: Handicaped: " << ride.handicapable << "**" << endl;
                switch (option) {

                    case 'A': // Size of Party
                    case 'a':
                        cout << "Enter Size of Party: " << endl;
                        cin >> i;
                        ride.sizeOfParty = i;
                        break;

                    case 'B': // Including Pets
                    case 'b':
                        cout << "Toggling Including Pets: " << endl;
                        ride.setIncludesPets();
                        break;

                    case 'C': // Pickup Location
                    case 'c':
                        cout << "Enter Pickup Location: " << endl;
                        cin >> str;
                        ride.pickupLocation = str;
                        break;

                    case 'D': // Drop Off Location
                    case 'd':
                        cout << "Enter Drop Off Location: " << endl;
                        cin >> str;
                        ride.dropOffLocation = str;
                        break;

                    case 'F': // Pickup Time
                    case 'f':
                        ride.setPickupTime();
                        break;

                    case 'G': // Handicaped
                    case 'g':
                        cout << "Toggling Handicapable: " << endl;
                        ride.setHandicapped();

                    default:
                        cout << "Invalid Option, please try again." << endl;
                        cin >> option;
                }
                break;
            }
        }
    }
}

void Passenger::editInfo() {
    char option;
    float flo;
    int i;
    string str;


    cout << "*************************************" << endl;
    cout << "         Passenger Edit Menu        " << endl;
    cout << "*************************************" << endl;
    cout << "What would you like to edit?" << endl;
    cout << "A: Required Rating : " << this->getRequiredRating() << endl;
    cout << "C: Pets Allowed : " << this->getHasPets() << endl;
    cout << "D: First Name : " << this->getFirstName() << endl;
    cout << "E: Last Name : " << this->getLastName() << endl;
    cout << "F: Payment Type : " << static_cast<int>(this->getPaymentPreference()) << endl;

    cin >> option;


    switch (option) {
        case 'A':
            cout << "New Required Rating: " << endl;
            cin >> flo;
            this->setRequiredRating(flo);
            break;

        case 'C':
            cout << "New pet policy: " << endl;
            this->setHasPets();
            break;

        case 'D':

            cout << "New first name: " << endl;
            cin >> str;
            this->setFirstName(str);

            break;

        case 'E':
            cout << "New Last Name: " << endl;
            cin >> str;
            this->setLastName(str);
            break;

        case 'F':
            cout << "New Payment Method (1-3): " << endl;
            cin >> i;
            this->setPaymentPreference(
                    static_cast<Passenger::PaymentPreference>(i));
            break;

        case 'Q':
            cout << "Quitting Edit Menu" << endl;
            break;

        default:
            cout << "Invalid option, try again." << endl;
    }

}


