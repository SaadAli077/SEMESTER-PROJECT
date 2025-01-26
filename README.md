Flight Reservation System Documentation
#### Overview:
The Flight Reservation System is a console-based application that permits users to view available flights, book tickets, cancel bookings, and for administrators, add new flights. The program saves booking records and flight details persistently via text files. 

#### Features:
- View all available flights.
- Get tickets in Economy or Business Class.
- Cancel an existing booking.
- New flight (Admin access is required).
- View all booked records.

- #### Running Instructions:
1. Compilation of your program using the C++ compiler:
   ```
   g++ -o flight_reservation flight_reservation.cpp
   ```
2. Run the resulting executable:
   ```
   ./flight_reservation
   ```
#### Overview of the Program:
- **Structures:**
  - `Flight`: Contains the particulars of the flight, including flight number, destination, Economy and Business class seats available, and timings.
  - `Passenger`: Represents the particulars of the passengers, such as their name, flight number, date of booking, phone number, age, and flying classes.

- **Main Functions:**
  - `loadFlights`: Loads flight details from `flights.txt` to the `Flight` array.
  - `saveFlights`: Saves current state of `Flight` array back to `flights.txt`.
  - `displayFlights`: Displays all flights in tabular format.
  - `bookFlight`: Deals with booking a flight including checking of seat availability and updating of records.
  - `cancelBooking`: Cancels a booking and its seat availability.
  - `addFlight`: Allows an administrator to add a new flight.
  - `saveBookingRecord`: Saves a new booking in `bookings.txt`.
  - `viewBookingRecords`: Displays all booking records.
 
  - #### Logic Flow:
1. At first, the program loads flight information from the text file `flights.txt`.
2. Next, a menu of operations opens up for the selection of operations by the user.
3. Next, the user selects the desired operation and the program carries the required function.
4. The access for Admin is configured with a password. ( admin123 )
5. The changes made in the application are append only once in text files.

#### File Descriptions:

- `flights.txt`: Contains information on the flights.
- `bookings.txt`: Keeps records of the passengers who have booked the flight.

#### User Manual
This section will cover the menu options offered in the program.

#### Menu Options:

1. **View Available Flights:**
   - Displays all of the flights including the flight number, destination, available seats, and timings.

2. **Make Booking:**
   - Accepts a flight number and class (economy or business) for the booking.
   - Accepts details of the Passenger: name, booking date, phone number, and age.
   - Updates the booking and saves changes on the seat availability.

3. **Cancel Booking:**
   - Accepts flight number and class for the booking that needs to be changed.
   - Updates the seat availability.

4. **Add New Flight (Admin):**
   - Needs Admin access ( password is admin123 ).
   - New flights can be added after entering all the details of the flight.

5. **View Booking Records:**
   - Shows all of the booking records which are saved under bookings.txt.

6. **Exit:**
   - Saves all of the changes before shutting down the application.

#### Notes for Users:
- Ensure `flights.txt` exists before running the program. If not, it will create one with default flight data.
- Enter valid input when prompted to avoid errors.
- Admin password is required to add new flights.
