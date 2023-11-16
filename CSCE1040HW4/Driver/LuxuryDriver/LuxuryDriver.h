
#ifndef CSCE1040HW4_LUXURYDRIVER_H
#define CSCE1040HW4_LUXURYDRIVER_H


#include "../Driver.h"

class LuxuryDriver : public Driver {
public:

    LuxuryDriver();
    ~LuxuryDriver();
    std::string getTypeName() const override {
        return "LuxuryDriver";
    }


    int vehicleCapacity{};
    string cargoCapacity;
    vector<string>amenities;


    void addLuxuryParameters();


    int getVehicleCapacity() const { return vehicleCapacity; };
    void setVehicleCapacity(int capacity);

    string getCargoCapacity() const { return cargoCapacity;};
    void setCargoCapacity(const string& cargo);

    vector<string>& getAmenities() { return amenities; };
    void setAmenities(const string& amenity);

    void getInfo() const override;
    void editInfo() override;
};


#endif //CSCE1040HW4_LUXURYDRIVER_H
