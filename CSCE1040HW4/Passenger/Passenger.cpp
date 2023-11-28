
#include <sstream>
#include <random>
#include "Passenger.h"

using namespace std;


Passenger::~Passenger() = default;

Passenger::Passenger() = default;


void Passenger::writePassengerProperties(ostream &dataFile) {
    dataFile << "Passenger,";
    dataFile << firstName << ",";
    dataFile << lastName << ",";
    dataFile << id << ",";
    dataFile << requiredRating << ",";
    dataFile << (hasPets ? "true" : "false") << ",";
    dataFile << static_cast<int>(paymentPreference) << ",";
    dataFile << password << ",";
    for (const auto &ride : rides) {
        dataFile << ride->id << ",";
    }
}

void Passenger::addRide(Ride* ride) {
    rides.push_back(ride);
}


void Passenger::getInfo() const {
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Required Rating: " << requiredRating << endl;
    cout << "Has Pets: " << (hasPets ? "true" : "false") << endl;
    string stringPaymentPreference;
    switch (static_cast<int>(paymentPreference)) {
        case 1:
            stringPaymentPreference = "Cash";
            break;
        case 2:
            stringPaymentPreference = "Credit";
            break;
        case 3:
            stringPaymentPreference = "Debit";
            break;

    }
    cout << "Payment Preference: " << stringPaymentPreference << endl;
    cout << "Password: " << password << endl;
    int count = 0;
    int currentRides = 0;
    for (auto &ride: rides) {
        count++;
        if (ride->rideStatus == Ride::RideStatus::Active) {
            currentRides++;
        }
    }
    cout << "Total Rides: " << count << endl;
    (currentRides < 2) ? cout << "Current Active Rides: " << currentRides << endl : cout << "Current Active Rides: "
                                                                                         << currentRides
                                                                                         << ", consider cancelling "
                                                                                         << currentRides - 1 << endl;

    cout << endl;

}

void Passenger::deleteCancelledAndCompletedRides() {
    for (auto it = rides.begin(); it != rides.end();) {
        if ((*it)->rideStatus == Ride::RideStatus::Completed || (*it)->rideStatus == Ride::RideStatus::Cancelled) {
            it = rides.erase(it);
        } else {
            ++it;
        }
    }
}


float Passenger::getRequiredRating() const {
    return requiredRating;
}

void Passenger::setRequiredRating(float rating) {

}

bool Passenger::getHasPets() const {
    return hasPets;
}

void Passenger::setHasPets(bool value) {
    hasPets = value;
}

Passenger::PaymentPreference Passenger::getPaymentPreference() const {
    return paymentPreference;
}

void Passenger::setPaymentPreference(Passenger::PaymentPreference pref) {

}

int Passenger::getId() const {
    return id;
}

void Passenger::setId() {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 20000);
    int random_number = distribution(generator);
    id = random_number;
}

string Passenger::getFirstName() const {
    return firstName;
}

void Passenger::setFirstName(const string &first) {

}

string Passenger::getLastName() const {
    return lastName;
}

void Passenger::setLastName(const string &last) {

}

void Passenger::getRides(char option) const {
    if (!rides.empty()) {
        bool foundRides = false;

        cout << "Rides:" << endl;
        cout << "---------------------------------------" << endl;

        for (const Ride* ridePtr : rides) {
            const Ride& ride = *ridePtr;
            bool printRide;

            switch (option) {
                case 'C':
                case 'c':
                    printRide = (ride.rideStatus == Ride::RideStatus::Active);
                    break;

                case 'A':
                case 'a':
                    printRide = (ride.rideStatus == Ride::RideStatus::Cancelled);
                    break;

                case 'B':
                case 'b':
                    printRide = (ride.rideStatus == Ride::RideStatus::Completed);
                    break;

                default:
                    cout << "Invalid option for getRides." << endl;
                    return;
            }

            if (printRide) {
                foundRides = true;

                cout << "Pickup Location: " << ride.getPickupLocation() << endl;
                cout << "Drop-Off Location: " << ride.getDropOffLocation() << endl;
                cout << "Pickup Time: " << ride.getPickupTime() << endl;
                cout << "Rating: " << ride.getRating() << endl;
                cout << "---------------------------------------" << endl;
            }
        }

        if (!foundRides) {
            // No rides found for the specified condition
            switch (option) {
                case 'C':
                case 'c':
                    cout << "No active rides available for this passenger." << endl;
                    break;

                case 'A':
                case 'a':
                    cout << "No cancelled rides available for this passenger." << endl;
                    break;

                case 'B':
                case 'b':
                    cout << "No completed rides available for this passenger." << endl;
                    break;

                default:
                    cout << "Invalid option for getRides." << endl;
                    break;
            }
        }
    } else {
        cout << "No rides available for this passenger." << endl;
    }
}



