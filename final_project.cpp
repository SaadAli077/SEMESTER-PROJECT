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