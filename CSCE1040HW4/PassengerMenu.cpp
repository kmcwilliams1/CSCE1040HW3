

#include "Passenger/PassengerMenu.h"
#include "Ride/RideCollection.h"
#include "Passenger/Passenger.h"

using namespace std;


void PassengerMenu(Passenger passenger, RideCollection &rideCollection, PassengerCollection &passengerCollection) {


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
        cout << "Q: Quit" << endl;

        char option;
        float flo;
        int i;
        string string1;

        cin >> option;

        switch (option) {
            case 'A':// Add New Ride
                rideCollection.addRide(passenger);
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
                cout << "*************************************" << endl;
                cout << "         Passenger Edit Menu        " << endl;
                cout << "*************************************" << endl;
                cout << "What would you like to edit?" << endl;
                cout << "A: Required Rating : " << passenger.getRequiredRating() << endl;
                cout << "C: Pets Allowed : " << passenger.getHasPets() << endl;
                cout << "D: First Name : " << passenger.getFirstName() << endl;
                cout << "E: Last Name : " << passenger.getLastName() << endl;
                cout << "F: Payment Type : " << static_cast<int>(passenger.getPaymentPreference()) << endl;

                cin >> option;


                switch (option) {
                    case 'A':
                        cout << "New Required Rating: " << endl;
                        cin >> i;
                        passenger.setRequiredRating(flo);
                        break;

                    case 'C':
                        cout << "New pet policy: " << endl;
                        passenger.setHasPets();
                        break;

                    case 'D':

                        cout << "New first name: " << endl;
                        cin >> string1;
                        passenger.setFirstName(string1);

                        break;

                    case 'E':
                        cout << "New Last Name: " << endl;
                        cin >> string1;
                        passenger.setLastName(string1);
                        break;

                    case 'F':
                        cout << "New Payment Method (1-3): " << endl;
                        cin >> i;
                        passenger.setPaymentPreference(
                                static_cast<Passenger::PaymentPreference>(i));
                        break;

                    case 'Q':
                        cout << "Quitting Edit Menu" << endl;
                        break;

                    default:
                        cout << "Invalid option, try again." << endl;
                }

                break;


            case 'F': //Rate

                passenger.rateRide(passenger);


                break;

            case 'G': // Delete

                cout << "Are you sure you wish to delete this account?";
                cin >> option;
                if (option == 'Y' || option == 'y') {
                    passengerCollection.deletePassenger(passenger);
                }

                break;

            case 'Q': //Quit

                break;

            default:
                cout << "Not an input, try again" << endl;
                cin >> option;

        }
        break;

    }

}