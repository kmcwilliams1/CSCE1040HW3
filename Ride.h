#ifndef INC_1040HOMEWORK_RIDE_H
#define INC_1040HOMEWORK_RIDE_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Ride {
public:

    //ride unique characteristics
    enum class RideStatus {
        Active = 12,
        Completed,
        Cancelled
    };
    Ride(int sizeOfParty, bool includesPets, string pickupLocation, string dropoffLocation, time_t pickupTime, string note, bool handicapable);
    Ride();
    ~Ride();

    void completeRide();
    void getPickupLocationAndTime() const;

    //setters and getters
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

    string getPickupTime() const;
    void setPickupTime(time_t time);

    time_t getDropOffTime() const;
    void setDropOffTime(time_t time);

    const string& getNote() const;
    void setNote(const string &note);

    bool getHandicapped() const;
    void setHandicapped();



//variables
    int sizeOfParty;
    bool handicapped;
    bool includesPets;
    RideStatus status;
    float rating;
    int id;
    string pickupLocation;
    string dropOffLocation;
    time_t pickupTime;
    time_t dropOffTime;
    string note;
    bool handicapable;
};

#endif // INC_1040HOMEWORK_RIDE_H
