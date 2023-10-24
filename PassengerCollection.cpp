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
                                             bool hasPets, Passenger::PaymentPreference paymentPreference) {
    Passenger* passenger = new Passenger(firstName, lastName, rating, hasPets, paymentPreference);
    passengers.push_back(*passenger);
    return passenger;
}

Passenger *PassengerCollection::addPassenger(Passenger passenger) {
    passengers.push_back(passenger);
    return nullptr;
}

