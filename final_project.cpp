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