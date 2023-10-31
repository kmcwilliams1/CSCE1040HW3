

#include "PassengerCollection.h"

void PassengerCollection::addPassenger() {

}

void PassengerCollection::deletePassenger(const Passenger& passenger) {
    for (auto it = passengers.begin(); it != passengers.end(); ) {
        if (passenger.id == it->id) {
            it = passengers.erase(it);
        } else {
            ++it;
        }
    }
}