void Passenger::cancelRide() {
    if (!rides.empty()) {
        cout << "Current Active Rides:" << endl;
        cout << "---------------------------------------" << endl;
        for (const Ride* ridePtr : rides) {
            const Ride& ride = *ridePtr;  // Dereference the pointer

            if (ride.rideStatus == Ride::RideStatus::Active) {
                cout << "Pickup Location: " << ride.getPickupLocation() << endl;
                cout << "Drop-Off Location: " << ride.getDropOffLocation() << endl;
                cout << "Pickup Time: " << ride.getPickupTime() << endl;
                cout << "ID: " << ride.id << endl;
                cout << "---------------------------------------" << endl;
            }
        }

        cout << "Enter the ride id you would like to cancel" << endl;
        int rideId;
        cin >> rideId;
        cout << endl;

        bool rideFound = false;

        for (Ride* ridePtr : rides) {
            if (ridePtr->id == rideId) {
                ridePtr->rideStatus = Ride::RideStatus::Cancelled;
                cout << "Ride cancelled" << endl;
                rideFound = true;
                break;
            }
        }

        if (!rideFound) {
            cout << "Ride not found" << endl;
        }
    }
}


void Passenger::rateRide() {
    cout << "Current Completed Rides:" << endl;
    cout << "---------------------------------------" << endl;

    bool rideFound = false;


    for (const Ride* originalRidePtr : rides) {
        const Ride& originalRide = *originalRidePtr;
        if (originalRide.rideStatus == Ride::RideStatus::Completed) {
            cout << originalRide.pickupLocation << " -> " << originalRide.dropOffLocation << endl;
            cout << originalRide.getPickupTime() << endl;
            cout << "Rating: " << originalRide.rating << endl;
            cout << "Ride ID: " << originalRide.id << endl;
            cout << "---------------------------------------" << endl;
            rideFound = true;
        }
    }

    if (!rideFound) {
        cout << "No completed rides found." << endl;
        return;
    }

    cout << "Enter Ride ID: ";
    int selectedRideId;
    cin >> selectedRideId;

    for (Ride* ridePtr : rides) {
        Ride& ride = *ridePtr;
        if (selectedRideId == ride.id && ride.rideStatus == Ride::RideStatus::Completed) {
            cout << "---------------------------------------" << endl;
            cout << "Enter Rating: ";
            float rating;
            cin >> rating;
            ride.setRating(rating);
            cout << "Ride id: " <<ride.id << endl;
            cout << "Just changed the rating of ride " << ride.getId() << " to " << ride.getRating() << endl;
            return;

        }
    }

    cout << "Invalid Ride ID or the ride is not eligible for rating." << endl;
}


