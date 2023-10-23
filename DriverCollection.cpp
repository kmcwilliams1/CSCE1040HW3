#include "DriverCollection.h"
#include "Driver.h"
#include "RideCollection.h"
#include "Ride.h"

DriverCollection::DriverCollection() {
    // Constructor implementation
}

DriverCollection::~DriverCollection() {
    // Destructor implementation
}

void DriverCollection::getDriver(const Driver& driver) const {
    // Implementation of getDriver
}

Driver* DriverCollection::addDriver(int vehicleCapacity, bool handicappedCapable, Driver::VehicleType vehicleType, bool petsAllowed, const std::string& firstName, const std::string& lastName) {
    Driver* driver = new Driver(vehicleCapacity, handicappedCapable, vehicleType, petsAllowed, firstName, lastName); // Initialize the driver
    drivers.push_back(*driver);
    return driver;
}

Driver *DriverCollection::addDriver(Driver driver) {
    return nullptr;
}

