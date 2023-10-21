#include "PassengerCollection.h"

PassengerCollection::PassengerCollection() {
    // Constructor implementation
}

PassengerCollection::~PassengerCollection() {
    // Destructor implementation
}

void PassengerCollection::getPassenger() const {
    // Implementation of getPassenger
}

Passenger* PassengerCollection::addPassenger(const string& firstName, const string& lastName, float rating,
                                             bool hasPets, Passenger::PaymentPreference paymentPreference, bool handicapped) {
    Passenger* passenger = new Passenger(firstName, lastName, rating, hasPets, paymentPreference, handicapped);
    passengers.push_back(*passenger);
    return passenger;
}

