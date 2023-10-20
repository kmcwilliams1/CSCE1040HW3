#include <iostream>
#include <string>
#include <ctime>
#include "Driver.h"
#include "Passenger.h"
#include "DriverCollection.h"
#include "PassengerCollection.h"

using namespace std;

struct User {
    Driver *driver;
    Passenger *passenger;
    string role;
    vector<Ride> passengerRides;
    vector<Ride> driverRides;

    User() : driver(nullptr), passenger(nullptr), role("") {}
};


void DriverMenu(Driver *driver) {

    string newFirstName, newLastName;
    int newVehicleTypeInt = 0;
    Driver::VehicleType newVehicleType = static_cast<Driver::VehicleType>(newVehicleTypeInt);

    while (true) {
        cout << "*************************************" << endl;
        cout << "            Driver Menu" << endl;
        cout << "*************************************" << endl;
        cout << "Enter Selection: " << endl;
        cout << "Get Schedule: a" << endl;
        cout << "Toggle Availability: r" << endl;
        cout << "Current Availability: " << driver->isAvailable() << endl;
        cout << "Get Notes: b" << endl;
        cout << "Get rides: C" << endl;
        cout << "Get Your Rating: D" << endl;
        cout << "Get Your Information: G" << endl;
        cout << "Edit Car information: E" << endl;
        cout << "Delete Account: L" << endl;
        cout << "Logout: Q" << endl;

        char option;
        cin >> option;

        switch (option) {
            case 'a':
                //TODO passenger needs to do DriverCollection.addNewRide first

                driver->getSchedule();
                cout << endl;
                break;

            case 'r':

                cout << "Current Availability: " << driver->isAvailable() << endl;
                driver->toggleAvailability();
                cout << "Now: " << driver->isAvailable() << endl;
                cout << endl;
                break;

            case 'b':

                driver->getNotes();
                cout << endl;
                break;

            case 'f':
                cout << "Finish Ride: f" << endl;
                cout << "Was the ride Successful?: Y/N" << endl;
                cin >> option;
                //TODO currentRide is the current Ride, only 1 is allowed for Driver/Passenger anyway, so create it and then destroy it at certain places
                //option == 'Y' ? driver->addCompletedRide(currentRide) : driver->addCancelledRide(currentRide);
                cout << endl;
                break;

            case 'c':

                cout << "Completed rides: A" << endl;
                cout << "Cancelled rides: B" << endl;
                cin >> option;
                if (option == 'A') {
                    driver->getCompletedRides();
                } else if (option == 'B') {
                    driver->getCancelledRides();
                }
                cout << endl;
                break;

            case 'd':

                driver->getDriverRating();
                cout << endl;
                break;

            case 'g':

                driver->printDriver();
                cout << endl;
                break;

            case 'E':

                cout << "What would you like to edit?" << endl;
                cout << "A: Vehicle Capacity : " << driver->getVehicleCapacity() << endl;
                cout << "B: Handicapped Capable: " << driver->isHandicappedCapable() << endl;
                cout << "C: Pets Allowed : " << driver->isPetsAllowed() << endl;
                cout << "D: First Name : " << driver->getFirstName() << endl;
                cout << "E: Last Name : " << driver->getLastName() << endl;
                cout << "F: Vehicle Type : " << static_cast<int>(driver->getVehicleType()) << endl;

                cin >> option;

                switch (option) {
                    case 'A':
                        int capacity;
                        cout << "New capacity: " << endl;
                        cin >> capacity;
                        driver->setVehicleCapacity(capacity);
                        break;

                    case 'B':
                        cout << "New handicap able: " << endl;
                        driver->setHandicappedCapable();
                        break;

                    case 'C':
                        cout << "New pet policy: " << endl;
                        driver->setPetsAllowed();
                        break;

                    case 'D':

                        cout << "New first name: " << endl;
                        cin >> newFirstName;
                        driver->setFirstName(newFirstName);
                        break;

                    case 'E':

                        cout << "New Last Name: " << endl;
                        cin >> newLastName;
                        driver->setLastName(newLastName);
                        break;

                    case 'F':

                        cout << "New Vehicle Type (1-5): " << endl;
                        cin >> newVehicleTypeInt;
                        driver->setVehicleType(static_cast<Driver::VehicleType>(newVehicleTypeInt));
                        break;

                    case 'Q':
                        cout << "Quitting Driver Menu" << endl;
                        break;

                    default:
                        cout << "Invalid option, try again." << endl;
                }
                cout << endl;
                break;

            case 'q':
                cout << endl;
                return;

            case 'l':
                cout << "Deleting Driver " << driver->getFirstName() << " " << driver->getLastName() << endl;
                delete driver;
                driver = nullptr;
                break;

            default:
                cout << "Invalid option, try again." << endl;
                cin >> option;
        }
    }
}


