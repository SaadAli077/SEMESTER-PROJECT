#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

struct Flight {
int flightNumber;
string destination;
int economySeatsAvailable;
int businessSeatsAvailable;
string departureTime;
string arrivalTime;
};

struct Passenger {
string name;
int flightNumber;
string bookingDate;
string phoneNumber;
int age;
string flyingClass;
};

void loadFlights(Flight flights[], int& numFlights);
void saveFlights(const Flight flights[], int numFlights);
void displayFlights(const Flight flights[], int numFlights);
void bookFlight(Flight flights[], int numFlights);
void cancelBooking(Flight flights[], int numFlights);
void addFlight(Flight flights[], int& numFlights);
void saveBookingRecord(const Passenger& passenger);
void viewBookingRecords();


 int choice; 
        do { 
            cout << "\n--- Flight Reservation System ---\n"; 
            cout << "1. View Available Flights\n"; 
            cout << "2. Book a Flight\n"; 
            cout << "3. Cancel a Booking\n"; 
            cout << "4. Add a New Flight (Admin)\n"; 
            cout << "5. View Booking Records\n"; 
            cout << "6. Exit\n"; 
            cout << "Enter your choice: "; 
 
            // Validate menu choice input 
            if (!(cin >> choice)) { 
                cin.clear(); 
                cin.ignore(10000, '\n'); 
                cout << "Invalid input. Please enter a number between 1 and 6.\n"; 
                continue; 
            }
            
      switch (choice) { 
                case 1: 
                    displayFlights(flights, numFlights); 
                    break; 
                case 2: 
                    bookFlight(flights, numFlights); 
                    break; 
                case 3: 
                    cancelBooking(flights, numFlights); 
                    break; 
                case 4: 
                    addFlight(flights, numFlights); 
                    break; 
                case 5: 
                    viewBookingRecords(); 
                    break; 
                case 6: 
                    saveFlights(flights, numFlights); 
                    cout << "Exiting the system. Goodbye!\n"; 
                    break; 
                default: 
                    cout << "Invalid choice. Please try again.\n"; 
            } 
        } while (choice != 6); 
    } catch (const exception& e) { 
        cerr << "Error: " << e.what() << endl; 
    } 
 
    return 0; 
}

// Function to load flights from a file
void loadFlights(Flight flights[], int& numFlights) {
    ifstream file("flights.txt");

    if (!file) {
        cout << "flights.txt file not found. Creating a new file with default data...\n";
        ofstream newFile("flights.txt");
        newFile << "101 NewYork 5 3 08:00 12:00\n102 London 3 2 10:00 14:00\n103 Paris 8 5 06:00 10:00\n";
        newFile.close();
        file.open("flights.txt");
    }

    if (!file) {
        throw runtime_error("Failed to open flights.txt.");
    }

    while (file >> flights[numFlights].flightNumber >> flights[numFlights].destination
                >> flights[numFlights].economySeatsAvailable >> flights[numFlights].businessSeatsAvailable
                >> flights[numFlights].departureTime >> flights[numFlights].arrivalTime) {
        numFlights++;
        if (numFlights == 100) break;
    }

    file.close();
}

// Function to save flights to a file
void saveFlights(const Flight flights[], int numFlights) {
    ofstream file("flights.txt");

    if (!file) {
        throw runtime_error("Failed to save to flights.txt.");
    }

    for (int i = 0; i < numFlights; i++) {
        file << flights[i].flightNumber << " " << flights[i].destination << " "
             << flights[i].economySeatsAvailable << " " << flights[i].businessSeatsAvailable << " "
             << flights[i].departureTime << " " << flights[i].arrivalTime << "\n";
    }

    file.close();
}

void displayFlights(const Flight flights[], int numFlights) {
    cout << "\nAvailable Flights:\n";
    cout << "Flight Number    Destination        Economy Seats    Business Seats    Departure Time    Arrival Time\n";
    cout << "------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < numFlights; i++) {
        cout << flights[i].flightNumber << "              " 
             << flights[i].destination << "              " 
             << flights[i].economySeatsAvailable << "               " 
             << flights[i].businessSeatsAvailable << "               "
             << flights[i].departureTime << "              "
             << flights[i].arrivalTime << "\n";
    }
}

