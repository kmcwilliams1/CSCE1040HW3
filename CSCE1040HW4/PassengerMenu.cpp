

#include "Passenger/PassengerMenu.h"
#include "Ride/RideCollection.h"
#include "Passenger/Passenger.h"

using namespace std;


void PassengerMenu(Passenger passenger, RideCollection &rideCollection, PassengerCollection &passengerCollection) {
    Ride newRide;

    while (true) {

        cout << "*************************************" << endl;
        cout << "            Passenger Menu           " << endl;
        cout << "*************************************" << endl;
        cout << "Enter Selection: " << endl;
        cout << "A: Add New Ride" << endl;
        cout << "B: Print Rides" << endl;
        cout << "C: Print Information" << endl;
        cout << "D: Cancel Ride" << endl;
        cout << "E: Edit Information" << endl;
        cout << "F: Rate a Ride" << endl;
        cout << "G: Delete Information" << endl;
        cout << "H: Edit Rides" << endl;
        cout << "Q: Quit" << endl;

        char option;
        float flo;
        int i;
        string string1;



        cin >> option;

        switch (option) {
            case 'A':// Add New Ride
                newRide.assignedPassengerId = passenger.id;
                newRide = rideCollection.addRide(newRide);
                passenger.rides.push_back(newRide);
                break;

            case 'B':// Print Rides
                passenger.getRides();
                break;

            case 'C':// Print Information
                passenger.getInfo();
                break;

            case 'D': // Cancel Ride
                passenger.cancelRide();
                break;

            case 'E': // Edit
                passenger.editInfo();
                break;

            case 'F': //Rate
                passenger.rateRide();
                break;

            case 'G': // Delete
                cout << "Are you sure you wish to delete this account?";
                cin >> option;
                if (option == 'Y' || option == 'y') {
                    passengerCollection.deletePassenger(passenger);
                }

                break;


            case 'H': // Edit
                passenger.editRide();
                break;

            case 'Q': //Quit
                cout << "Goodbye!" << endl;
                return;

            default:
                cout << "Not an input, try again" << endl;
                cin >> option;

        }


    }

}