void PassengerMenu(Driver *driver) {

    string newFirstName, newLastName;
    int newVehicleTypeInt = 0;
    Driver::VehicleType newVehicleType = static_cast<Driver::VehicleType>(newVehicleTypeInt);

    while (true) {
        cout << "*************************************" << endl;
        cout << "            Passenger Menu" << endl;
        cout << "*************************************" << endl;
        cout << "Enter Selection: " << endl;
        cout << "Get Schedule: a" << endl;
        cout << "Toggle Availability: r" << endl;
        cout << "Current Availability: " << driver->isAvailable() << endl;
        cout << "Get Notes: b" << endl;
        cout << "Get rides: C" << endl;
        cout << "Get Your Rating: D" << endl;
        cout << "Get Your Information: G" << endl;
        cout << "Edit Car information: E" << endl;
        cout << "Delete Account: L" << endl;
        cout << "Logout: Q" << endl;

        char option;
        cin >> option;

        switch (option) {
            case 'a':
                //TODO passenger needs to do DriverCollection.addNewRide first

                driver->getSchedule();
                cout << endl;
                break;

            case 'r':

                cout << "Current Availability: " << driver->isAvailable() << endl;
                driver->toggleAvailability();
                cout << "Now: " << driver->isAvailable() << endl;
                cout << endl;
                break;

            case 'b':

                driver->getNotes();
                cout << endl;
                break;

            case 'f':
                cout << "Finish Ride: f" << endl;
                cout << "Was the ride Successful?: Y/N" << endl;
                cin >> option;
                //TODO currentRide is the current Ride, only 1 is allowed for Driver/Passenger anyway, so create it and then destroy it at certain places
                //option == 'Y' ? driver->addCompletedRide(currentRide) : driver->addCancelledRide(currentRide);
                cout << endl;
                break;

            case 'c':

                cout << "Completed rides: A" << endl;
                cout << "Cancelled rides: B" << endl;
                cin >> option;
                if (option == 'A') {
                    driver->getCompletedRides();
                } else if (option == 'B') {
                    driver->getCancelledRides();
                }
                cout << endl;
                break;

            case 'd':

                driver->getDriverRating();
                cout << endl;
                break;

            case 'g':

                driver->printDriver();
                cout << endl;
                break;

            case 'E':

                cout << "What would you like to edit?" << endl;
                cout << "A: Vehicle Capacity : " << driver->getVehicleCapacity() << endl;
                cout << "B: Handicapped Capable: " << driver->isHandicappedCapable() << endl;
                cout << "C: Pets Allowed : " << driver->isPetsAllowed() << endl;
                cout << "D: First Name : " << driver->getFirstName() << endl;
                cout << "E: Last Name : " << driver->getLastName() << endl;
                cout << "F: Vehicle Type : " << static_cast<int>(driver->getVehicleType()) << endl;

                cin >> option;

                switch (option) {
                    case 'A':
                        int capacity;
                        cout << "New capacity: " << endl;
                        cin >> capacity;
                        driver->setVehicleCapacity(capacity);
                        break;

                    case 'B':
                        cout << "New handicap able: " << endl;
                        driver->setHandicappedCapable();
                        break;

                    case 'C':
                        cout << "New pet policy: " << endl;
                        driver->setPetsAllowed();
                        break;

                    case 'D':

                        cout << "New first name: " << endl;
                        cin >> newFirstName;
                        driver->setFirstName(newFirstName);
                        break;

                    case 'E':

                        cout << "New Last Name: " << endl;
                        cin >> newLastName;
                        driver->setLastName(newLastName);
                        break;

                    case 'F':

                        cout << "New Vehicle Type (1-5): " << endl;
                        cin >> newVehicleTypeInt;
                        driver->setVehicleType(static_cast<Driver::VehicleType>(newVehicleTypeInt));
                        break;

                    case 'Q':
                        cout << "Quitting Driver Menu" << endl;
                        break;

                    default:
                        cout << "Invalid option, try again." << endl;
                }
                cout << endl;
                break;

            case 'q':
                cout << endl;
                return;

            case 'l':
                cout << "Deleting Driver " << driver->getFirstName() << " " << driver->getLastName() << endl;
                delete driver;
                driver = nullptr;
                break;

            default:
                cout << "Invalid option, try again." << endl;
                cin >> option;
        }
    }
}

