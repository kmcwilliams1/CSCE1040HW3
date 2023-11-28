

#include <limits>
#include <random>
#include <sstream>
#include "PassengerCollection.h"



Passenger *PassengerCollection::addPassenger() {

    auto passenger = new Passenger;
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "********************************" << endl;
    cout << "********************************" << endl;
    cout <<
            "             _   _                             \n"
            "            | \\ | | _____      __              \n"
            "            |  \\| |/ _ \\ \\ /\\ / /              \n"
            " ____       | |\\  |  __/\\ V  V /               \n"
            "|  _ \\ __ _ |_| \\_|\\___| \\_/\\_/ __ _  ___ _ __ \n"
            "| |_) / _` / __/ __|/ _ \\ '_ \\ / _` |/ _ \\ '__|\n"
            "|  __/ (_| \\__ \\__ \\  __/ | | | (_| |  __/ |   \n"
            "|_|   \\__,_|___/___/\\___|_| |_|\\__, |\\___|_|   \n"
            "                               |___/           \n";


    cout << "********************************" << endl;
    cout << "********************************" << endl << endl << endl;


    cout << "********************************" << endl;
    cout << "*     Personal Information:    *" << endl;
    cout << "********************************" << endl;


    while (true) {
        cout << "*  First Name: ";
        cin >> passenger->firstName;
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
        cout << "*  Last Name: ";
        cin >> passenger->lastName;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid last name." << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }

    cout << "*  Password: ";
    cin >> passenger->password;
    cout << "\n";


    cout << "********************************" << endl;
    cout << "*      Vehicle Information:    *" << endl;
    cout << "********************************" << endl;


    while (true) {
        cout << "Enter Minimum Driver Rating: ";
        cin >> passenger->requiredRating;
        if (cin.fail() || passenger->requiredRating < 0 || passenger->requiredRating > 5) {
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

        passenger->hasPets = (inputChar == 'Y' || inputChar == 'y');
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
            passenger->paymentPreference = static_cast<Passenger::PaymentPreference>(input);
            break;
        }
    }

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 20000);
    int random_number = distribution(generator);
    passenger->id = random_number;

    this->passengers.push_back(passenger);
    return passenger;

}

void PassengerCollection::deletePassenger(const Passenger* passenger) {
    for (auto it = passengers.begin(); it != passengers.end(); ) {
        if (passenger->id == (*it)->id) {
            delete *it;  // Don't forget to free the memory
            it = passengers.erase(it);
        } else {
            ++it;
        }
    }
}



void PassengerCollection::readPassengerProperties(const string& basicString){
    istringstream dataStream(basicString);
    string temp;
    auto *passenger = new Passenger;
    
    
    getline(dataStream, temp, ',');
    {
    };
    getline(dataStream, temp, ',');
    {
        passenger->firstName = temp;
    };
    getline(dataStream, temp, ',');
    {
        passenger->lastName = temp;
    };
    getline(dataStream, temp, ',');
    {
        passenger->id = stoi(temp);
    };
    getline(dataStream, temp, ',');
    {
        passenger->requiredRating = stof(temp);
    };
    getline(dataStream, temp, ',');
    {
        passenger->hasPets = (temp == "true");
    };
    getline(dataStream, temp, ',');
    {
        passenger->paymentPreference = static_cast<Passenger::PaymentPreference>(stoi(temp));
    };
    getline(dataStream, temp, ',');
    {
        passenger->password = temp;
    }

    getline(dataStream, temp, '\n');


    string rideId;
    passenger->rideIds.clear();
    char currentChar;

    for (char i: temp) {
        currentChar = i;
        if (currentChar != ',') {
            rideId.push_back(currentChar);
        } else {
            passenger->rideIds.push_back(stoi(rideId));
            rideId = "";
        }
    };

    this->passengers.push_back(passenger);

}
