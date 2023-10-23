#include <iostream>
#include <string>
#include <fstream>
#include "Passenger.h"
#include "RideCollection.h"

using namespace std;

void PassengerMenu(Passenger &passenger, RideCollection &rideCollection) {

    Ride newRide;
    char option;
    int sizeOfParty;
    bool thesePets;
    bool handicapable;
    string pickupLocation;
    string dropOffLocation;
    string note;
    int month, day, hour, minute;
    char inputChar;
    time_t userTime;
    struct tm timeInfo{};
    int createid = rand() % 1000000000;
    int idcreated = createid;
    string role, firstName, lastName, id, rating, hasPets, paymentPreference, password;


    string temp;
    string readingLine;

    int rideIndex = 0;
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
        cout << "Get Rides: G" << endl;
        cout << "Cancel Ride: D" << endl;
        cout << "Get My Information: C" << endl;
        cout << "Edit My information: E" << endl;
        cout << "Logout: Q" << endl;

        cin >> option;
        switch (option) {

            case 'G':
                cout << "Which ride number would you like to update?" << endl;
                passenger.printRides();
                cin >> rideIndex;

                if (rideIndex >= 0 && rideIndex < passenger.rides.size()) {
                    id = to_string(rideCollection.rides.at(rideIndex).id);
                    cout << "*************************************" << endl;
                    cout << "           Ride Edit Menu            " << endl;
                    cout << "*************************************" << endl;
                    cout << "Enter Selection: " << endl;
                    cout << "setSizeOfParty A: " << passenger.rides[rideIndex].getSizeOfParty() << endl;
                    cout << "setThesePets B: " << passenger.rides[rideIndex].getIncludesPets() << endl;
                    cout << "setHandicapable C: " << passenger.rides[rideIndex].getHandicapped() << endl;
                    cout << "setPickupLocation D: " << passenger.rides[rideIndex].pickupLocation << endl;
                    cout << "setDropOffLocation E: " << passenger.rides[rideIndex].dropOffLocation << endl;
                    cout << "setPickupTime F: " << passenger.rides[rideIndex].pickupTime << endl;
                    cout << "setNote G: " << passenger.rides[rideIndex].note << endl;
                    cin >> option;
                    switch (option) {

                        case 'A':
                            cout << "Enter size of party: ";
                            cin >> sizeOfParty;
                            passenger.rides[rideIndex].setSizeOfParty(sizeOfParty);
                            rideCollection.rides.at(rideIndex).setSizeOfParty(sizeOfParty);
                            break;
                        case 'B':
                            cout << "Pets were " << passenger.rides[rideIndex].getIncludesPets() << endl;
                            passenger.rides[rideIndex].setIncludesPets();
                            rideCollection.rides.at(rideIndex).setIncludesPets();
                            cout << "And now are " << passenger.rides[rideIndex].getIncludesPets() << endl;
                            break;
                        case 'C':
                            cout << "Handicapable was " << passenger.rides[rideIndex].getHandicapped() << endl;
                            passenger.rides[rideIndex].setHandicapped();
                            rideCollection.rides.at(rideIndex).setHandicapped();
                            cout << "And now are " << passenger.rides[rideIndex].getHandicapped() << endl;
                            break;
                        case 'D':
                            cout << "Enter pickup location: ";
                            cin >> pickupLocation;
                            passenger.rides[rideIndex].setPickupLocation(pickupLocation);
                            rideCollection.rides.at(rideIndex).setPickupLocation(pickupLocation);
                            break;
                        case 'E':
                            cout << "Enter drop off location: ";
                            cin >> dropOffLocation;
                            passenger.rides[rideIndex].setDropOffLocation(dropOffLocation);
                            rideCollection.rides.at(rideIndex).setDropOffLocation(dropOffLocation);
                            break;
                        case 'F':
                            cout << "Is it this month (Y/N): ";
                            cin >> inputChar;
                            if (inputChar == 'N' || inputChar == 'n') {
                                cout << "Enter month (1-12): ";
                                cin >> month;
                            }
                            cout << "Enter Day: ";
                            cin >> day;
                            cout << "Pickup Hour (0-23): ";
                            cin >> hour;
                            cout << "Pickup Minute (0-59): ";
                            cin >> minute;
                            time_t now;
                            time(&now);
                            timeInfo = *localtime(&now);

                            //previous months are 'next year', so add +1 to year
                            if (inputChar == 'N' || inputChar == 'n') {
                                if (month < timeInfo.tm_mon + 1) {
                                    timeInfo.tm_year++;
                                }
                                timeInfo.tm_mon = month - 1;
                            }
                            timeInfo.tm_mday = day;
                            timeInfo.tm_hour = hour;
                            timeInfo.tm_min = minute;
                            timeInfo.tm_sec = 0;
                            timeInfo.tm_isdst = -1;
                            break;
                        case 'G':
                            cout << "Enter note: ";
                            cin >> note;
                            passenger.rides[rideIndex].setNote(note);
                            rideCollection.rides.at(rideIndex).setNote(note);
                            break;

                        default:
                            cout << "Invalid option" << endl;
                            cin >> option;

                    }


                } else {
                    cout << "Invalid ride number. No ride was canceled." << endl;
                }
                break;

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
                cout << "Do you need a handicapable vehicle (Y/N): " << endl;
                cin >> inputChar;
                (inputChar == 'Y' || inputChar == 'y') ? handicapable = true : handicapable = false;
                cout << "Do you have pets (Y/N): " << endl;
                cin >> inputChar;
                (inputChar == 'Y' || inputChar == 'y') ? thesePets = true : thesePets = false;


                cout << "Is it this month (Y/N): ";
                cin >> inputChar;
                if (inputChar == 'N' || inputChar == 'n') {
                    cout << "Enter month (1-12): ";
                    cin >> month;
                }
                cout << "Enter Day: ";
                cin >> day;
                cout << "Pickup Hour (0-23): ";
                cin >> hour;
                cout << "Pickup Minute (0-59): ";
                cin >> minute;
                time_t now;
                time(&now);
                timeInfo = *localtime(&now);

                //previous months are 'next year', so add +1 to year
                if (inputChar == 'N' || inputChar == 'n') {
                    if (month < timeInfo.tm_mon + 1) {
                        timeInfo.tm_year++;
                    }
                    timeInfo.tm_mon = month - 1;
                }
                timeInfo.tm_mday = day;
                timeInfo.tm_hour = hour;
                timeInfo.tm_min = minute;
                timeInfo.tm_sec = 0;
                timeInfo.tm_isdst = -1;
                userTime = mktime(&timeInfo);


                rideCollection.addRide(sizeOfParty, thesePets, pickupLocation, dropOffLocation, userTime, note,
                                       handicapable);
                newRide = rideCollection.rides.back();
                passenger.addRide(newRide);
                passenger.printRides();
                cout << endl;
                break;

            case 'B':
                passenger.printRides();
                break;

            case 'C':
                passenger.printPassenger();
                break;

            case 'D':
                cout << "Which ride number would you like to cancel?" << endl;
                passenger.printRides();
                cin >> rideIndex;

                if (rideIndex >= 0 && rideIndex < passenger.rides.size()) {
                    passenger.rides.at(rideIndex).setStatus(Ride::RideStatus::Cancelled);
                    rideCollection.rides.at(rideIndex).setStatus(Ride::RideStatus::Cancelled);
                    cout << "Ride Cancelled" << endl;
                } else {
                    cout << "Invalid ride number. No ride was canceled." << endl;
                }
                break;

            case 'F':
                cout << "Which ride would you like to rate?" << endl;

                if (passenger.rides.empty()) {
                    cout << "You have no rides to rate." << endl;
                    break;
                }

                for (Ride ride: passenger.rides) {
                    if (static_cast<int>(ride.status) == 13 || static_cast<int>(ride.status) == 14) {
                        passenger.printRides();
                    }
                }

                cin >> rideIndex;
                if ((rideIndex >= 0 && rideIndex < passenger.rides.size())) {
                    cout << "Enter new rating: " << endl;
                    cin >> newRating;
                    passenger.rides.at(rideIndex).setRating(newRating);
                    rideCollection.rides.at(rideIndex).setRating(newRating);
                    cout << "Ride Rated" << endl;
                }

                cout << endl;
                break;


            case 'E':
                cout << "*************************************" << endl;
                cout << "         Passenger Edit Menu         " << endl;
                cout << "*************************************" << endl;
                cout << "Enter Selection: " << endl;
                cout << "A: Required Rating : " << passenger.getRequiredRating() << endl;
                cout << "C: Pets Allowed : " << passenger.getHasPets() << endl;
                cout << "D: First Name : " << passenger.getFirstName() << endl;
                cout << "E: Last Name : " << passenger.getLastName() << endl;
                cout << "F: Payment Type : " << static_cast<int>(passenger.getPaymentPreference()) << endl;

                cin >> option;

                switch (option) {
                    case 'A':
                        cout << "New Required Rating: " << endl;
                        cin >> newRating;
                        passenger.setRequiredRating(newRating);

                        break;

                    case 'C':
                        cout << "pet policy toggled: " << endl;
                        passenger.setHasPets();
                        break;

                    case 'D':
                        cout << "New first name: " << endl;
                        cin >> newFirstName;
                        passenger.setFirstName(newFirstName);
                        break;


                    case 'E':
                        cout << "New Last Name: " << endl;
                        cin >> newLastName;
                        passenger.setLastName(newLastName);
                        break;

                    case 'F':
                        cout << "New Payment Method (1-3): " << endl;
                        cin >> newPaymentPreferenceInt;
                        passenger.setPaymentPreference(
                                static_cast<Passenger::PaymentPreference>(newPaymentPreferenceInt));
                        break;

                    case 'Q':
                        cout << "Quitting Edit Menu" << endl;
                        break;

                    default:
                        cout << "Invalid option, try again." << endl;
                }


                break;


            case 'Q':
                cout << "Quitting" << endl;
                return;


            case 'l':
                cout << "Deleting Passenger " << passenger.getFirstName() << " " << passenger.getLastName() << endl;
                break;

            default:
                cout << "Invalid option, try again." << endl;
                cin >> option;

        }
    }
}