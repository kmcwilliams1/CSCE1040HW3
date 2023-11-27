
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
    virtual std::string getTypeName() const {
        return "Driver";
    }


    //variables
    enum class VehicleType {
        BasicDriver = 1,
        EconomyDriver,
        GroupDriver,
        LuxuryDriver,
        Other
    };
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
    virtual void writeDriverProperties(ostream &dataFile) ;

    void getSchedule();
    virtual void getInfo() const ;
    virtual void editInfo();
    void deleteCancelledAndCompletedRides();
    void copyPropertiesFrom(const Driver* otherDriver);


    //getters and setters
    bool isHandicappedCapable() const;
    void setHandicappedCapable(bool isHandicappedCapable);

    void setVehicleType(VehicleType type);
    VehicleType getVehicleType() const;

    float getDriverRating() const;
    void setDriverRating(float rating);

    bool isPetsAllowed() const;
    void setPetsAllowed(bool isPetsAllowed);

    bool isAvailable() const;
    void setAvailable(bool isAvailable);

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

    void getRides() const;

    const string &getPassword() const;
    void setPassword(const string &pass);

};


#endif //CSCE1040HW4_DRIVER_H
