#include <iostream>
#include <string>
#include "Passenger.h"
#include "RideCollection.h"

using namespace std;

void PassengerMenu(Passenger *passenger, RideCollection &rideCollection) {

    string newFirstName, newLastName;
    float newRating;
    int newPaymentPreferenceInt = 0;

    while (true) {
        cout << "*************************************" << endl;
        cout << "            Passenger Menu           " << endl;
        cout << "*************************************" << endl;
        cout << "Enter Selection: " << endl;
        cout << "Generate New Ride: A" << endl;
        cout << "Get Rides: B" << endl;
        cout << "Cancel Ride: D" << endl;
        cout << "Get My Information: C" << endl;
        cout << "Edit My information: E" << endl;
        cout << "Logout: Q" << endl;

        Ride newRide;
        char option;
        int sizeOfParty;
        bool thesePets = true;
        bool handicapable = false;
        string pickupLocation;
        string dropOffLocation;
        string note;
        int hour, minute;
        char inputChar;
        int month = 0;
        time_t userTime;
        struct tm timeInfo{};


        int rideIndex = 0;

        cin >> option;

        switch (option) {
            case 'A':
                cout << "How many passengers would you like?" << endl;
                cin >> sizeOfParty;
                cout << "Enter pickup location: " << endl;
                cin >> pickupLocation;
                cout << "Enter drop off location: " << endl;
                cin >> dropOffLocation;
                cout << "Enter note: " << endl;
                cin >> note;

                cout << "Ride Information Below: " << endl;
                cout << "Do you need a handicapable vehicle: " << handicapable << endl;
                cout << "Is it this month (Y/N): ";
                cin >> inputChar;
                if (inputChar == 'N' || inputChar == 'n') {
                    cout << "Enter month (1-12): ";
                    cin >> month;
                }

                cout << "Pickup Hour (0-23): ";
                cin >> hour;

                cout << "Pickup Minute (0-59): ";
                cin >> minute;


                time_t now;
                time(&now);
                timeInfo = *localtime(&now);

                if (inputChar == 'N' || inputChar == 'n') {
                    if (month < timeInfo.tm_mon + 1) {

                        timeInfo.tm_year++;
                    }
                    timeInfo.tm_mon = month - 1;
                }

                timeInfo.tm_hour = hour;
                timeInfo.tm_min = minute;
                timeInfo.tm_sec = 0;
                timeInfo.tm_isdst = -1;

                userTime = mktime(&timeInfo);
                rideCollection.addRide(sizeOfParty, thesePets, pickupLocation, dropOffLocation, userTime, note, handicapable);
                newRide = rideCollection.rides.back();
                passenger->addRide(newRide);
                passenger->printRides();
                cout << endl;
                break;


            case 'B':
                passenger->printRides();
                break;

            case 'C':
                passenger->printPassenger();
                break;


            case 'D':
                cout << "Which ride number would you like to cancel?" << endl;
                passenger->printRides();
                cin >> rideIndex;

                if (rideIndex >= 0 && rideIndex < passenger->rides.size()) {
                    passenger->rides.erase(passenger->rides.begin() + rideIndex);
                    cout << "Ride Cancelled" << endl;
                } else {
                    cout << "Invalid ride number. No ride was canceled." << endl;
                }
                break;

            case 'F':
                cout << "Which ride would you like to rate?" << endl;

                if(passenger->rides.empty()) {
                    cout << "You have no rides to rate." << endl;
                    break;
                }

                for (Ride ride : passenger->rides) {
                    if(static_cast<int>(ride.status) == 13 || static_cast<int>(ride.status)  == 14 ) {
                        passenger->printRides();
                    }
                }

                cin >> rideIndex;
                if ((rideIndex >= 0 && rideIndex < passenger->rides.size())) {
                    cout << "Enter new rating: " << endl;
                    cin >> newRating;
                    passenger->rides.at(rideIndex).setRating(newRating);
                    rideCollection.rides.at(rideIndex).setRating(newRating);
                    cout << "Ride Rated" << endl;
                }

                cout << endl;
                break;


            case 'E':
                cout << "What would you like to edit?" << endl;
                cout << "A: Required Rating : " << passenger->getRequiredRating() << endl;
                cout << "C: Pets Allowed : " << passenger->getHasPets() << endl;
                cout << "D: First Name : " << passenger->getFirstName() << endl;
                cout << "E: Last Name : " << passenger->getLastName() << endl;
                cout << "F: Payment Type : " << static_cast<int>(passenger->getPaymentPreference()) << endl;

                cin >> option;

                switch (option) {
                    case 'A':
                        cout << "New Required Rating: " << endl;
                        cin >> newRating;
                        passenger->setRequiredRating(newRating);
                        break;

                    case 'C':
                        cout << "New pet policy: " << endl;
                        passenger->setHasPets();
                        break;

                    case 'D':
                        cout << "New first name: " << endl;
                        cin >> newFirstName;
                        passenger->setFirstName(newFirstName);
                        break;

                    case 'E':

                        cout << "New Last Name: " << endl;
                        cin >> newLastName;
                        passenger->setLastName(newLastName);
                        break;

                    case 'F':

                        cout << "New Payment Method (1-3): " << endl;
                        cin >> newPaymentPreferenceInt;
                        passenger->setPaymentPreference(
                                static_cast<Passenger::PaymentPreference>(newPaymentPreferenceInt));
                        break;

                    case 'Q':
                        cout << "Quitting Passenger Menu" << endl;
                        break;

                    default:
                        cout << "Invalid option, try again." << endl;
                }
                cout << endl;
                break;

            case 'Q':
                cout << endl;
                return;

            case 'l':
                cout << "Deleting Passenger " << passenger->getFirstName() << " " << passenger->getLastName() << endl;
                delete passenger;
                passenger = nullptr;
                break;

            default:
                cout << "Invalid option, try again." << endl;
                cin >> option;

        }
    }
}