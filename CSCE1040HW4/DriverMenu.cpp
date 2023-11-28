
#include <iostream>
#include <string>

using namespace std;

void DriverMenu(Driver *driver, RideCollection *rideCollection, DriverCollection &driverCollection) {

    char option;
    string str;

    while (true) {
        cout << "*************************************" << endl;
        cout << "*          *  Driver Menu  *        *" << endl;
        cout << "*          *****************        *" << endl;
        cout << "*             " << driver->getFirstName() << " " << driver->getLastName() << endl;
        cout << "*************************************" << endl;
        cout << "*           Enter Selection:        *" << endl;
        cout << "*************************************" << endl;
        cout << "*        A. Get Current Rides       *" << endl;
        cout << "*           B. Finish Ride          *" << endl;
        cout << "*          C. Get Past rides        *" << endl;
        cout << "*      -----------------------      *" << endl;
        cout << "*       D. Toggle Availability      *" << endl;
        cout << "*      E. Get Your Information      *" << endl;
        cout << "*      F. Edit Your information     *" << endl;
        cout << "*      -----------------------      *" << endl;
        cout << "*        G. Delete Account          *" << endl;
        cout << "*             Q. Logout             *" << endl;
        cout << "*************************************" << endl;
        cout << "*";


        cin >> option;
        cout << "*************************************" << endl;

        switch (option) {
            case 'a':
            case 'A':// Get Current Rides
                driver->getSchedule();
                cout << "Add more rides to your schedule? (Y/N)" << endl;
                cin >> option;
                if (option == 'Y' || option == 'y') {
                    rideCollection->assignSchedule(*driver);
                    driver->getSchedule();
                } else if (option == 'N' || option == 'n') {
                    break;
                } else {
                    cout << "Invalid input, please try again.";
                }
                break;

            case 'd':
            case 'D':// Toggle Availability
            {

                cout << "Are you available? (Y/N)" << endl;
                cin >> option;

                if (option == 'Y' || option == 'y') {
                    driver->setAvailable(true);
                    cout << "Now Available" << endl;
                } else if (option == 'N' || option == 'n') {
                    driver->setAvailable(false);
                    cout << "Now Unavailable" << endl;
                } else {
                    cout << "Invalid input, please try again.";
                }



                break;
            }

            case 'b':
            case 'B':// Finish Ride
                cout << "Which action would you like to take?" << endl;
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

            case 'c':
            case 'C':// Get rides
                driver->getRides();
                break;

            case 'e':
            case 'E':// Get Your Information
            {
                driver->getInfo();
                cout << endl;
                break;
            }

            case 'f':
            case 'F':// Edit Car information
            {
                driver->editInfo();
                cout << endl;
                break;
            }

            case 'g':
            case 'G':// Delete Account

                cout << "Are you sure you want to delete your account?" << endl;
                cin >> option;
                if (option == 'Y' || option == 'y') {
                    driverCollection.removeDriver(*driver);
                    cout << "Account deleted" << endl;
                }
                break;

            case 'q':
            case 'Q':
                cout << "Quitting Driver Menu" << endl;
                return;

            default:
                cout << "Invalid option, try again." << endl;
                cin >> option;

        }
    }
}

