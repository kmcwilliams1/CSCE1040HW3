

#ifndef CSCE1040HW4_ECONOMYDRIVER_H
#define CSCE1040HW4_ECONOMYDRIVER_H


#include "../Driver.h"

class BasicDriver;
class GroupDriver;
class LuxuryDriver;
class EconomyDriver : public Driver{

public:
    EconomyDriver();
    ~EconomyDriver();


    int vehicleCapacity{};
    string cargoCapacity;

    void addEconomyParameters();
    void readEconomyProperties(const string &basicString);

    int getVehicleCapacity() const { return vehicleCapacity; };
    void setVehicleCapacity(int capacity);

    string getCargoCapacity() const { return cargoCapacity;};
    void setCargoCapacity(const string &cargo);


    void getInfo() const;

    void editInfo();
};


#endif //CSCE1040HW4_ECONOMYDRIVER_H
