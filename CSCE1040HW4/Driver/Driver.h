
#ifndef CSCE1040HW4_DRIVER_H
#define CSCE1040HW4_DRIVER_H

#include <iostream>
#include <vector>
#include "../Ride/Ride.h"

using namespace std;


class Driver {

public:
    Driver();
    ~Driver();


    //variables
    enum class VehicleType {
        BasicDriver = 1,
        EconomyDriver,
        GroupDriver,
        LuxuryDriver,
        Other
    };
    int vehicleCapacity{};
    bool handicappedCapable{};
    VehicleType vehicleType{};
    float driverRating{};
    bool petsAllowed{};
    bool available{};
    int id{};
    string firstName;
    string lastName;
    vector<int> rideIds;
    vector<Ride> rides;
    string password;


    //methods
    void writeDriverProperties(ostream &dataFile);
    void readDriverProperties(const string &basicString);

    void addNewRide(Ride *ride);
    void getSchedule();
    void getInfo();
    void deleteCancelledAndCompletedRides();




    //getters and setters
    int getVehicleCapacity() const;
    void setVehicleCapacity(int capacity);

    bool isHandicappedCapable() const;
    void setHandicappedCapable();

    void setVehicleType(VehicleType type);
    VehicleType getVehicleType() const;

    float getDriverRating() const;
    void setDriverRating(float rating);

    bool isPetsAllowed() const;
    void setPetsAllowed();

    bool isAvailable() const;
    void setAvailable();

    int getId() const;
    void setId(int newId);

    const string &getFirstName() const;
    void setFirstName(const string &first);

    const string &getLastName() const;
    void setLastName(const string &last);

    void getCompletedRides() const;
    void setCompletedRides();

    void getCancelledRides() const;
    void setCancelledRides();

    const vector<Ride> &getRides() const;

    const string &getPassword() const;
    void setPassword(const string &pass);

    void editInfo();
};


#endif //CSCE1040HW4_DRIVER_H
