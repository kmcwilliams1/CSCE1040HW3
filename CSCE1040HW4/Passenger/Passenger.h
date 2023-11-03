

#ifndef CSCE1040HW4_PASSENGER_H
#define CSCE1040HW4_PASSENGER_H


#include <iostream>
#include <vector>
#include "../Ride/Ride.h"
#include "../Ride/RideCollection.h"

using namespace std;

class Passenger {

public:
    Passenger();
    ~Passenger();


    //variables
    enum class PaymentPreference {
        Cash = 1,
        Credit,
        Debit
    };

    float requiredRating{};
    bool hasPets{};
    PaymentPreference paymentPreference{};
    string firstName;
    string lastName;
    int id{};
    string password;
    vector<int> rideIds;
    vector<Ride> rides;


    //methods
    void addRide(const Ride& ride);
    void readPassengerProperties(string &readingLine);
    void writePassengerProperties(ostream& dataFile);
    void getInfo() const;
    void deleteCancelledAndCompletedRides();
    void getRides() const;
    void cancelRide();
    void rateRide();


    //getters and setters
    float getRequiredRating() const;
    void setRequiredRating(float rating);

    bool getHasPets() const;
    void setHasPets();

    PaymentPreference getPaymentPreference() const;
    void setPaymentPreference(PaymentPreference pref);

    int getId() const;
    void setId();

    string getFirstName() const;
    void setFirstName(const string& first);

    string getLastName() const;
    void setLastName(const string& last);


    void editRide();

    void editInfo();
};


#endif //CSCE1040HW4_PASSENGER_H
