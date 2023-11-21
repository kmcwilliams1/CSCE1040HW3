
#ifndef CSCE1040HW4_GROUPDRIVER_H
#define CSCE1040HW4_GROUPDRIVER_H


#include "../Driver.h"


class GroupDriver : public Driver {
public:
    GroupDriver();
    ~GroupDriver();


    int vehicleCapacity;
    string cargoCapacity;
    vector<string>amenities;

    void addGroupParameters();

    int getVehicleCapacity() const { return vehicleCapacity; };
    void setVehicleCapacity();

    string getCargoCapacity() const { return cargoCapacity;};
    void setCargoCapacity();

    vector<string> getAmenities() const { return amenities; };
    void setAmenities();


    void readGroupProperties(const string &basicString);
};


#endif //CSCE1040HW4_GROUPDRIVER_H
