
#ifndef CSCE1040HW4_GROUPDRIVER_H
#define CSCE1040HW4_GROUPDRIVER_H


#include "../Driver.h"

class BasicDriver;
class EconomyDriver;
class LuxuryDriver;
class GroupDriver : public Driver {
public:
    GroupDriver();
    ~GroupDriver();

    int vehicleCapacity{};
    string cargoCapacity;

    void addGroupParameters();
    void readGroupProperties(const string &basicString);

    int getVehicleCapacity() const { return vehicleCapacity; };
    void setVehicleCapacity(int capacity);

    string getCargoCapacity() const { return cargoCapacity;};
    void setCargoCapacity(const string &cargo);


    void getInfo() const override;
    void editInfo() override;

    void writeDriverProperties(ostream &ostream) override;
};


#endif //CSCE1040HW4_GROUPDRIVER_H
