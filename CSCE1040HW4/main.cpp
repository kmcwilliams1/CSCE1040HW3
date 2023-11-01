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
  //  ofstream fout("RideShareData.dat");


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

    fin.clear();
    fin.seekg(0, ios::beg);

    for(Passenger& currentPassenger : passengerCollection.passengers) {
        for(int rideId : currentPassenger.rideIds) {
            for(auto & currentRide : rideCollection.rides) {
                if(rideId == currentRide.id) {
                   currentPassenger.rides.push_back(currentRide);
                }
            }
        }
    }

    for(Driver& currentDriver : driverCollection.drivers) {
        for(int rideId : currentDriver.rideIds) {
            for(auto & currentRide : rideCollection.rides) {
                if(rideId == currentRide.id) {
                   currentDriver.rides.push_back(currentRide);
                }
            }
        }
    }



    cout << "List of driver collection is: " << driverCollection.drivers.size() << endl;
    cout << "List of passenger collection is: " << passengerCollection.passengers.size() << endl;
    cout << "List of ride collection is: " << rideCollection.rides.size() << endl << endl;

    while (true) {

        cout << "********* Main Menu **********" << endl;
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

                while (getline(fin, readingLine)) {


                    /*search the datasheet for the password, then again, read the values from the datasheet*/
                    if (readingLine.find("Driver") != string::npos &&
                        readingLine.find(enteredPassword) != string::npos) {
                        cout << "Accessing Driver Menu " << endl;
                        driver.readDriverProperties(readingLine);
                        cout << "Logging in as " << driver.getFirstName() << endl;
                        DriverMenu(driver, rideCollection, driverCollection);
                        break;
                    } else if (readingLine.find("Passenger") != string::npos &&
                        readingLine.find(enteredPassword) != string::npos) {
                        cout << "Accessing Passenger Menu " << endl;
                        passenger.readPassengerProperties(readingLine);
                        cout << "Logging in as " << passenger.firstName << endl;
                        PassengerMenu(passenger, rideCollection, passengerCollection);
                        break;

                    } else cout << "Incorrect password. Try again." << endl;

                }

                fin.clear();
                fin.seekg(0, ios::beg);

                break;

            case 'b':
            case 'B'://Add Driver

                driverCollection.addDriver();

                break;

            case 'c':
            case 'C'://Add Passenger

                passengerCollection.addPassenger();

                break;

            case 'd':
            case 'D'://Exit

//                if(!fout){
//                    cerr << "Failed to open output file"<< endl;
//                    return 1;
//                }
//
//                for (Ride &ride1: rideCollection.rides) {
//                    ride1.writeRideProperties(fout);
//                }
//                for (Driver &driver1: driverCollection.drivers) {
//                    driver1.writeDriverProperties(fout);
//                }
//                for (Passenger &passenger1: passengerCollection.passengers) {
//                    passenger1.writePassengerProperties(fout);
//                }
//
//                fout.close();

                cout << "Goodbye" << endl;

                return 0;

            default:
                cout << "Invalid option, try again" << endl;
                cin >> option;

        }

    }


    return 0;
}
