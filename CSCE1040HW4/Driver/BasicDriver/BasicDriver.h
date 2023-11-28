

#ifndef CSCE1040HW4_BASICDRIVER_H
#define CSCE1040HW4_BASICDRIVER_H

#include "../Driver.h"


class EconomyDriver;
class GroupDriver;
class LuxuryDriver;
class BasicDriver : public Driver {

public:
    BasicDriver();
    ~BasicDriver();
    std::string getTypeName() const override {
        return "BasicDriver";
    }

    int vehicleCapacity{};
    string cargoCapacity;

    void addBasicParameters();


    int getVehicleCapacity() const { return vehicleCapacity; };
    void setVehicleCapacity(int capacity);


    string getCargoCapacity() const { return cargoCapacity;};
    void setCargoCapacity(const string &cargo);


    void getInfo() const override;
    void editInfo() override;

    void readBasicProperties(const string &basicString);
    void writeDriverProperties(ostream &ostream) override;
};


#endif //CSCE1040HW4_BASICDRIVER_H
