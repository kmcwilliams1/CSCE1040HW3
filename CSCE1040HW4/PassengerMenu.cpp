

#include "Passenger/PassengerMenu.h"
#include "Ride/RideCollection.h"
#include "Passenger/Passenger.h"

using namespace std;


void PassengerMenu(Passenger passenger, RideCollection &rideCollection) {



    while (true){

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
        cout << "Q: Quit" << endl;

        char option;

        cin >> option;

        switch(option){
            case 'A':
            rideCollection.addRide(passenger);
                break;

        }




    }


}