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


bool isLoggedIn = false;


int main() {
    Driver driver;
    Passenger passenger;
    DriverCollection driverCollection;
    PassengerCollection passengerCollection;
    RideCollection rideCollection;
    char option;
    string enteredPassword;

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

                    case 'A': //Login
                        cout << "Enter password: ";
                        cin >> enteredPassword;
                        cin.ignore();
                        while (getline(fin, readingLine)) {
                            cout << "Reading Line " << readingLine << endl;

                            if (readingLine.find("Driver") != string::npos &&
                                readingLine.find(enteredPassword) != string::npos) {
                                cout << "found password at : " << enteredPassword << endl;
                                cout << "Accessing Driver Menu " << endl;
                                driver.setDriverProperties(readingLine); // Pass the entire line
                                cout << "Logging in as " << driver.getFirstName() << endl;
                                DriverMenu(driver, rideCollection);
                                break;
                            }

                            if (readingLine.find("Passenger") != string::npos &&
                                readingLine.find(enteredPassword) != string::npos) {
                                cout << "found password at : " << readingLine << endl;
                                cout << "Accessing Passenger Menu " << endl;
                                passenger.setPassengerProperties(readingLine);
                                cout << "Logging in as " << passenger.getFirstName() << endl;
                                PassengerMenu(passenger, rideCollection);
                                break;

                            }
                        }
                        cout << "Incorrect password. Try again." << endl;
                        break;


                    case 'C':
                        cout << "Exiting" << endl;
                        break;
                    default:
                        cout << "Invalid option, try again." << endl;
                        cin >> option;
                }
                break;

            case 'B': // Add Driver
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
                    cout << "looking to add driver readingLine: " << readingLine << endl;

                    if (readingLine.find(driverSearchWord)) {

                        fout << "Driver, ";
                        fout << firstName << ",";
                        fout << lastName << ",";
                        fout << id << ",";
                        fout << false << ","; // isAvailable
                        fout << vehicleCapacity << ",";
                        fout << handicappedCapable << ",";
                        fout << static_cast<int>(driver.getVehicleType()) << ",";
                        fout << driver.isPetsAllowed() << ",";
                        fout << 0 << ","; // driverRating
                        fout << 0 << ","; //completed rides
                        fout << 0 << ","; // cancelled rides
                        fout << password << "," << endl;
                        fout.flush();
                        break;
                    }
                }
                cout << "Accessing Driver Features for " << driver.getFirstName() << " "
                     << driver.getLastName() << endl;
                cout << "Accessing Driver Menu " << endl;
                DriverMenu(driver, rideCollection);
                break;

            case 'C': // Add Passenger
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
                cout << "Enter Password: ";
                cin >> password;

                passenger = *passengerCollection.addPassenger(firstName, lastName, rating, hasPets,
                                                              static_cast<Passenger::PaymentPreference>(paymentPreference));

                while (getline(fin, readingLine)) {


                    if (readingLine.find(passengerSearchWord) != string::npos) {

                        fout << "Passenger, ";
                        fout << firstName << ",";
                        fout << lastName << ",";
                        fout << id << ",";
                        fout << rating << ",";
                        fout << hasPets << ",";
                        fout << paymentPreference << ",";
                        fout << password << ",";
                        fout.flush();
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
}


