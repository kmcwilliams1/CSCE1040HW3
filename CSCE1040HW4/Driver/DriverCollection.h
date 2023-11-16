

#ifndef CSCE1040HW4_DRIVERCOLLECTION_H
#define CSCE1040HW4_DRIVERCOLLECTION_H


#include "Driver.h"
#include "../Ride/RideCollection.h"

class DriverCollection {

public:
    Driver * addDriver();
    vector<Driver*> drivers;

    void removeDriver(Driver& driver);

    Driver *updateVehicleType(Driver *driver);

    Driver *createDriverOfType(int type);
};


#endif //CSCE1040HW4_DRIVERCOLLECTION_H
