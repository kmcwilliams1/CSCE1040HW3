#include <iostream>
#include <fstream>
#include "Driver/Driver.h"
#include "Passenger/Passenger.h"
#include "Driver/DriverCollection.h"
#include "Passenger/PassengerCollection.h"
#include "Ride/RideCollection.h"
#include "DriverMenu.cpp"
#include "PassengerMenu.cpp"

using namespace std;


int main() {
    Driver driver;
    Passenger passenger;
    Ride ride;

    DriverCollection driverCollection;
    PassengerCollection passengerCollection;
    RideCollection rideCollection;

    ifstream fin("RideShareData.dat");


    char option;
    string enteredPassword;
    string readingLine;
    string role;
    string driverSearchWord = "Driver";
    string passengerSearchWord = "Passenger";
    string rideSearchWord = "Ride";

    while (fin >> readingLine) {
        role = readingLine.substr(0, readingLine.find(','));

        if (role == driverSearchWord) {

            driver.readDriverProperties(readingLine);
            driverCollection.drivers.push_back(driver);

        } else if (role == rideSearchWord) {

            ride.readRideProperties(readingLine);
            rideCollection.rides.push_back(ride);

        } else if (role == passengerSearchWord) {

            passenger.readPassengerProperties(readingLine);
            passengerCollection.passengers.push_back(passenger);

        }
    }

    cout << "Size of rideCollection is: " << rideCollection.rides.size() << endl;
    cout << "Size of driverCollection is: " << driverCollection.drivers.size() << endl;
    cout << "Size of passengerCollection is: " << passengerCollection.passengers.size() << endl << endl;


    fin.clear();
    fin.seekg(0, ios::beg);


    /*populates the passengers and drivers with ride objects*/
    for (auto &currentRide: rideCollection.rides) {
        for (auto &currentPassenger: passengerCollection.passengers) {
            if (currentRide.assignedPassengerId == currentPassenger.id) {
                currentPassenger.rides.push_back(currentRide);
            }
        }
    }

    for (auto &currentRide: rideCollection.rides) {
        for (auto &currentDriver: driverCollection.drivers) {
            if (currentRide.assignedDriverId == currentDriver.id) {
                currentDriver.rides.push_back(currentRide);
            }
        }
    }

    fin.close();


    while (true) {

        cout << "********* Main Menu *********" << endl;
        cout << "** What do you want to do? **" << endl;
        cout << "** A. Login                **" << endl;
        cout << "** B. Add Driver           **" << endl;
        cout << "** C. Add Passenger        **" << endl;
        cout << "** D. Exit                 **" << endl;
        cout << "*****************************" << endl;

        cin >> option;

        switch (option) {
            case 'a':
            case 'A'://Login
                cout << "Enter password: ";
                cin >> enteredPassword;
                cin.ignore();



                /*search the datasheet for the password, then again, read the values from the datasheet*/

                for (auto &currentDriver: driverCollection.drivers) {
                    if (currentDriver.password == enteredPassword) {
                        DriverMenu(currentDriver, rideCollection, driverCollection);
                    }
                }

                for (auto &currentPassenger: passengerCollection.passengers) {
                    if (currentPassenger.password == enteredPassword) {
                        PassengerMenu(currentPassenger, rideCollection, passengerCollection);
                    } else {
                        cout << "Incorrect password, try again." << endl;
                        cin >> enteredPassword;
                    }
                }


                break;

            case 'b':
            case 'B'://Add Driver

                driver = driverCollection.addDriver(driver);
                cout << "Loading driver " << driver.firstName << endl;
                DriverMenu(driver, rideCollection, driverCollection);

                break;

            case 'c':
            case 'C'://Add Passenger

                passenger = passengerCollection.addPassenger(passenger);
                cout << "Loading passenger " << passenger.firstName << endl;
                PassengerMenu(passenger, rideCollection, passengerCollection);

                break;

            case 'd':
            case 'D'://Exit
                ofstream fout("RideShareData.dat");

                /*all data from sheet was already copied, any new data has already been stored in a
                 * collection, hence the datasheet can be rewritten with all existing collection data*/

                if (!fout) {
                    cerr << "Failed to open output file" << endl;
                    return 1;
                }

                for (Ride &currentRide: rideCollection.rides) {
                    cout << "Ride " << currentRide.pickupLocation << endl;
                    currentRide.writeRideProperties(fout);
                }
                for (Driver &currentDriver: driverCollection.drivers) {
                    currentDriver.writeDriverProperties(fout);
                }
                for (Passenger &currentPassenger: passengerCollection.passengers) {
                    cout << "Passenger " << currentPassenger.firstName << endl;
                    currentPassenger.writePassengerProperties(fout);
                }

                fout.close();

                cout << "Goodbye" << endl;

                return 0;

        }

    }
}
