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
    Ride ride;
    
    DriverCollection driverCollection;
    PassengerCollection passengerCollection;
    RideCollection rideCollection;

    char option;
    string enteredPassword;

    fstream file("RideShareData.dat");
    fstream tempFile("TempRideShareData.dat", ios::out);
    string driverSearchWord = "Driver,";
    string passengerSearchWord = "Passenger,";
    string rideSearchWord = "Ride,";
    string readingLine;
    string role;

    while (file >> readingLine) {
        cout << "main readingLine: " <<readingLine << endl;
        role = readingLine.substr(0, readingLine.find(','));
        cout <<"Role: " << role << endl;
        switch (role) {
            case driverSearchWord:
                getline(file, readingLine, ',');
                driver.setFirstName(readingLine);

                getline(file, readingLine, ',');
                driver.setLastName(readingLine);

                getline(file, readingLine, ',');
                driver.setId(stoi(readingLine));

                getline(file, readingLine, ',');
                driver.setAvailable();

                getline(file, readingLine, ',');
                driver.setVehicleCapacity(stoi(readingLine));

                getline(file, readingLine, ',');
                driver.setHandicappedCapable();

                getline(file, readingLine, ',');
                driver.setVehicleType(stoi(readingLine));

                getline(file, readingLine, ',');
                driver.setPetsAllowed();

                getline(file, readingLine, ',');
                driver.setDriverRating(stoi(readingLine));

                getline(file, readingLine, ',');
                driver.setCompletedRides(stoi(readingLine));

                getline(file, readingLine, ',');
                driver.setCancelledRides(stoi(readingLine));

                getline(file, readingLine, ',');
                driver.setPassword(readingLine);

                driverCollection.addDriver(driver);
                break;
            case passengerSearchWord:

                getline(file, readingLine, ',');
                passenger.setFirstName(readingLine);

                getline(file, readingLine, ',');
                passenger.setLastName(readingLine);

                getline(file, readingLine, ',');
                passenger.setId(stoi(readingLine));

                getline(file, readingLine, ',');
                passenger.setRequiredRating(stoi(readingLine));

                getline(file, readingLine, ',');
                passenger.setHasPets();

                getline(file, readingLine, ',');
                passenger.setPaymentPreference(stoi(readingLine));

                getline(file, readingLine, ',');
                passenger.setPassword(readingLine);

                passengerCollection.addPassenger(passenger);

                break;
            case rideSearchWord:

                getline(file, readingLine, ',');
                ride.setSizeOfParty(stoi(readingLine));

                getline(file, readingLine, ',');
                ride.setPickupLocation((readingLine));

                getline(file, readingLine, ',');
                ride.setDropOffLocation((readingLine));

                getline(file, readingLine, ',');
                ride.setPickupTime(stoi(readingLine));

                getline(file, readingLine, ',');
                ride.setNote(readingLine);

                getline(file, readingLine, ',');
                ride.setHandicapped();

                getline(file, readingLine, ',');
                ride.setIncludesPets();

                getline(file, readingLine, ',');
                ride.setId(stoi(readingLine));

                getline(file, readingLine, ',');
                ride.setStatus(stoi(readingLine));

                break;

            default:
                break;
        }
    }


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
                        while (getline(file, readingLine)) {

                            if (readingLine.find("Driver") != string::npos &&
                                readingLine.find(enteredPassword) != string::npos) {
                                cout << "Accessing Driver Menu " << endl;
                                driver.setDriverProperties(readingLine); // Pass the entire line
                                cout << "Logging in as " << driver.getFirstName() << endl;
                                DriverMenu(driver, rideCollection);
                                break;
                            }

                            else if (readingLine.find("Passenger") != string::npos &&
                                readingLine.find(enteredPassword) != string::npos) {
                                cout << "Accessing Passenger Menu " << endl;
                                passenger.setPassengerProperties(readingLine);
                                cout << "Logging in as " << passenger.getFirstName() << endl;
                                PassengerMenu(passenger, rideCollection);
                                break;

                            }

                            else  cout << "Incorrect password. Try again." << endl;

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


                cout << "Accessing Passenger Features for " << passenger.getFirstName() << " "
                     << passenger.getLastName() << endl;
                cout << "Accessing Passenger Menu " << endl;
                PassengerMenu(passenger, rideCollection);
                break;

            case 'D':
                cout << "Exiting" << endl;

                //save everything to file
                // while (getline(file, readingLine)) {
                //
                //                        cout << "rideEditMenu readingLine " << readingLine << endl;
                //
                //                        if (readingLine.find(rideCollection.rides.at(rideIndex).id) == string::npos) {
                //
                //
                //                            cout << "not the line with info, being sent to temp file: " << readingLine << endl << endl;
                //                            tempFile << readingLine << endl;
                //
                //
                //                        } else if (readingLine.find(rideCollection.rides.at(rideIndex).id) != string::npos) {
                //
                //                            cout << "rideEditMenu readingLine found " << readingLine << endl << endl;
                //                            sizeOfParty = passenger.rides[rideIndex].getSizeOfParty();
                //                            pickupLocation = passenger.rides[rideIndex].getPickupLocation();
                //                            dropOffLocation = passenger.rides[rideIndex].getDropOffLocation();
                //                            note = passenger.rides[rideIndex].getNote();
                //                            userTime = mktime(&timeInfo);
                //                            handicapable = passenger.rides[rideIndex].getHandicapped();
                //                            thesePets = passenger.rides[rideIndex].getIncludesPets();
                //
                //
                //                            // Update the ride's information in this line
                //                            file << "Ride,";
                //
                //                            tempFile << sizeOfParty << ",";
                //                            tempFile << pickupLocation << ",";
                //                            tempFile << dropOffLocation << ",";
                //                            tempFile << userTime << ",";
                //                            tempFile << note << ",";
                //                            tempFile << handicapable << ",";
                //                            tempFile << thesePets << ",";
                //                            tempFile << idcreated << ",";
                //                            tempFile << 1 << ",";
                //                            tempFile << endl;
                //
                //
                //                            tempFile << endl;
                //                        }
                //                    }
                //    // Rename the temporary file to the original file's name
                //                cout << "Attempting to rename the temporary file to the original file." << endl;
                //                if (rename("TempRideShareData.dat", "RideShareData.dat") != 0) {
                //                    perror("Failed to rename the temporary file to the original file");
                //                    return; // or handle the error appropriately
                //                } else {
                //                    cout << "Rename successful." << endl;
                //                }
                //
                //                cout << "Attempting to remove the original file." << endl;
                //                if (remove("TempRideShareData.dat") != 0) {
                //                    perror("Failed to remove the original file");
                //                    return; // or handle the error appropriately
                //                } else {
                //                    cout << "Removal successful." << endl;
                //                }


                return 0;

            default:
                cout << "Invalid option" << endl;
        }

    }
}


