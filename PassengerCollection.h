#ifndef INC_1040HOMEWORK_PASSENGERCOLLECTION_H
#define INC_1040HOMEWORK_PASSENGERCOLLECTION_H

#include <vector>
#include "Passenger.h"

using namespace std;

class PassengerCollection {
public:


    PassengerCollection();
    ~PassengerCollection();

    void getPassenger() const;
    Passenger* addPassenger(int id, const string& firstName, const string& lastName, float rating,
                            bool hasPets, Passenger::PaymentPreference paymentPreference, bool handicapped);
    void updatePassenger(int id, const string& firstName, const string& lastName, float rating,
                         bool hasPets, Passenger::PaymentPreference paymentPreference, bool handicapped);
    void deleteCancelledAndCompletedRides(int id) const;
    void printPassenger(int id) const;
    void printPassengerRides(int id) const;

private:
    vector<Passenger> passengers;
};

#endif // INC_1040HOMEWORK_PASSENGERCOLLECTION_H
