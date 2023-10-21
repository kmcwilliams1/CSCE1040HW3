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
    Passenger* addPassenger(const string& firstName, const string& lastName, float rating,
                            bool hasPets, Passenger::PaymentPreference paymentPreference, bool handicapped);


private:
    vector<Passenger> passengers;
};

#endif // INC_1040HOMEWORK_PASSENGERCOLLECTION_H
