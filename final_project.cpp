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
