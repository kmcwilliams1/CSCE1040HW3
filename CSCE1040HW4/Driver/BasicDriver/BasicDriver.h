

#ifndef CSCE1040HW4_BASICDRIVER_H
#define CSCE1040HW4_BASICDRIVER_H

#include "../Driver.h"

class BasicDriver : public Driver {

public:
    BasicDriver();
    ~BasicDriver();


    int vehicleCapacity;
    string cargoCapacity;
    vector<string>amenities;

    void addBasicParameters();


    int getVehicleCapacity() const { return vehicleCapacity; };
    void setVehicleCapacity();


    string getCargoCapacity() const { return cargoCapacity;};
    void setCargoCapacity();

    vector<string> getAmenities() const { return amenities; };
    void setAmenities();
};


#endif //CSCE1040HW4_BASICDRIVER_H
