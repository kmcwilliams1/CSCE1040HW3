
#include <algorithm>
#include "Ride/RideCollection.h"
#include "Passenger/Passenger.h"


using namespace std;


void PassengerMenu(Passenger *passenger, RideCollection *rideCollection, PassengerCollection &passengerCollection) {

    while (true) {

        cout << "*************************************" << endl;
        cout << "*         *  Passenger Menu  *      *" << endl;
        cout << "*         *******************       *" << endl;
        cout << "*           " << passenger->getFirstName() << " " << passenger->getLastName() << endl;
        cout << "*************************************" << endl;
        cout << "*           Enter Selection:        *" << endl;
        cout << "*************************************" << endl;
        cout << "*          A. Add New Ride          *" << endl;
        cout << "*           B. Print Rides          *" << endl;
        cout << "*           D. Cancel Ride          *" << endl;
        cout << "*            H. Edit Ride           *" << endl;
        cout << "*           F. Rate a Ride          *" << endl;
        cout << "*       ----------------------      *" << endl;
        cout << "*       C. Print My Information     *" << endl;
        cout << "*        E. Edit My Information     *" << endl;
        cout << "*       G. Delete My Information    *" << endl;
        cout << "* I. Delete Cancelled and Completed Rides *" << endl;
        cout << "*              Q. Quit              *" << endl;
        cout << "*************************************" << endl;
        cout << "*";

        char option;
        string string1;


        cin >> option;
        cout << "*************************************" << endl;

        switch (option) {
            case 'a':
            case 'A':// Add New Ride
            {
                Ride *newRide = new Ride();
                newRide->setAssignedPassengerId(passenger->id);
                rideCollection->addRide(newRide);
                passenger->addRide(newRide);
                break;
            }
            case 'b':
            case 'B':// Print Rides
                cout << "A. Cancelled " << endl;
                cout << "B. Completed " << endl;
                cout << "C. Active " << endl;
                cin >> option;
                passenger->getRides(option);
                break;

            case 'c':
            case 'C':// Print Information
                passenger->getInfo();
                break;

            case 'd':
            case 'D': // Cancel Ride
                passenger->cancelRide();
                break;

            case 'e':
            case 'E': // Edit

                passenger->editInfo();
                break;


            case 'f':
            case 'F': //Rate

            {
                passenger->rateRide();
                break;
            }

            case 'g':
            case 'G': // Delete
                cout << "Are you sure you wish to delete this account?";
                cin >> option;
                if (option == 'Y' || option == 'y') {
                    passengerCollection.deletePassenger(passenger);
                }
                break;

            case 'h':
            case 'H': // Edit Ride
                passenger->editRide();
                break;

            case 'i':
            case 'I':// Delete past cancelled and completed rides
                passenger->deleteCancelledAndCompletedRides();

            case 'Q':
            case 'q': // Quit
            {

                cout << "Goodbye!" << endl;
                return;
            }




            default:
                cout << "Not an input, try again" << endl;
                break;

        }
    }
}