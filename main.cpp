#include <iostream>
#include <string>
#include <ctime>
#include "Driver.h"
#include "Passenger.h"
#include "DriverCollection.h"
#include "PassengerCollection.h"
#include "RideCollection.h"
#include <fstream>

using namespace std;

struct User {
    Driver *driver;
    Passenger *passenger;

    string role;


    User() : driver(nullptr), passenger(nullptr) {}
};

bool isLoggedIn = false;

void DriverMenu(Driver *driver, RideCollection &rideCollection) {

    string newFirstName, newLastName;
    int newVehicleTypeInt = 0;
    int rideIndex;


    while (true) {
        cout << "*************************************" << endl;
        cout << "            Driver Menu" << endl;
        cout << "*************************************" << endl;
        cout << "Enter Selection: " << endl;
        cout << "Get Current Schedule: A" << endl;
        cout << "Toggle Availability: B" << endl;
        cout << "Current Availability: " << driver->isAvailable() << endl;
        cout << "Get past rides: D" << endl;
        cout << "Get Your Information: E" << endl;
        cout << "Edit Car information: F" << endl;
        cout << "Delete Account: G" << endl;
        cout << "Logout: Q" << endl;

        char option;
        cin >> option;

        switch (option) {
            case 'A':


                for (Ride ride : rideCollection.rides) {
                    if(ride.includesPets && driver->petsAllowed) {
                        if(ride.handicapped && driver->handicappedCapable) {
                            if(ride.sizeOfParty < driver->vehicleCapacity) {
                                if(ride.rating >= driver->driverRating) {
                                    driver->rides.push_back(ride);
                                }
                            }
                        }
                    }
                }

                driver->getSchedule();
                cout << endl;
                break;

            case 'B':

                cout << "Current Availability: " << driver->isAvailable() << endl;
                driver->toggleAvailability();
                cout << "Now: " << driver->isAvailable() << endl;
                cout << endl;
                break;


            case 'D':
                cout << "Which ride number would you like to complete?" << endl;
                driver->getSchedule();
                cin >> option;
                cin >> rideIndex;

                cout << "Was the ride Successful?: Y/N" << endl;
                cin >> option;

                if (rideIndex >= 0 && rideIndex < driver->rides.size()) {
                    driver->rides.erase(driver->rides.begin() + rideIndex);
                    cout << "Ride Cancelled" << endl;
                }

                (option == 'Y' || option == 'y') ? driver->addCompletedRide() : driver->addCancelledRide();
                cout << endl;
                break;


            case 'E':

                cout << "Completed rides: A" << endl;
                cout << "Cancelled rides: B" << endl;
                cin >> option;
                if (option == 'A') {
                    driver->getCompletedRides();
                } else if (option == 'B') {
                    driver->getCancelledRides();
                }
                cout << endl;
                break;

            case 'F':

                driver->printDriver();
                cout << endl;
                break;

            case 'G':

                cout << "What would you like to edit?" << endl;
                cout << "A: Vehicle Capacity : " << driver->getVehicleCapacity() << endl;
                cout << "B: Handicapped Capable: " << driver->isHandicappedCapable() << endl;
                cout << "C: Pets Allowed : " << driver->isPetsAllowed() << endl;
                cout << "D: First Name : " << driver->getFirstName() << endl;
                cout << "E: Last Name : " << driver->getLastName() << endl;
                cout << "F: Vehicle Type : " << static_cast<int>(driver->getVehicleType()) << endl;

                cin >> option;

                switch (option) {
                    case 'A':
                        int capacity;
                        cout << "New capacity: " << endl;
                        cin >> capacity;
                        driver->setVehicleCapacity(capacity);
                        break;

                    case 'B':
                        cout << "New handicapable: " << endl;
                        driver->setHandicappedCapable();
                        break;

                    case 'C':
                        cout << "New pet policy: " << endl;
                        driver->setPetsAllowed();
                        break;

                    case 'D':

                        cout << "New first name: " << endl;
                        cin >> newFirstName;
                        driver->setFirstName(newFirstName);
                        break;

                    case 'E':

                        cout << "New Last Name: " << endl;
                        cin >> newLastName;
                        driver->setLastName(newLastName);
                        break;

                    case 'F':

                        cout << "New Vehicle Type (1-5): " << endl;
                        cin >> newVehicleTypeInt;
                        driver->setVehicleType(static_cast<Driver::VehicleType>(newVehicleTypeInt));
                        break;

                    case 'Q':
                        cout << "Quitting Driver Menu" << endl;
                        break;

                    default:
                        cout << "Invalid option, try again." << endl;
                }
                cout << endl;
                break;

            case 'Q':
                cout << "Quitting" << endl;
                isLoggedIn = false;
                return;


            case 'H':
                cout << "Deleting Driver " << driver->getFirstName() << " " << driver->getLastName() << endl;
                delete driver;
                driver = nullptr;
                break;

            default:
                cout << "Invalid option, try again." << endl;
                cin >> option;
        }
    }
}


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
                        isLoggedIn = false;
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

