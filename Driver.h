#ifndef INC_1040HOMEWORK_DRIVER_H
#define INC_1040HOMEWORK_DRIVER_H

#include <string>
#include <vector>
#include "Ride.h"

class Driver {
public:
    Driver();
    ~Driver();

    enum class VehicleType {
        Compact2Dr = 1,
        Sedan4Dr,
        SUV,
        Van,
        Other
    };

    int vehicleCapacity;
    bool handicappedCapable;
    VehicleType vehicleType;
    float driverRating;
    bool petsAllowed;
    bool available;
    int id;
    std::string firstName;
    std::string lastName;
    int completedRides;
    int cancelledRides;
    std::vector<Ride> rides;
    string password;

    Driver(int capacity, bool handicapped, VehicleType vType, bool pets, string fName, string lName);

    int getId() const;
    void setId(int newId);
    void setDriverRating(float rating);
    bool isAvailable() const;
    void setAvailable(bool status);
    void addNewRide(Ride* ride);
    void addCompletedRide( );
    void addCancelledRide( );
    int getCompletedRides() const;
    int getCancelledRides() const;
    float updateDriverRating();
    bool toggleAvailability();
    void getSchedule();
    void deleteCancelledAndCompletedRides() ;


    // Getter and setter methods
    int getVehicleCapacity() const;
    void setVehicleCapacity(int capacity);
    bool isHandicappedCapable() const;
    void setHandicappedCapable();
    VehicleType getVehicleType() const;
    void setVehicleType(VehicleType type);
    bool isPetsAllowed() const;
    void setPetsAllowed();
    const std::string& getFirstName() const;
    void setFirstName(const std::string& first);
    const std::string& getLastName() const;
    void setLastName(const std::string& last);
    void printDriver() const;

    void setDriverProperties(const string& basicString);


};

#endif // DRIVER_H
