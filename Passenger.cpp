#include <sstream>
#include "Passenger.h"
#include "RideCollection.h"
#include "Ride.h"

Passenger::Passenger(const string &first, const string &last, float rating,
                     bool pets, PaymentPreference paymentPref)
        : requiredRating(rating), hasPets(pets), paymentPreference(paymentPref),
          firstName(first), lastName(last) {
}

Passenger::Passenger() {

}

Passenger::~Passenger() {
    rides.clear();
}

float Passenger::getRequiredRating() const {
    return requiredRating;
}

void Passenger::setRequiredRating(float rating) {
    requiredRating = rating;
}

bool Passenger::getHasPets() const {
    return hasPets;
}

void Passenger::setHasPets() {
    hasPets = !hasPets;
}

Passenger::PaymentPreference Passenger::getPaymentPreference() const {
    return paymentPreference;
}

void Passenger::setPaymentPreference(PaymentPreference pref) {
    paymentPreference = pref;
}

string Passenger::getFirstName() const {
    return firstName;
}

void Passenger::setFirstName(const string &first) {
    firstName = first;
}

string Passenger::getLastName() const {
    return lastName;
}

void Passenger::setLastName(const string &last) {
    lastName = last;
}


void Passenger::printRides() const {

    if (!rides.empty()) {
        cout << " Rides:" << endl;
        for (const Ride ride: rides) {
            cout << "Pickup Location: " << ride.getPickupLocation() << endl;
            cout << "Drop-Off Location: " << ride.getDropOffLocation() << endl;
            cout << "Pickup Time: " << ride.getPickupTime() << endl;

            string statusString;
            switch (ride.getStatus()) {
                case Ride::RideStatus::Active:
                    statusString = "Active";
                    break;
                case Ride::RideStatus::Completed:
                    statusString = "Completed";
                    break;
                case Ride::RideStatus::Cancelled:
                    statusString = "Cancelled";
                    break;
                default:
                    statusString = "Unknown";
                    break;
            }

            cout << "Passenger.cpp::printRides status: " << static_cast<int>(ride.status) << endl;
            cout << "---------------------------------------" << endl;
        }
    } else {
        cout << "No rides available for this passenger." << endl;
    }
}


void Passenger::deleteCancelledAndCompletedRides() {

    auto it = rides.begin();

    while (it != rides.end()) {
        if (it->getStatus() == Ride::RideStatus::Cancelled || it->getStatus() == Ride::RideStatus::Completed) {
            it = rides.erase(it);
        } else {
            ++it;
        }
    }
}

void Passenger::printPassenger() const {
    cout << "Passenger Information:" << endl;
    cout << "ID: " << id << endl;
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Required Rating: " << requiredRating << endl;
    cout << "Has Pets: " << (hasPets ? "Yes" : "No") << endl;
    cout << "Payment Preference: ";
    switch (paymentPreference) {
        case PaymentPreference::Cash:
            cout << "Cash" << endl;
            break;
        case PaymentPreference::Credit:
            cout << "Credit" << endl;
            break;
        case PaymentPreference::Debit:
            cout << "Debit" << endl;
            break;
    }
}

void Passenger::addRide(Ride ride) {
    rides.push_back(ride);
}

void Passenger::setPassengerProperties(string basicString) {
    istringstream dataStream(basicString);
    string temp;

    getline(dataStream, temp, ',');
    {
        cout << "current role " << temp << endl;
    };
    getline(dataStream, temp, ',');
    {
        cout << "first name " << temp << endl;
        this->firstName = temp;
    };
    getline(dataStream, temp, ',');
    {
        cout << "last name " << temp << endl;
        this->lastName = temp;
    };
    getline(dataStream, temp, ',');
    {
        cout << "id " << temp << endl;
        this->id = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        cout << "required rating " << temp << endl;
        this->requiredRating = stof(temp);
    };
    getline(dataStream, temp, ',');
    {
        this->hasPets = (temp == "true");
    };
    getline(dataStream, temp, ',');
    {
        this->paymentPreference = static_cast<PaymentPreference>(stoi(temp));
    };
    getline(dataStream, temp, ',');
    {
        this->password = temp;
    }


//    getline(dataStream, temp, '\n');
//    {
//        cout << "trip id " << temp << endl;
//        for(int i = 0; i < temp.length(); i++) {}
//    };


}

int Passenger::getId() const {
    return 0;
}

void Passenger::setId(int id) {

}
