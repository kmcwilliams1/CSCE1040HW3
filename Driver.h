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
    std::string notes;
    int id;
    std::string firstName;
    std::string lastName;
    int completedRides;
    int canceledRides;
    std::vector<Ride*> rides;

    Driver(int capacity, bool handicapped, VehicleType vType, bool pets, string fName, string lName);

    int getId() const;
    void setId(int newId);
    float getDriverRating() const;
    void setDriverRating(float rating);
    bool isAvailable() const;
    void setAvailable(bool status);
    void addNewRide(Ride* ride);
    void addCompletedRide( Ride* ride);
    void addCancelledRide( Ride* ride);
    int getCompletedRides() const;
    int getCancelledRides() const;
    float updateDriverRating( float driverRating);
    bool toggleAvailability();
    void getSchedule();
    void deleteCancelledAndCompletedRides() const;


    // Getter and setter methods
    int getVehicleCapacity() const;
    void setVehicleCapacity(int capacity);
    bool isHandicappedCapable() const;
    void setHandicappedCapable();
    VehicleType getVehicleType() const;
    void setVehicleType(VehicleType type);
    bool isPetsAllowed() const;
    void setPetsAllowed();
    const std::string& getNotes() const;
    void setNotes(const std::string& driverNotes);
    const std::string& getFirstName() const;
    void setFirstName(const std::string& first);
    const std::string& getLastName() const;
    void setLastName(const std::string& last);
    void printDriver() const;

};

#endif // DRIVER_H
