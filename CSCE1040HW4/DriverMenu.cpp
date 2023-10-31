
#include <iostream>
#include <string>
#include "Ride/RideCollection.h"
#include "Driver/Driver.h"

using namespace std;

void DriverMenu(const Driver &driver, RideCollection &rideCollection, DriverCollection &driverCollection) {


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

                break;
        }
    }


}