#include <iostream>
#include <string>

class Driver {
public:
    std::string firstName;
    std::string lastName;

    Driver(const std::string& first, const std::string& last)
            : firstName(first), lastName(last) {}

    virtual void displayInfo() const = 0; // Pure virtual function
    virtual ~Driver() {} // Virtual destructor
};

class Luxury : public Driver {
public:
    int seatCapacity;

    Luxury(const std::string& first, const std::string& last, int seats)
            : Driver(first, last), seatCapacity(seats) {}

    void displayInfo() const override {
        std::cout << "Luxury Driver: " << firstName << " " << lastName
                  << ", Seat Capacity: " << seatCapacity << std::endl;
    }
};

class Basic : public Driver {
public:
    int cargoCapacity;

    Basic(const std::string& first, const std::string& last, int cargo)
            : Driver(first, last), cargoCapacity(cargo) {}

    void displayInfo() const override {
        std::cout << "Basic Driver: " << firstName << " " << lastName
                  << ", Cargo Capacity: " << cargoCapacity << std::endl;
    }
};

void updateDriver(Driver*& driver) {
    std::string type;
    std::cout << "Enter new vehicle type (Luxury/Basic): ";
    std::cin >> type;

    if (type == "Luxury") {
        int seats;
        std::cout << "Enter seat capacity: ";
        std::cin >> seats;
        delete driver;
        driver = new Luxury(driver->firstName, driver->lastName, seats);
    } else if (type == "Basic") {
        int cargo;
        std::cout << "Enter cargo capacity: ";
        std::cin >> cargo;
        delete driver;
        driver = new Basic(driver->firstName, driver->lastName, cargo);
    } else {
        std::cout << "Invalid vehicle type!" << std::endl;
    }
}

int main() {
    std::string firstName, lastName;
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;

    Driver* driver = nullptr;

    std::string vehicleType;
    std::cout << "Enter vehicle type (Luxury/Basic): ";
    std::cin >> vehicleType;

    if (vehicleType == "Luxury") {
        int seats;
        std::cout << "Enter seat capacity: ";
        std::cin >> seats;
        driver = new Luxury(firstName, lastName, seats);
    } else if (vehicleType == "Basic") {
        int cargo;
        std::cout << "Enter cargo capacity: ";
        std::cin >> cargo;
        driver = new Basic(firstName, lastName, cargo);
    } else {
        std::cout << "Invalid vehicle type!" << std::endl;
        return 1;
    }

    driver->displayInfo();

    // Offer a way to toggle vehicle types
    updateDriver(driver);

    // Display updated driver information
    driver->displayInfo();

    // Clean up allocated memory
    delete driver;

    return 0;
}
