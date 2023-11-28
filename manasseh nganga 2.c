#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_USERNAME "manasseh"
#define DEFAULT_PASSWORD "123456"
#define MAX_ROUTES 4
#define MAX_BOOKED_TICKETS 100

struct BusRoute {
    int busId;
    char name[50];
    char schedule[50];
    float price;
    int availableSeats;
};

struct Passenger {
    char name[50];
    int busId;
    int seatNumber;
};

struct BusRoute busRoutes[MAX_ROUTES] = {
    {1, "Thika Road", "08:00 AM", 10.0, 60},
    {2, "Ngong Road", "10:30 AM", 12.5, 60},
    {3, "Mombasa Road", "01:00 PM", 8.0, 60},
    {4, "Jogoo Road", "03:30 PM", 15.0, 60}
};

struct Passenger bookedTickets[MAX_BOOKED_TICKETS];
int numBookedTickets = 0;

void displayBusSchedules() {
    printf("Available Bus Routes:\n");
    printf("----------------------------\n");
    printf("Bus ID\tRoute\tSchedule\tPrice\tAvailable Seats\n");
    printf("----------------------------\n");

    for (int i = 0; i < MAX_ROUTES; i++) {
        printf("%d\t%s\t%s\t$%.2f\t%d\n", busRoutes[i].busId, busRoutes[i].name, busRoutes[i].schedule, busRoutes[i].price, busRoutes[i].availableSeats);
    }

    printf("----------------------------\n");
}

void bookTicket() {
    int routeChoice;

    printf("Enter the number of the route you want to book: ");
    if (scanf("%d", &routeChoice) != 1 || routeChoice < 1 || routeChoice > MAX_ROUTES + 1) {
        printf("Invalid route selection. Please select a valid route.\n");
        
        while (getchar() != '\n');
        return;
    }

    if (busRoutes[routeChoice - 1].availableSeats > 0) {
        struct Passenger passenger;
        printf("Enter your name: ");
        scanf(" %[^\n]", passenger.name);
        passenger.busId = busRoutes[routeChoice - 1].busId;
        passenger.seatNumber = 60 - busRoutes[routeChoice - 1].availableSeats + 1;
        busRoutes[routeChoice - 1].availableSeats--;
        bookedTickets[numBookedTickets] = passenger;
        numBookedTickets++;
        printf("You, %s, have booked a ticket for %s at %s (Bus ID: %d) for ksh%.2f. Your seat number is %d.\n", passenger.name,
               busRoutes[routeChoice - 1].name, busRoutes[routeChoice - 1].schedule, passenger.busId, busRoutes[routeChoice - 1].price, passenger.seatNumber);
    } else {
        printf("Sorry, the bus is full. Please choose another route.\n");
    }
}


void displayTickets() {
    printf("Tickets booked:\n");
    printf("Passenger name | Bus Route          | Price     | Time      | Seat Number\n");
    printf("------------------------------------------------------------------------\n");

    for (int i = 0; i < numBookedTickets; i++) {
        printf("%-15s | %-20s | ksh%.2f   | %s | %d\n",
               bookedTickets[i].name, busRoutes[i].name, busRoutes[i].price, busRoutes[i].schedule, bookedTickets[i].seatNumber);
    }
}

int main() {
    char username[60] = "";
    char password[100];
    char buffer[100];

    
    do {
        printf("Please log in:\n");
        printf("Username: ");
        scanf("%59s", username);

        
        printf("Password: ");
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0; 
        strncpy(password, buffer, sizeof(password) - 1);
        password[sizeof(password) - 1] = '\0';

        if (strcmp(username, DEFAULT_USERNAME) == 0 && strcmp(password, DEFAULT_PASSWORD) == 0) {
            printf("Login successful. Welcome, %s!\n", username);
            break;
        } else {
            printf("Login failed. Incorrect username or password. Please try again.\n");
        }
    } while (1);

    int option;

    while (1) {
        printf("\nBus Booking System\n");
        printf("1. View Bus Schedules\n");
        printf("2. Book a Ticket\n");
        printf("3. Display Tickets\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number.\n");
            
            while (getchar() != '\n');
            continue;
        }

        switch (option) {
            case 1:
                displayBusSchedules();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                displayTickets();
                break;
            case 4:
                printf("Thank you for using our bus booking system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please choose a valid option.\n");
        }
    }

    return 0;
}