void Passenger::editRide() {
    cout << "*************************************" << endl;
    cout << "            Current Rides            " << endl;
    cout << "*************************************" << endl;

    if (!rides.empty()) {
        cout << "---------------------------------" << endl;
        for (const Ride* originalRidePtr : rides) {
            const Ride& originalRide = *originalRidePtr;

            cout << "Destination: ";
            cout << originalRidePtr->pickupLocation << " -> " << originalRidePtr->dropOffLocation << endl;
            cout << "Time: ";
            cout << originalRidePtr->getPickupTime() << endl;
            cout << "ID: ";
            cout << originalRidePtr->id << endl;
            cout << "---------------------------------" << endl;

        }
    }

    cout << endl << endl;

    cout << "Enter Ride ID you wish to edit: ";
    int i;
    string str;
    char option;
    cin >> i;
    bool found = false;

    for (Ride* ridePtr : rides) {
        Ride& ride = *ridePtr;
        if (ride.id == i) {
            found = true;
            cout << "\n\n\n\n";
            while (true) {

                cout << "*************************************" << endl;
                cout << "               Ride Edit             " << endl;
                cout << "*************************************" << endl;
                cout << "** A: Size of Party:               " << ride.sizeOfParty << endl;
                cout << "** B: Including Pets:              " << ride.includesPets << endl;
                cout << "** C: Pickup Location:         " << ride.pickupLocation << endl;
                cout << "** D: Drop Off Location:       " << ride.dropOffLocation << endl;
                cout << "** F: Pickup Time:          " << ride.getPickupTime() << endl;
                cout << "** G: Handicapped:                 " << ride.handicapable << endl;
                cout << "** Q: Quit:                 " << endl;
                cout << "*************************************" << endl;
                cout << "*";
                cin >> option;
                cout << "*************************************" << endl;

                switch (option) {

                    case 'A': // Size of Party
                    case 'a':
                        cout << "Enter Size of Party: " << endl;
                        cin >> i;
                        ride.sizeOfParty = i;
                        break;

                    case 'B': // Including Pets
                    case 'b':
                        cout << "Toggling Including Pets: " << endl;
                        ride.setIncludesPets();
                        break;

                    case 'C': // Pickup Location
                    case 'c':
                        cout << "Enter Pickup Location: " << endl;
                        cin >> str;
                        ride.pickupLocation = str;
                        break;

                    case 'D': // Drop Off Location
                    case 'd':
                        cout << "Enter Drop Off Location: " << endl;
                        cin >> str;
                        ride.dropOffLocation = str;
                        break;

                    case 'F': // Pickup Time
                    case 'f':
                        ride.setPickupTime();
                        break;

                    case 'G': // Handicaped
                    case 'g':
                        cout << "Toggling Handicapable: " << endl;
                        ride.setHandicapped();
                        break;


                    case 'Q': // Quit
                        case 'q':
                            return;
                    default:
                        cout << "Invalid Option, please try again." << endl;
                        cin >> option;
                }
                break;
            }
        }

    }


    if(!found) {
        cout << "Ride not found." << endl;
    }
}


void Passenger::editInfo() {
    char option;
    float flo;
    int i;
    string str;


    cout << "*************************************" << endl;
    cout << "         Passenger Edit Menu        " << endl;
    cout << "*************************************" << endl;
    cout << "What would you like to edit?" << endl;
    cout << "A: Required Rating : " << this->getRequiredRating() << endl;
    cout << "C: Pets Allowed : " << this->getHasPets() << endl;
    cout << "D: First Name : " << this->getFirstName() << endl;
    cout << "E: Last Name : " << this->getLastName() << endl;
    switch (static_cast<int>(this->getPaymentPreference())) {
        case 1:
            str = "Cash";
            break;
        case 2:
            str = "Credit";
            break;
        case 3:
            str = "Debit";
            break;
    }

    cout << "F: Payment Type : " << str << endl;
    cout << "*";
    cin >> option;
    cout << "*************************************" << endl;


    switch (option) {
        case 'A':
            cout << "New Required Rating: " << endl;
            cin >> flo;
            this->setRequiredRating(flo);
            break;

        case 'C':
            while (true) {
                cout << "Do you have luggage storage? (Y/N) ";
                cin >> option;

                if (option == 'Y' || option == 'y') {
                    this->setHasPets(true);
                    break;
                } else if (option == 'N' || option == 'n') {
                    this->setHasPets(false);
                    break;
                } else {
                    cout << "Not a valid input, please try again: " << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

            cout << "*************************************" << endl;


        case 'D':

            cout << "New first name: " << endl;
            cin >> str;
            this->setFirstName(str);

            break;

        case 'E':
            cout << "New Last Name: " << endl;
            cin >> str;
            this->setLastName(str);
            break;

        case 'F':
            cout << "New Payment Method: " << endl;
            cout << "1. Cash " << endl;
            cout << "2. Credit " << endl;
            cout << "3. Debit: " << endl;
            cout << "*";
            cin >> i;
            this->setPaymentPreference(
                    static_cast<Passenger::PaymentPreference>(i));
            break;

        case 'Q':
            cout << "Quitting Edit Menu" << endl;
            break;

        default:
            cout << "Invalid option, try again." << endl;
    }

}


