#ifndef INC_1040HOMEWORK_PASSENGER_H
#define INC_1040HOMEWORK_PASSENGER_H

#include <iostream>
#include <string>
#include <vector>
#include "Ride.h"

using namespace std;

class Passenger {
public:
    enum class PaymentPreference {
        Cash = 1,
        Credit,
        Debit
    };

    Passenger(int passengerId, const string& first, const string& last, float rating,
              bool pets, PaymentPreference paymentPref, bool isHandicapped);
    Passenger();
    ~Passenger();

    float getRequiredRating() const;
    void setRequiredRating(float rating);

    bool getHasPets() const;
    void setHasPets(bool pets);

    PaymentPreference getPaymentPreference() const;
    void setPaymentPreference(PaymentPreference pref);

    bool getHandicapped() const;
    void setHandicapped(bool isHandicapped);

    string getFirstName() const;
    void setFirstName(const string& first);

    string getLastName() const;
    void setLastName(const string& last);

    int getId() const;
    void setId(int passengerId);

    void printRides() const;
    void deleteCancelledAndCompletedRides() const;
    void printPassenger() const;
    void printPassengerRides() const;

private:
    float requiredRating;
    bool hasPets;
    PaymentPreference paymentPreference;
    bool handicapped;
    string firstName;
    string lastName;
    int id;
    vector<Ride*> rides;
};

#endif // INC_1040HOMEWORK_PASSENGER_H
