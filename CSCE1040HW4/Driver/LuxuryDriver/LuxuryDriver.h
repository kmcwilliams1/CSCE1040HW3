
#ifndef CSCE1040HW4_LUXURYDRIVER_H
#define CSCE1040HW4_LUXURYDRIVER_H


#include "../Driver.h"

class LuxuryDriver : public Driver {
public:

    LuxuryDriver();
    ~LuxuryDriver();



    int vehicleCapacity;
    string cargoCapacity;
    vector<string>amenities;


    void addLuxuryParameters();


    int getVehicleCapacity() const { return vehicleCapacity; };
    void setVehicleCapacity();

    string getCargoCapacity() const { return cargoCapacity;};
    void setCargoCapacity();

    vector<string> getAmenities() const { return amenities; };
    void setAmenities();


};


#endif //CSCE1040HW4_LUXURYDRIVER_H
