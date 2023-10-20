#ifndef INC_1040HOMEWORK_DRIVERCOLLECTION_H
#define INC_1040HOMEWORK_DRIVERCOLLECTION_H

#include <vector>
#include "Driver.h"

class DriverCollection {
public:
    DriverCollection();
    ~DriverCollection();

    void getDriver(const Driver& driver) const;
    Driver* addDriver(int vehicleCapacity, bool handicappedCapable, Driver::VehicleType vehicleType, bool petsAllowed, const std::string& firstName, const std::string& lastName);


private:
    std::vector<Driver> drivers;
};

#endif // INC_1040HOMEWORK_DRIVERCOLLECTION_H
