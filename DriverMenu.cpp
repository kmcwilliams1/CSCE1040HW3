#include <iostream>
#include <string>
#include "Driver.h"
#include "RideCollection.h"

using namespace std;

void DriverMenu(Driver driver, RideCollection &rideCollection) {

    string newFirstName, newLastName;
    int newVehicleTypeInt = 0;
    int rideIndex;


    while (true) {
        cout << "*************************************" << endl;
        cout << "            Driver Menu" << endl;
        cout << "*************************************" << endl;
        cout << "Enter Selection: " << endl;
        cout << "Get Current Schedule: A" << endl;
        cout << "Toggle Availability: B" << endl;
        cout << "Current Availability: " << driver.isAvailable() << endl;
        cout << "Get past rides: D" << endl;
        cout << "Get Your Information: E" << endl;
        cout << "Edit Car information: F" << endl;
        cout << "Delete Account: G" << endl;
        cout << "Logout: Q" << endl;

        char option;
        cin >> option;

        switch (option) {
            case 'A':


                for (Ride ride : rideCollection.rides) {
                    if(ride.includesPets && driver.petsAllowed) {
                        if(ride.handicapped && driver.handicappedCapable) {
                            if(ride.sizeOfParty < driver.vehicleCapacity) {
                                if(ride.rating >= driver.driverRating) {
                                    driver.rides.push_back(ride);
                                }
                            }
                        }
                    }
                }

                driver.getSchedule();
                cout << endl;
                break;

            case 'B':

                cout << "Current Availability: " << driver.isAvailable() << endl;
                driver.toggleAvailability();
                cout << "Now: " << driver.isAvailable() << endl;
                cout << endl;
                break;


            case 'D':
                cout << "Which ride number would you like to complete?" << endl;
                driver.getSchedule();
                cin >> option;
                cin >> rideIndex;

                cout << "Was the ride Successful?: Y/N" << endl;
                cin >> option;

                if (rideIndex >= 0 && rideIndex < driver.rides.size()) {
                    driver.rides.erase(driver.rides.begin() + rideIndex);
                    cout << "Ride Cancelled" << endl;
                }

                (option == 'Y' || option == 'y') ? driver.addCompletedRide() : driver.addCancelledRide();
                cout << endl;
                break;


            case 'E':

                cout << "Completed rides: A" << endl;
                cout << "Cancelled rides: B" << endl;
                cin >> option;
                if (option == 'A') {
                    driver.getCompletedRides();
                } else if (option == 'B') {
                    driver.getCancelledRides();
                }
                cout << endl;
                break;

            case 'F':

                driver.printDriver();
                cout << endl;
                break;

            case 'G':

                cout << "What would you like to edit?" << endl;
                cout << "A: Vehicle Capacity : " << driver.getVehicleCapacity() << endl;
                cout << "B: Handicapped Capable: " << driver.isHandicappedCapable() << endl;
                cout << "C: Pets Allowed : " << driver.isPetsAllowed() << endl;
                cout << "D: First Name : " << driver.getFirstName() << endl;
                cout << "E: Last Name : " << driver.getLastName() << endl;
                cout << "F: Vehicle Type : " << static_cast<int>(driver.getVehicleType()) << endl;

                cin >> option;

                switch (option) {
                    case 'A':
                        int capacity;
                        cout << "New capacity: " << endl;
                        cin >> capacity;
                        driver.setVehicleCapacity(capacity);
                        break;

                    case 'B':
                        cout << "New handicapable: " << endl;
                        driver.setHandicappedCapable();
                        break;

                    case 'C':
                        cout << "New pet policy: " << endl;
                        driver.setPetsAllowed();
                        break;

                    case 'D':

                        cout << "New first name: " << endl;
                        cin >> newFirstName;
                        driver.setFirstName(newFirstName);
                        break;

                    case 'E':

                        cout << "New Last Name: " << endl;
                        cin >> newLastName;
                        driver.setLastName(newLastName);
                        break;

                    case 'F':

                        cout << "New Vehicle Type (1-5): " << endl;
                        cin >> newVehicleTypeInt;
                        driver.setVehicleType(static_cast<Driver::VehicleType>(newVehicleTypeInt));
                        break;

                    case 'Q':
                        cout << "Quitting Driver Menu" << endl;
                        break;

                    default:
                        cout << "Invalid option, try again." << endl;
                }
                cout << endl;
                break;

            case 'Q':
                cout << "Quitting" << endl;

                return;


            case 'H':
                cout << "Deleting Driver " << driver.getFirstName() << " " << driver.getLastName() << endl;
                break;

            default:
                cout << "Invalid option, try again." << endl;
                cin >> option;
        }
    }
}