// Function to book a flight
void bookFlight(Flight flights[], int numFlights) {
    int flightNumber;
    cout << "Enter the flight number to book: ";
    cin >> flightNumber;

    bool flightFound = false;
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].flightNumber == flightNumber) {
            flightFound = true;

            string flyingClass;
            cout << "Choose flying class (Economy/Business): ";
            cin >> flyingClass;

            if (flyingClass == "Economy") {
                if (flights[i].economySeatsAvailable > 0) {
                    flights[i].economySeatsAvailable--;
                } else {
                    cout << "No Economy seats available.\n";
                    return;
                }
            } else if (flyingClass == "Business") {
                if (flights[i].businessSeatsAvailable > 0) {
                    flights[i].businessSeatsAvailable--;
                } else {
                    cout << "No Business seats available.\n";
                    return;
                }
            } else {
                cout << "Invalid class. Please choose 'Economy' or 'Business'.\n";
                return;
            }

            Passenger p;
            cout << "Enter your name: ";
            cin >> p.name;
            p.flightNumber = flightNumber;

            cout << "Enter booking date (DD/MM/YYYY): ";
            cin >> p.bookingDate;

            cout << "Enter your phone number: ";
            cin >> p.phoneNumber;

            cout << "Enter your age: ";
            cin >> p.age;

            p.flyingClass = flyingClass;

            saveBookingRecord(p);
            cout << "Booking successful! Seats left - Economy: " 
                 << flights[i].economySeatsAvailable 
                 << ", Business: " << flights[i].businessSeatsAvailable << "\n";
            return;
        }
    }

    if (!flightFound) {
        cout << "Flight number not found. Please try again.\n";
    }
}

// Function to cancel a booking
void cancelBooking(Flight flights[], int numFlights) {
    int flightNumber;
    cout << "Enter the flight number to cancel booking: ";
    cin >> flightNumber;

    bool flightFound = false;
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].flightNumber == flightNumber) {
            flightFound = true;

            string flyingClass;
            cout << "Enter flying class (Economy/Business) for cancellation: ";
            cin >> flyingClass;

            if (flyingClass == "Economy") {
                flights[i].economySeatsAvailable++;
            } else if (flyingClass == "Business") {
                flights[i].businessSeatsAvailable++;
            } else {
                cout << "Invalid flying class.\n";
                return;
            }

            cout << "Booking canceled successfully! Seats available - Economy: " 
                 << flights[i].economySeatsAvailable
                 << ", Business: " << flights[i].businessSeatsAvailable << "\n";
            return;
        }
    }

    if (!flightFound) {
        cout << "Flight number not found. Please try again.\n";
    }
}

// Function to add a new flight
void addFlight(Flight flights[], int& numFlights) {
    const string ADMIN_PASSWORD = "admin123";
    int attempts = 0;

    while (attempts < 3) {
        string enteredPassword;
        cout << "Enter admin password: ";
        cin >> enteredPassword;

        if (enteredPassword == ADMIN_PASSWORD) {
            break;
        } else {
            attempts++;
            cout << "Incorrect password. Attempts left: " << (3 - attempts) << "\n";
        }
    }

    if (attempts == 3) {
        cout << "Access denied. Maximum attempts reached.\n";
        return;
    }

    if (numFlights >= 100) {
        cout << "Cannot add more flights. Maximum limit reached.\n";
        return;
    }

    Flight newFlight;
    cout << "Enter flight number: ";
    cin >> newFlight.flightNumber;
    cout << "Enter destination: ";
    cin >> newFlight.destination;
    cout << "Enter departure time (HH:MM): ";
    cin >> newFlight.departureTime;
    cout << "Enter arrival time (HH:MM): ";
    cin >> newFlight.arrivalTime;
    cout << "Enter number of Economy seats available: ";
    cin >> newFlight.economySeatsAvailable;
    cout << "Enter number of Business seats available: ";
    cin >> newFlight.businessSeatsAvailable;

    flights[numFlights] = newFlight;
    numFlights++;

    saveFlights(flights, numFlights);
    cout << "Flight added successfully.\n";
}

// Function to save booking record to a file
void saveBookingRecord(const Passenger& passenger) {
    ofstream file("bookings.txt", ios::app);
    if (!file) throw runtime_error("Failed to open bookings.txt.");

    file << passenger.flightNumber << " " << passenger.name << " "
         << passenger.bookingDate << " " << passenger.phoneNumber << " "
         << passenger.age << " " << passenger.flyingClass << "\n";

    file.close();
}


void saveBookingRecord(const Passenger& passenger) {
ofstream file("bookings.txt", ios::app);
if (!file) throw runtime_error("Failed to open bookings.txt.");
file << passenger.flightNumber << " " << passenger.name << " "
<< passenger.bookingDate << " " << passenger.phoneNumber << " "
<< passenger.age << " " << passenger.flyingClass << "\n";
file.close();
}

void viewBookingRecords() {
ifstream file("bookings.txt");
if (!file) {
cout << "No booking records found.\n";
return;
}
cout << "\nBooking Records:\n";
cout << "Flight Number Name Booking Date Phone Number Age Flying
Class\n";
cout << "--------------------------------------------------------------------------------------------\n";
Passenger p;
while (file >> p.flightNumber >> p.name >> p.bookingDate >> p.phoneNumber >> p.age >>
p.flyingClass) {
cout << p.flightNumber << " " << p.name << " "
<< p.bookingDate << " " << p.phoneNumber << " "
<< p.age << " " << p.flyingClass << "\n";
}
file.close();
}
