#include "Passenger.h"
#include "RideCollection.h"
#include "Ride.h"

Passenger::Passenger(const string &first, const string &last, float rating,
                     bool pets, PaymentPreference paymentPref, bool isHandicapped)
        : requiredRating(rating), hasPets(pets), paymentPreference(paymentPref),
          handicapped(isHandicapped), firstName(first), lastName(last) {
}

Passenger::Passenger() {

}

Passenger::~Passenger() {
    rides.clear();
}

float Passenger::getRequiredRating() const {
    return requiredRating;
}

void Passenger::setRequiredRating(float rating) {
    requiredRating = rating;
}

bool Passenger::getHasPets() const {
    return hasPets;
}

void Passenger::setHasPets() {
    hasPets = !hasPets;
}

Passenger::PaymentPreference Passenger::getPaymentPreference() const {
    return paymentPreference;
}

void Passenger::setPaymentPreference(PaymentPreference pref) {
    paymentPreference = pref;
}

bool Passenger::getHandicapped() const {
    return handicapped;
}

void Passenger::setHandicapped() {
    handicapped = !handicapped;
}

string Passenger::getFirstName() const {
    return firstName;
}

void Passenger::setFirstName(const string &first) {
    firstName = first;
}

string Passenger::getLastName() const {
    return lastName;
}

void Passenger::setLastName(const string &last) {
    lastName = last;
}


void Passenger::printRides() const {

    if (!rides.empty()) {
        cout << " Rides:" << endl;
        for (const Ride ride: rides) {
            cout << "Pickup Location: " << ride.getPickupLocation() << endl;
            cout << "Drop-Off Location: " << ride.getDropOffLocation() << endl;
            cout << "Pickup Time: " << ride.getPickupTime() << endl;
            cout << "Status: ";
            switch (ride.getStatus()) {
                case Ride::RideStatus::Active:
                    cout << "Active" << endl;
                    break;
                case Ride::RideStatus::Completed:
                    cout << "Completed" << endl;
                    break;
                case Ride::RideStatus::Cancelled:
                    cout << "Cancelled" << endl;
                    break;
            }
            cout << "---------------------------------------" << endl;
        }
    } else {
        cout << "No rides available for this passenger." << endl;
    }
}


void Passenger::deleteCancelledAndCompletedRides() const {

}

void Passenger::printPassenger() const {
    cout << "Passenger Information:" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Required Rating: " << requiredRating << endl;
    cout << "Has Pets: " << (hasPets ? "Yes" : "No") << endl;
    cout << "Payment Preference: ";
    switch (paymentPreference) {
        case PaymentPreference::Cash:
            cout << "Cash" << endl;
            break;
        case PaymentPreference::Credit:
            cout << "Credit" << endl;
            break;
        case PaymentPreference::Debit:
            cout << "Debit" << endl;
            break;
    }
    cout << "Handicapped: " << (handicapped ? "Yes" : "No") << endl;

}

void Passenger::addRide(Ride ride) {
    rides.push_back(ride);
}


