#ifndef INC_1040HOMEWORK_RIDE_H
#define INC_1040HOMEWORK_RIDE_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Ride {
public:

    enum class RideStatus {
        Active,
        Completed,
        Cancelled
    };
    Ride(int sizeOfParty, bool includesPets, string pickupLocation, string dropoffLocation, time_t pickupTime);
    Ride();
    ~Ride();

    int getSizeOfParty() const;
    void setSizeOfParty(int partySize);

    bool getIncludesPets() const;
    void setIncludesPets(bool pets);

    RideStatus getStatus() const;
    void setStatus(RideStatus rideStatus);

    float getRating() const;
    void setRating(float rideRating);

    int getId() const;
    void setId(int rideId);

    string getPickupLocation() const;
    void setPickupLocation(const string& location);

    string getDropOffLocation() const;
    void setDropOffLocation(const string& location);

    time_t getPickupTime() const;
    void setPickupTime(time_t time);

    time_t getDropOffTime() const;
    void setDropOffTime(time_t time);

    void completeRide();
    void getPickupLocationAndTime() const;


private:
    int sizeOfParty;
    bool includesPets;
    RideStatus status;
    float rating;
    int id;
    string pickupLocation;
    string dropOffLocation;
    time_t pickupTime;
    time_t dropOffTime;
};

#endif // INC_1040HOMEWORK_RIDE_H
