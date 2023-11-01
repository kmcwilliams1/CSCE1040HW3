
#include "Passenger.h"

using namespace std;


Passenger::~Passenger() = default;

Passenger::Passenger() = default;


void Passenger::readPassengerProperties(string &readingLine) {

}

void Passenger::writePassengerProperties(ostream &dataFile) {

}

void Passenger::addRide(Ride ride) {


    ride.assignedPassengerId = this->id;

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
                cout << "*********** Ride Edit ***************" << endl;
                cout << "** A: Size of Party: " << ride.sizeOfParty << "**" << endl;
                cout << "** B: Including Pets: " << ride.includesPets << "**" << endl;
                cout << "** C: Pickup Location: " << ride.pickupLocation << "**" << endl;
                cout << "** D: Drop Off Location: " << ride.dropOffLocation << "**" << endl;
                cout << "** F: Pickup Time: " << ride.pickupTime << "**" << endl;
                cout << "** G: Handicaped: " << ride.handicapable << "**" << endl;
                cout << "*********************************************" << endl;
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

}


