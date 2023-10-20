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
    char option;
    cout << "********************************" << endl;
    cout << "Enter Selection G: "<< endl;
    cin >> option;
    while (option != 'q') {
        switch (option) {

            case 'a':
                cout << "Get Schedule: a" << endl;
                //TODO passenger needs to do DriverCollection.addNewRide first
                driver->getSchedule();
                break;

            case 'r':
                cout << "Toggle Availability: r" << endl;
                cout << "Current Availability: " << driver->isAvailable() << endl;
                driver->toggleAvailability();
                cout << "Now: " << driver->isAvailable() << endl;

                break;

            case 'b':
                cout << "Get Notes: b" << endl;
                driver->getNotes();
                break;

            case 'f':
                cout << "Finish Ride: f" << endl;
                cout << "Was the ride Successful?: Y/N" << endl;
                cin >> option;
                //TODO currentRide is the current Ride, only 1 is allowed for Driver/Passenger anyway, so create it and then destroy it at certain places
                //option == 'Y' ? driver->addCompletedRide(currentRide) : driver->addCancelledRide(currentRide);


            case 'c':
                cout << "Get rides: C" << endl;
                cout << "Completed rides: A" << endl;
                cout << "Cancelled rides: B" << endl;
                cin >> option;
                option == 'A' ? driver->getCompletedRides() : driver->getCancelledRides();

                break;

            case 'd':
                cout << "Get Your Rating: D" << endl;
                driver->getDriverRating();
                break;

            case 'g':
                cout << "Get Your Information: G" << endl;
                 driver->printDriver();
                break;


            case 'E':
                cout << "Edit Car information: E" << endl;
                cout << "What would you like to edit?" << endl;
                cout << "A: Vehicle Capacity : " << driver->getVehicleCapacity() << endl;
                cout << "B: Handicapped Capable: " << driver->isHandicappedCapable() << endl;
                cout << "C: Pets Allowed : " << driver->isPetsAllowed() << endl;
                cout << "D: First Name : " << driver->getFirstName() << endl;
                cout << "D: Last Name : " << driver->getLastName() << endl;

                //cout << "D: Vehicle Type : " << driver->getVehicleType() << endl;


                char editOption;
                cin >> editOption;
                switch (option) {

                    case 'A':
                        int capacity;
                        cout << "New capacity: " << endl;
                        cin >> capacity;
                        driver->setVehicleCapacity(capacity);
                        break;

//                        bool isHandicappedCapable() const;
//                        void setHandicappedCapable(bool capable);
//
//                        void setVehicleType(Driver::VehicleType type);
//
//                        void setPetsAllowed(bool allowed);
//
//                        void setFirstName(const std::string &first);
//
//                        void setLastName(const std::string &last);


                }


                break;


            case 'q':
                cout << "Logout: Q" << endl;
                break;
        }
        break;
    }


    cout << "End ********************************" << endl;

};

void PassengerMenu( Driver *driver) {
    char option;
    cout << "********************************";
    while (option != 'q') {
        switch (option) {

            case 'a':

                break;

            case 'b':

                break;

            case 'c':

                break;

            case 'd':

                break;


            case 'q':
                cout << "Logout: Q" << endl;
                break;
        }
        break;
    }


    cout << "********************************";

};

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
                cout << "Accessing Menu "<< endl;
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
                delete user.driver;
                delete user.passenger;
                user.driver = nullptr;
                user.passenger = nullptr;
                isLoggedIn = false;
            }
        }
    }

    return 0;
}
