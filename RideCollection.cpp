#include "RideCollection.h"
#include <iostream>

RideCollection::RideCollection() {
    // Initialize your RideCollection if needed
}

RideCollection::~RideCollection() {
    // Cleanup any resources if needed
}

void RideCollection::getRides() const {
    if (!rides.empty()) {
        cout << " Rides:" << endl;
        for (const Ride ride : rides) {
            cout << "Pickup Location: " << ride.getPickupLocation() << endl;
            cout << "Drop-Off Location: " << ride.getDropOffLocation() << endl;
            cout << "Pickup Time: " << ride.getPickupTime() << endl;

            string statusString;
            switch (ride.getStatus()) {
                case Ride::RideStatus::Active:
                    statusString = "Active";
                    break;
                case Ride::RideStatus::Completed:
                    statusString = "Completed";
                    break;
                case Ride::RideStatus::Cancelled:
                    statusString = "Cancelled";
                    break;
                default:
                    statusString = "Unknown";
                    break;
            }

            cout << "RideCollection::getRides status: " << statusString << endl;
            cout << "---------------------------------------" << endl;
        }
    } else {
        cout << "No rides available at the moment." << endl;
    }
}




int RideCollection::showActiveRides(RideCollection::RideStatus status) {
    return 0;
}

Ride *RideCollection::addRide(int sizeOfParty, bool includesPets, string pickupLocation, string dropOffLocation,
                              time_t pickupTime, string note, bool handicapable) {
    Ride *ride = new Ride(sizeOfParty, includesPets, pickupLocation, dropOffLocation, pickupTime, note, handicapable);
    ride->setStatus(Ride::RideStatus::Active);
    rides.push_back(*ride);
    return ride;
}

