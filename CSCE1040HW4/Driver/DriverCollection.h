

#ifndef CSCE1040HW4_DRIVERCOLLECTION_H
#define CSCE1040HW4_DRIVERCOLLECTION_H


#include "Driver.h"
#include "../Ride/RideCollection.h"

class DriverCollection {

public:
    Driver * addDriver();
    vector<Driver*> drivers;

    void removeDriver(Driver& driver);

    void readDriverProperties(const string& basicString);
};


#endif //CSCE1040HW4_DRIVERCOLLECTION_H