int main() {
    User user;
    DriverCollection driverCollection;
    PassengerCollection passengerCollection;
    RideCollection rideCollection;


    ofstream fout("RideShareData.dat", ios::app);
    ifstream fin ("RideShareData.dat");

    string driverSearchWord = "Drivers";
    string passengerSearchWord = "Passengers";
    string rideSearchWord = "Rides";
    string readingLine;


    while (true) {

        if (!isLoggedIn && (user.driver != nullptr || user.passenger != nullptr)) {

            cout << "Your accounts: ";
            user.driver != nullptr && cout << "Driver: " << user.driver->getFirstName() << endl;
            user.passenger != nullptr && cout << "Passenger: " << user.passenger->getFirstName() << endl;

            cout << "Do you want to log in?" << endl;
            user.driver != nullptr && cout << "A: Driver" << endl;
            user.passenger != nullptr && cout << "B: Passenger" << endl;
            cout << "C: No" << endl;

            char option;
            cin >> option;
            switch (option) {
                case 'A':
                    cout << "Accessing Driver Features for " << user.driver->getFirstName() << " "
                         << user.driver->getLastName() << endl;
                    cout << "Accessing Driver Menu " << endl;
                    DriverMenu(user.driver, rideCollection);
                    isLoggedIn = true;
                    break;
                case 'B':
                    cout << "Accessing Passenger Features for " << user.passenger->getFirstName() << " "
                         << user.passenger->getLastName() << endl;
                    cout << "Accessing Passenger Menu " << endl;
                    PassengerMenu(user.passenger, rideCollection);
                    isLoggedIn = true;
                    break;
                case 'C':
                    cout << "Exiting" << endl;
                    break;
                default:
                    cout << "Invalid option, try again." << endl;
                    cin >> option;
            }
        }


        if (!isLoggedIn && (user.driver == nullptr || user.passenger == nullptr)) {
            cout << "Choose your role (Driver/Passenger) or 'exit': ";
            cin >> user.role;

            if (user.role == "exit") {
                break;
            } else if (user.role == "Driver") {
                int vehicleCapacity;
                bool handicappedCapable;
                int vehicleType;
                bool petsAllowed;
                string firstName;
                string lastName;
                int id = rand() % 1000000000 + 1000;

                cout << "Enter Vehicle Capacity: ";
                cin >> vehicleCapacity;
                cout << "Is Handicapped Capable (1 for true, 0 for false): ";
                cin >> handicappedCapable;
                cout << "Enter Vehicle Type (1 for Compact2Dr, 2 for Sedan4Dr, 3 for SUV, 4 for Van, 5 for Other): ";
                cin >> vehicleType;
                cout << "Are Pets Allowed (1 for true, 0 for false): ";
                cin >> petsAllowed;
                cout << "Enter First Name: ";
                cin >> firstName;
                cout << "Enter Last Name: ";
                cin >> lastName;

                user.driver = driverCollection.addDriver(vehicleCapacity, handicappedCapable,
                                                         static_cast<Driver::VehicleType>(vehicleType), petsAllowed,
                                                         firstName, lastName);


                while (getline(fin, readingLine)) {
                    fout << readingLine << endl;

                    if (readingLine.find(driverSearchWord) != string::npos) {
                        // Insert the new data after the word
                        fout << "Driver: " ;
                        fout << " " << user.driver->getFirstName();
                        fout <<  " " <<user.driver->getLastName();
                        fout <<  " id " << id;
                        fout <<  " vehicleCapacity: " << user.driver->getVehicleCapacity();
                        fout <<  " isHandicapable: " << user.driver->isHandicappedCapable();
                        fout <<  " vehicleType " << static_cast<int>(user.driver->getVehicleType());
                        fout <<  " petsAllowed: " << user.driver->isPetsAllowed();
                        fout <<  " driverRating: " << 0;
                        for (Ride ride : user.driver->rides) {
                            fout <<  " rideIds: ";
                        }
                        break;

                    }

                }

                cout << "Results:  " << user.driver->getFirstName() << endl;
                isLoggedIn = true;
            } else if (user.role == "Passenger") {
                string firstName;
                string lastName;
                float rating;
                bool hasPets;
                int paymentPreference;
                bool handicapped;
                int id = rand() % 1000000000 + 1000;


                cout << "Enter First Name: ";
                cin >> firstName;
                cout << "Enter Last Name: ";
                cin >> lastName;
                cout << "Enter Minimum Driver Rating: ";
                cin >> rating;
                cout << "Has Pets (1 for true, 0 for false): ";
                cin >> hasPets;
                cout << "Payment Preference (1 for Cash, 2 for Credit, 3 for Debit): ";
                cin >> paymentPreference;


                user.passenger = passengerCollection.addPassenger(firstName, lastName, rating, hasPets,
                                                                  static_cast<Passenger::PaymentPreference>(paymentPreference));
               cout << "Results:  " << user.passenger->getFirstName() << endl;

               while (getline(fin, readingLine)) {
                    fout << readingLine << endl;

                    if (readingLine.find(passengerSearchWord) != string::npos) {
                        // Insert the new data after the word
                        fout << "Passenger: " ;
                        fout << " " << firstName;
                        fout <<  " " <<lastName;
                        fout <<  " id " << id;
                        fout <<  " requiredRating: " << rating;
                        fout <<  " hasPets: " << hasPets;
                        fout <<  " paymentPreference " << paymentPreference;
                        for (Ride ride : user.passenger->rides) {
                            fout <<  " rideIds: ";
                        }
                        break;
                    }
                }

                isLoggedIn = true;
            } else {
                cout << "Invalid role. Please try again." << endl;
            }
        }

        // If the user is already logged in, this section will execute directly.
        if (isLoggedIn) {
            cout << "Logged in as " << user.role << endl;

            if (user.role == "Driver" && user.driver != nullptr) {
                cout << "Accessing Driver Features for " << user.driver->getFirstName() << " "
                     << user.driver->getLastName() << endl;
                cout << "Accessing Driver Menu " << endl;
                DriverMenu(user.driver, rideCollection);


            } else if (user.role == "Passenger" && user.passenger != nullptr) {
                cout << "Accessing Passenger Features for " << user.passenger->getFirstName() << " "
                     << user.passenger->getLastName() << endl;
                cout << "Accessing Passenger Menu " << endl;
                PassengerMenu(user.passenger, rideCollection);
            }



            cout << "Do you want to log out? (yes/no): ";
            string logout;
            cin >> logout;

            if (logout == "yes") {
                isLoggedIn = false;
            }
        }
    }

    return 0;
}



