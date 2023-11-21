

#ifndef CSCE1040HW4_ECONOMYDRIVER_H
#define CSCE1040HW4_ECONOMYDRIVER_H


#include "../Driver.h"

class EconomyDriver : public Driver{

public:
    EconomyDriver();
    ~EconomyDriver();



    int vehicleCapacity;
    string cargoCapacity;
    vector<string>amenities;

    void addEconomyParameters();


    int getVehicleCapacity() const { return vehicleCapacity; };
    void setVehicleCapacity();

    string getCargoCapacity() const { return cargoCapacity;};
    void setCargoCapacity();

    vector<string> getAmenities() const { return amenities; };
    void setAmenities();

    void readEconomyProperties(const string &basicString);
};


#endif //CSCE1040HW4_ECONOMYDRIVER_H
