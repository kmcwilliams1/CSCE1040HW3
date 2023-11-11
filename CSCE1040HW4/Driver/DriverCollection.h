

#ifndef CSCE1040HW4_DRIVERCOLLECTION_H
#define CSCE1040HW4_DRIVERCOLLECTION_H


#include "Driver.h"

class DriverCollection {

public:
    Driver * addDriver();
    vector<Driver*> drivers;

    void removeDriver(Driver& driver);
    void replaceDriver(Driver* oldDriver, Driver* newDriver);

    Driver *updateVehicleType(Driver *driver);
};


#endif //CSCE1040HW4_DRIVERCOLLECTION_H
