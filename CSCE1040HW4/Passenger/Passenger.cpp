
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


void Passenger::rateRide(const Passenger& passenger) {
    float flo;
    for (const Ride& ride: passenger.rides) {
        cout << ride.pickupLocation << "-> " << ride.dropOffLocation << endl;
        cout << ride.id << endl;
    }

    cout << "Enter Ride ID: " << endl;
    cin >> flo;

    for (Ride ride: passenger.rides) {
        if (flo == ride.id) {
            ride.setRating(flo);
        }
    }


}


