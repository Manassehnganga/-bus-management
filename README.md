Bus Booking System
This is a simple console-based Bus Booking System implemented in C. The program allows users to log in, view available bus routes, book tickets, and display booked tickets.

Features
Login System: Users are required to log in with a username and password before accessing the system. The default credentials are provided in the code.

View Bus Schedules: Users can view the available bus routes, including the route ID, name, schedule, price, and available seats.

Book a Ticket: Users can book a ticket by selecting a bus route and providing their name. The program validates the route selection and seat availability.

Display Booked Tickets: Users can view the details of the tickets they have booked, including passenger name, bus route, price, time, and seat number.

Exit: Users can exit the program at any time.

Instructions
Login:

Enter the default username: "manasseh".
Enter the default password: "123456".
Main Menu:

Choose an option from the menu:
1: View Bus Schedules
2: Book a Ticket
3: Display Tickets
4: Exit
View Bus Schedules:

Displays a list of available bus routes with their details.
Book a Ticket:

Enter the number of the route you want to book.
Enter your name.
Receives a confirmation message with booking details if successful.
Display Tickets:

Shows a list of booked tickets with passenger details and route information.
Exit:

Exits the program.
Input Guidelines
Follow the on-screen prompts for username and password.
For route selection, enter a valid route number.
Pay attention to the available seats and choose routes with available space.
Notes
The default credentials are provided in the code for demonstration purposes. For a real-world application, a more secure authentication system should be implemented.

The program utilizes a simple array-based storage for bus routes and booked tickets. For scalability, consider using a database.

Input validation is implemented to handle invalid inputs gracefully.
