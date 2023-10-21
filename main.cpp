#include <iostream>
#include <string>
#include <ctime>
#include "Driver.h"
#include "Passenger.h"
#include "DriverCollection.h"
#include "PassengerCollection.h"
#include "RideCollection.h"
#include "DriverMenu.cpp"
#include "PassengerMenu.cpp"
#include <fstream>

using namespace std;

struct User {

    string role;

};

bool isLoggedIn = false;


int main() {
    Driver driver;
    Passenger passenger;
    User user;
    DriverCollection driverCollection;
    PassengerCollection passengerCollection;
    RideCollection rideCollection;
    char option;
    string enteredPassword = " ";

    ofstream fout("RideShareData.dat", ios::app);
    ifstream fin("RideShareData.dat");

    string driverSearchWord = "Drivers";
    string passengerSearchWord = "Passengers";
    string rideSearchWord = "Rides";
    string readingLine;

    // B
    int vehicleCapacity;
    bool handicappedCapable;
    int vehicleType;
    bool petsAllowed;
    int password;

    // B&C
    string firstName;
    string lastName;
    int id = rand() % 1000000000 + 1000;

    // C
    float rating;
    bool hasPets;
    int paymentPreference;
    bool handicapped;

    while (true) {

        cout << "What do you want to do?" << endl;
        cout << "A. Login" << endl;
        cout << "B. Add Driver" << endl;
        cout << "C. Add Passenger" << endl;
        cout << "D. Exit" << endl;

        cin >> option;

        switch (option) {
            case 'A':
                switch (option) {

                    case 'A':
                        cout << "Enter password: ";
                        cin >> enteredPassword;
                        cin.ignore();
                        while (getline(fin, readingLine)) {
                            if (readingLine.find("password: " + enteredPassword) != string::npos) {
                                cout << "readingLine: " << readingLine << endl;

                                cout << "Accessing Driver Menu " << endl;

                                driver.setDriverProperties(readingLine);



                                cout << "Logging in as " << driver.getFirstName() << endl;
                                DriverMenu(driver, rideCollection);
                                break;
                            }
                        }
                        cout << "Incorrect password. Try again." << endl;

                    case 'B':
                        cout << "Enter password: ";
                        cin >> enteredPassword;
                        while (getline(fin, readingLine)) {
                            size_t pos = readingLine.find("password: ");
                            if (pos != string::npos) {
                                string savedPassword = readingLine.substr(pos + 9);
                                if (enteredPassword == savedPassword) {
                                    cout << "Accessing Passenger Menu " << endl;
                                    PassengerMenu(passenger, rideCollection);
                                    break;
                                } else cout << "Incorrect password. Try again." << endl;
                            }
                        }

                        break;

                    case 'C':
                        cout << "Exiting" << endl;
                        break;
                    default:
                        cout << "Invalid option, try again." << endl;
                        cin >> option;
                }
                break;

            case 'B':
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
                cout << "Enter Password: ";
                cin >> password;

                driver = *driverCollection.addDriver(vehicleCapacity, handicappedCapable,
                                                    static_cast<Driver::VehicleType>(vehicleType), petsAllowed,
                                                    firstName, lastName);

                while (getline(fin, readingLine)) {
                    fout << readingLine << endl;

                    if (readingLine.find(driverSearchWord) != string::npos) {
                        // Insert the new data after the word
                        fout << "Driver: ";
                        fout << firstName;
                        fout << " " << lastName;
                        fout << ", id " << id;
                        fout << ", isAvailable " << false;
                        fout << ", vehicleCapacity: " << vehicleCapacity;
                        fout << ", isHandicapable: " << handicappedCapable;
                        fout << ", vehicleType " << static_cast<int>(driver.getVehicleType());
                        fout << ", petsAllowed: " << driver.isPetsAllowed();
                        fout << ", driverRating: " << 0;
                        for (Ride ride: driver.rides) {
                            fout << " rideIds: " << ride.getId() << " , ";
                        }
                        fout << ", Complete Rides: " << 0;
                        fout << ", Cancelled Rides: " << 0;
                        fout << ", password: " << password << " " << endl;
                        fout.flush();
                        break;
                    }
                }
                cout << "Accessing Driver Features for " << driver.getFirstName() << " "
                     << driver.getLastName() << endl;
                cout << "Accessing Driver Menu " << endl;
                DriverMenu(driver, rideCollection);
                break;

            case 'C':
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

                passenger = *passengerCollection.addPassenger(firstName, lastName, rating, hasPets,
                                                             static_cast<Passenger::PaymentPreference>(paymentPreference));

                while (getline(fin, readingLine)) {
                    fout << readingLine << endl;

                    if (readingLine.find(passengerSearchWord) != string::npos) {
                        // Insert the new data after the word
                        fout << "Passenger: ";
                        fout << " " << firstName;
                        fout << " " << lastName;
                        fout << " id " << id;
                        fout << " requiredRating: " << rating;
                        fout << " hasPets: " << hasPets;
                        fout << " paymentPreference " << paymentPreference;
                        for (Ride ride: passenger.rides) {
                            fout << " rideIds: " << ride.getId();
                        }
                        break;
                    }
                }
                cout << "Accessing Passenger Features for " << passenger.getFirstName() << " "
                     << passenger.getLastName() << endl;
                cout << "Accessing Passenger Menu " << endl;
                PassengerMenu(passenger, rideCollection);
                break;

            case 'D':
                cout << "Exiting" << endl;
                return 0;

            default:
                cout << "Invalid option" << endl;
        }

    }

    return 0;
}


void
mainMenu(DriverCollection &driverCollection, PassengerCollection &passengerCollection, RideCollection &rideCollection) {

}
