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

    Passenger(const string& first, const string& last, float rating,
              bool pets, PaymentPreference paymentPref);
    Passenger();
    ~Passenger();

    float getRequiredRating() const;
    void setRequiredRating(float rating);

    bool getHasPets() const;
    void setHasPets();

    PaymentPreference getPaymentPreference() const;
    void setPaymentPreference(PaymentPreference pref);

    int getId() const;
    void setId(int id);

    string getFirstName() const;
    void setFirstName(const string& first);

    string getLastName() const;
    void setLastName(const string& last);

    string getPassword() const;
    void setPassword(const string& password);

    void printRides() const;
    void deleteCancelledAndCompletedRides() ;
    void printPassenger() const;

    void addRide(Ride ride);


    float requiredRating;
    bool hasPets;
    PaymentPreference paymentPreference;
    string firstName;
    string lastName;
    int id;
    string password;
    vector<Ride> rides;

    void setPassengerProperties(string basicString);
};

#endif // INC_1040HOMEWORK_PASSENGER_H
