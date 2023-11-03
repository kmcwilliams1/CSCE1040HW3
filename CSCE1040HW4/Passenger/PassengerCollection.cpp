

#include <limits>
#include <random>
#include "PassengerCollection.h"

Passenger PassengerCollection::addPassenger(Passenger passenger) {
    while (true) {
        cout << "Enter First Name: ";
        cin >> passenger.firstName;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid first name." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    while (true) {
        cout << "Enter Last Name: ";
        cin >> passenger.lastName;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid last name." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    while (true) {
        cout << "Enter Minimum Driver Rating: ";
        cin >> passenger.requiredRating;
        if (cin.fail() || passenger.requiredRating < 0 || passenger.requiredRating > 5) {
            cout << "Invalid input. Please enter a rating between 0 and 5." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    while (true) {
        char inputChar;
        cout << "Has Pets (Y/N): ";
        cin >> inputChar;

        while (inputChar != 'Y' && inputChar != 'y' && inputChar != 'N' && inputChar != 'n') {
            cout << "Invalid input. Please enter 'Y' or 'N': ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> inputChar;
        }

        passenger.hasPets = (inputChar == 'Y' || inputChar == 'y');
        break;
    }

    int input;
    while (true) {
        cout << "Payment Preference (1 for Cash, 2 for Credit, 3 for Debit): ";
        cin >> input;
        if (cin.fail() || (input < 1 || input > 3)) {
            cout << "Invalid input. Please enter a payment preference between 1 and 3." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            passenger.paymentPreference = static_cast<Passenger::PaymentPreference>(input);
            break;
        }
    }

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 20000);
    int random_number = distribution(generator);
    passenger.id = random_number;


    cout << "Enter Password: ";
    cin >> passenger.password;

    return passenger;

}

void PassengerCollection::deletePassenger(const Passenger& passenger) {
    for (auto it = passengers.begin(); it != passengers.end(); ) {
        if (passenger.id == it->id) {
            it = passengers.erase(it);
        } else {
            ++it;
        }
    }
}
