
#include <iostream>
#include <string>
#include "Driver/LuxuryDriver/LuxuryDriver.h"
#include "Driver/BasicDriver/BasicDriver.h"
#include "Driver/EconomyDriver/EconomyDriver.h"
#include "Driver/GroupDriver/GroupDriver.h"

using namespace std;

void DriverMenu(Driver &driver, RideCollection &rideCollection, DriverCollection &driverCollection) {


    while (true) {
        cout << "Vtype " << static_cast<int>(driver.vehicleType) << endl;
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

                break;

            case 'E':// Get Your Information
            {
                driver.getInfo();
                cout << endl;
                break;
            }


            case 'F':// Edit Car information
            {
                cout << "driverMenu case F Driver type: " << driver.getTypeName() << endl;
                cout << "driverMenu case F Driver Vtype: " << static_cast<int>(driver.getVehicleType()) << endl;

                int beforeVType = static_cast<int>(driver.getVehicleType());
                driver.getInfo();
                Driver* updatedDriver = driverCollection.updateVehicleType(&driver);

                if (updatedDriver) {

                    cout << "updatedDriver type " <<  updatedDriver->getTypeName() << endl;
                    updatedDriver->getInfo();

                    cout << "driver = *updatedDriver: "<< endl;
                    driver = *updatedDriver;
                    cout << "driver type " <<  driver.getTypeName() << endl;
                    delete updatedDriver;

                }

                cout << "driverMenu after case F Driver type: " << driver.getTypeName() << endl;

                int afterVType = static_cast<int>(driver.getVehicleType());

                cout << "driverMenu case F updated Driver Vtype: " << static_cast<int>(driver.getVehicleType()) << endl;
                cout << endl;
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
            case 'Q':
                cout << "Quitting Driver Menu" << endl;
                return;

            default:
                cout << "Invalid option, try again." << endl;
                cin >> option;

        }
    }
}

