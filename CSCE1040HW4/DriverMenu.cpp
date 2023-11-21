
#include <iostream>
#include <string>

using namespace std;

void DriverMenu(Driver *driver, RideCollection &rideCollection, DriverCollection &driverCollection) {

    char option;
    string str;

    while (true) {
        cout << "*************************************"<< endl;
        cout << "*          *  Driver Menu  *        *"<< endl;
        cout << "*          *****************        *"<< endl;
        cout << "*          " << driver->getFirstName()<< " " << driver->getLastName()<< endl;
        cout << "*************************************"<< endl;
        cout << "*           Enter Selection:        *" << endl;
        cout << "*************************************"<< endl;
        cout << "*      A. Get Current Schedule      *" << endl;
        cout << "*      B. Toggle Availability       *" << endl;
        cout << "*          C. Finish Ride           *" << endl;
        cout << "*        D. Get past rides          *" << endl;
        cout << "*      E. Get Your Information      *" << endl;
        cout << "*     F. Edit Car information       *" << endl;
        cout << "*        G. Delete Account          *" << endl;
        cout << "*              Q. Logout            *" << endl;
        cout << "*************************************"<< endl;
        cout << "*";



        cin >> option;

        switch (option) {
            case 'A':// Get Current Schedule
                cout << "Add more rides to your schedule?" << endl;
                cin >> option;
                if (option == 'Y' || option == 'y') {
                    rideCollection.assignSchedule(*driver);
                };
                driver->getSchedule();

                break;

            case 'B':// Toggle Availability
                cout << "Current Availability: " << driver->isAvailable() << endl;
                driver->setAvailable(!driver->isAvailable());
                cout << "Now: " << driver->isAvailable() << endl;
                cout << endl;
                break;

            case 'C':// Finish Ride

                cout << "Complete Ride: A" << endl;
                cout << "Cancel Ride: B" << endl;
                cin >> option;

                if (option == 'A' || option == 'a') {
                    driver->setCompletedRides();
                } else if (option == 'B' || option == 'b') {
                    driver->setCancelledRides();
                } else {
                    cout << "Invalid Option" << endl;
                }

                break;

            case 'D':// Get past rides

                break;

            case 'E':// Get Your Information
            {
                driver->getInfo();
                cout << endl;
                break;
            }


            case 'F':// Edit Car information
            {
                driver = driverCollection.updateVehicleType(driver);
                cout << endl;
                break;
            }


            case 'G':// Delete Account

                cout << "Are you sure you want to delete your account?" << endl;
                cin >> option;
                if (option == 'Y' || option == 'y') {
                    driverCollection.removeDriver(*driver);
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

