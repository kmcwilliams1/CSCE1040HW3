
#ifndef CSCE1040HW4_GROUPDRIVER_H
#define CSCE1040HW4_GROUPDRIVER_H


#include "../Driver.h"


class GroupDriver : public Driver {
public:
    GroupDriver();
    ~GroupDriver();

    int vehicleCapacity;
    string cargoCapacity;

    void addGroupParameters();
    void readGroupProperties(const string &basicString);

    int getVehicleCapacity() const { return vehicleCapacity; };
    void setVehicleCapacity(int capacity);

    string getCargoCapacity() const { return cargoCapacity;};
    void setCargoCapacity(const string &cargo);


};


#endif //CSCE1040HW4_GROUPDRIVER_H