int main() {
    User user;
    DriverCollection driverCollection;
    PassengerCollection passengerCollection;

    bool isLoggedIn = false;

    while (true) {
        if (!isLoggedIn) {
            cout << "Choose your role (Driver/Passenger) or 'exit': ";
            cin >> user.role;

            if (user.role == "exit") {
                break;
            } else if (user.role == "Driver") {
                int vehicleCapacity;
                bool handicappedCapable;
                int vehicleType;
                bool petsAllowed;
                string firstName;
                string lastName;

                cout << "Enter Vehicle Capacity: ";
                cin >> vehicleCapacity;
                cout << "Is Handicapped Capable (1 for true, 0 for false): ";
                cin >> handicappedCapable;
                cout << "Enter Vehicle Type (1 for Compact2Dr, 2 for Sedan4Dr, 3 for SUV, 4 for Van, 5 for Other): ";
                cin >> vehicleType;
                cout << "Are Pets Allowed (1 for true, 0 for false): ";
                cin >> petsAllowed;
                cout << "Enter First Name: ";
                cin >> firstName;
                cout << "Enter Last Name: ";
                cin >> lastName;

                user.driver = driverCollection.addDriver(vehicleCapacity, handicappedCapable,
                                                         static_cast<Driver::VehicleType>(vehicleType), petsAllowed,
                                                         firstName, lastName);
                cout << "Results:  " << user.driver->getFirstName() << endl;
                isLoggedIn = true;
            } else if (user.role == "Passenger") {
                string firstName;
                string lastName;
                float rating;
                bool hasPets;
                int paymentPreference;
                bool handicapped;
                int id = rand() % 1000;

                cout << "Enter First Name: ";
                cin >> firstName;
                cout << "Enter Last Name: ";
                cin >> lastName;
                cout << "Enter Rating: ";
                cin >> rating;
                cout << "Has Pets (1 for true, 0 for false): ";
                cin >> hasPets;
                cout << "Payment Preference (1 for Cash, 2 for Credit, 3 for Debit): ";
                cin >> paymentPreference;
                cout << "Is Handicapped (1 for true, 0 for false): ";
                cin >> handicapped;

                isLoggedIn = true;
            } else {
                cout << "Invalid role. Please try again." << endl;
            }


        } else {
            cout << "Logged in as " << user.role << endl;

            if (user.role == "Driver" && user.driver != nullptr) {
                // Implement driver-specific functionality here
                cout << "Accessing Driver Features for " << user.driver->getFirstName() << " "
                     << user.driver->getLastName() << endl;
                cout << "Accessing Driver Menu " << endl;
                DriverMenu(user.driver);

            } else if (user.role == "Passenger" && user.passenger != nullptr) {
                // Implement passenger-specific functionality here
                cout << "Accessing Passenger Features for " << user.passenger->getFirstName() << " "
                     << user.passenger->getLastName() << endl;


            }

            cout << "Do you want to log out? (yes/no): ";
            string logout;
            cin >> logout;

            if (logout == "yes") {
                isLoggedIn = false;

            }
        }
    }

    return 0;
}
