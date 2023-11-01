
#include <iostream>
#include <string>
#include "Ride/RideCollection.h"
#include "Driver/Driver.h"

using namespace std;

void DriverMenu(Driver driver, RideCollection &rideCollection, DriverCollection &driverCollection) {


    while (true) {
        cout << "*************************************" << endl;
        cout << "            Driver Menu" << endl;
        cout << "*************************************" << endl;
        cout << "Enter Selection: " << endl;
        cout << "Get Current Schedule: A" << endl;
        cout << "Toggle Availability: B" << endl;
        cout << "Finish Ride: C" << endl;
        cout << "Get past rides: D" << endl;
        cout << "Get Your Information: E" << endl;
        cout << "Edit Car information: F" << endl;
        cout << "Delete Account: G" << endl;
        cout << "Logout: Q" << endl;

        char option;
        string str;
        int i;
        cin >> option;

        switch (option) {
            case 'A':// Get Current Schedule
                cout << "Add more rides to your schedule?" << endl;
                cin >> option;
                if (option == 'Y' || option == 'y') {
                    rideCollection.assignSchedule(driver);
                };
                driver.getSchedule();

                break;

            case 'B':// Toggle Availability
                cout << "Current Availability: " << driver.isAvailable() << endl;
                driver.setAvailable();
                cout << "Now: " << driver.isAvailable() << endl;
                cout << endl;
                break;

            case 'C':// Finish Ride

                cout << "Complete Ride: A" << endl;
                cout << "Cancel Ride: B" << endl;
                cin >> option;

                if (option == 'A' || option == 'a') {
                    driver.setCompletedRides();
                } else if (option == 'B' || option == 'b') {
                    driver.setCancelledRides();
                } else {
                    cout << "Invalid Option" << endl;
                }

                break;

            case 'D':// Get past rides
                cout << "Completed rides: A" << endl;
                cout << "Cancelled rides: B" << endl;
                cin >> option;
                if (option == 'A') {
                    driver.getCompletedRides();
                }
                if (option == 'B') {
                    driver.getCancelledRides();
                }
                break;

            case 'E':// Get Your Information
                driver.getInfo();
                cout << endl;

                break;
            case 'F':// Edit Car information
                cout << "*************************************" << endl;
                cout << "           Driver Edit Menu          " << endl;
                cout << "*************************************" << endl;
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
                        cout << "New capacity: " << endl;
                        cin >> i;
                        driver.setVehicleCapacity(i);
                        break;

                    case 'B':
                        driver.setHandicappedCapable();
                        cout << "New handicapable: " << endl;
                        driver.isHandicappedCapable();
                        break;

                    case 'C':
                        cout << "New pet policy: " << endl;
                        driver.setPetsAllowed();
                        break;

                    case 'D':

                        cout << "New first name: " << endl;
                        cin >> str;
                        driver.setFirstName(str);
                        break;

                    case 'E':

                        cout << "New Last Name: " << endl;
                        cin >> str;
                        driver.setLastName(str);
                        break;

                    case 'F':

                        cout << "New Vehicle Type (1-5): " << endl;
                        cin >> i;
                        driver.setVehicleType(static_cast<Driver::VehicleType>(i));
                        break;

                    case 'Q':
                        cout << "Quitting Driver Menu" << endl;
                        break;

                    default:
                        cout << "Invalid option, try again." << endl;
                        break;
                }

            case 'G':// Delete Account

                cout << "Are you sure you want to delete your account?" << endl;
                cin >> option;
                if (option == 'Y' || option == 'y') {
                    driverCollection.removeDriver(driver);
                    cout << "Account deleted" << endl;
                }

                break;

            default:
                cout << "Invalid option, try again." << endl;
                cin >> option;
        }


    }

}

