#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#define MAX_BOOKINGS 50
#define MAX_NAME_LENGTH 20
#define MAX_BUSES 20
#define NUM_ROWS 8
#define NUM_COLUMNS 4
#define MAX_EMPLOYEES 20
#define NUM_ROUTES 15

//struct to represent a bus schedule
typedef struct {
	char destination[MAX_NAME_LENGTH] ;
	char departure[MAX_NAME_LENGTH] ;
	int totalSeats ;
	int seatsAvailable ;
} BusSchedule;

//struct to represent an employee
typedef struct {
char usernameEmployee[MAX_NAME_LENGTH];
char passwordemployee[MAX_NAME_LENGTH];
} Employee; 

int numBookings = 0;
int numBuses  = 0;
int numEmployees  = 0;
int numRoutes  = 15;

//Array to represent all buses routes
char busDetails[NUM_ROUTES][2][MAX_NAME_LENGTH] = {
	{"Naivasha", "Meru"},
	{"Naivasha", "Mombasa"},
	{"Naivasha", "Nairobi"},
	{"Naivasha", "Mwea"},
	{"Naivasha", "Nakuru"},
	{"Naivasha", "Machakos"},
	{"Nairobi", "Kitui"},
	{"Nairobi", "Kisii"},
	{"Nairobi", "Kisumu"},
	{"Nairobi", "Eldoret"},
	{"Nakuru", "Baringo"},
	{"Nakuru", "Bungoma"},
	{"Nakuru", "Taita taveta"},
	{"Nakuru", "Nairobi"},
	{"Nakuru", "Namanga"}
};

char seatAvailability[NUM_ROWS][2][NUM_COLUMNS] = {
	{
		{1, 0, 0, 1},
	    {1, 1, 0, 1}
	},
	{   	
  		{1, 0, 1, 1},
		{0, 0, 0, 0}
	},
	{
		{1, 0, 0, 0},
		{0, 1, 0, 1}
	},
	{		
		{0, 0, 0, 1},
		{0, 1, 1, 1}
	}
 };

// Function to add a new bus schedule
void addBusSchedule(char busDetails[NUM_ROUTES][2][MAX_NAME_LENGTH]) {
 	  
	char destination[MAX_NAME_LENGTH]; 
	char departure [MAX_NAME_LENGTH];
	
	printf("Enter place of departure: ");
	scanf("%s", departure);
	printf("Enter the destination: ");
	scanf("%s", destination);
	
	strcpy(busDetails[NUM_ROUTES][0], departure);
	strcpy(busDetails[NUM_ROUTES][1], destination);
	
	
	printf("New bus schedule added: %s to %s\n", departure, destination);
}
 
// Function to view all bus schedules
int viewAllBusSchedules(char busDetails[NUM_ROUTES][2][MAX_NAME_LENGTH]) {
	
	int i;
	printf("--------------------All Buses Available-------------------------\n");
	
	for(i = 0; i < NUM_ROUTES; i++){
		printf("Route %d: %s to %s\n", i + 1, busDetails[i][0], busDetails[i][1]);
	}
	
			
	return 0;
}

// Function to delete a bus schedule
void deleteBusSchedule(char busDetails[NUM_ROUTES][2][MAX_NAME_LENGTH]) {
	
	int routeIndex;
	printf("------------------------Existing Bus Schedules--------------------------------\n");
	
	for (int i = 0; i <numRoutes; ++i) {
		printf("%d: %s to %s\n", i + 1, busDetails[i][0], busDetails[i][1]);
	}
	printf("-------------------------------------------------------------------------------\n");
	printf("Enter the number of bus schedule to delete: \n");
	scanf("%d", &routeIndex);
	printf("-------------------------------------------------------------------------------\n");
	
	if (routeIndex >= 1 && routeIndex <= numRoutes) {
		// Delete the bus schedule by shifting elements to overwrite the one being deleted
		for (int i = routeIndex - 1; i < numRoutes - 1; ++i){
			strcpy(busDetails[i][0], busDetails[i + 1][0]);
			strcpy(busDetails[i][1], busDetails[i + 1][1]);
		}
		(numRoutes)--; // Decrement in the number of routes
		printf("----------------------------------------------------------------------------\n");
		printf("Bus schedule deleted successfully!\n");
	} else {
		printf("----------------------------------------------------------------------------\n");
		printf("Invalid bus schedule number. No deletions made in the system.\n");
		printf("---------------------------------------------------------------------------\n");
	}
} 

// Function to modify a bus schedule
void modifyBusSchedule(char busDetails[NUM_ROUTES][2][MAX_NAME_LENGTH], int numRoutes) {
	int routeIndex;
	
	    printf("-------------------------------------------------------------------------------\n"); 
		printf("Existing Bus Schedules:\n");
		printf("-------------------------------------------------------------------------------\n");
		//This will print out all the bus schedules in place in the current system
			for (int i = 0; i < numRoutes; ++i) {
		 printf("%d: %s to %s\n", i + 1, busDetails[i][0], busDetails[i][1]);
	}
	printf("-----------------------------------------------------------------------------------\n");
	printf("Enter the number of the bus schedule to modify: \n");
	scanf("%d", &routeIndex);
	printf("-----------------------------------------------------------------------------------\n");
	
	if (routeIndex >= 1 && routeIndex <= numRoutes) {
		// Modify the bus schedules
		routeIndex--; // Adjust index to match array index
		printf("Enter the new place of departure: ");
		scanf("%s", busDetails[routeIndex][0]);
		printf("------------------------------------------------------------------------------\n");
		printf("Enter the new destination: ");
		scanf("%s", busDetails[routeIndex][1]);
		printf("------------------------------------------------------------------------------\n");
	    printf("Bus schedule modified successfully!\n");
	    printf("------------------------------------------------------------------------------\n");
	} else {
		printf("------------------------------------------------------------------------------\n");
		printf("Invalid bus schedule number. No modifications made.\n");
		printf("------------------------------------------------------------------------------\n");
	}
		
}

//Function to search for buses based on departure and destination
int searchBus(char busDetails[NUM_ROUTES][2][MAX_NAME_LENGTH], int numRoutes, char* departure, char* destination, char *seatAvailability[NUM_ROWS][2][NUM_COLUMNS]){
    int choice;
    bool busFound = false;

    printf("Enter the place of departure: ");
    scanf("%s", departure);
    printf("Enter the destination: ");
    scanf("%s", destination);

    // Iterate through the array to find the bus 
    for (int i = 0; i < numRoutes; ++i) {
	    if (strcmp(busDetails[i][0], departure) == 0 && strcmp(busDetails[i][1], destination) == 0){
	    	busFound = true;
	    	break;
	    }
    }
  
     // Display the result to the user
     if (busFound) {
    	printf("Bus from %s to %s is available.\n", departure, destination);
    	printf("Do you want to book this bus? \n!. Yes\n2. No\n");
  	    scanf("%d", &choice);
  	
  	    if  (choice == 1) {
			 searchBus();
		     return 0;
	    } else if (choice == 2) {
	  	   return;
	    } else {
	        printf("Invalid option");
	    }
	 
    } else  {
     	printf("Bus from %s to %s is not available.\n", departure, destination);
   }
}

// Function to view all available seats for a bus
int viewAvailableSeats(char seatsAvailability[NUM_ROWS][2][NUM_COLUMNS]) {
	printf("Available Seats:\n");
	printf("  A B C D\n");
	printf("1. %d %d %d %d\n", *seatAvailability[0][0], *seatAvailability[0][1], *seatAvailability[0][2], *seatAvailability[0][3]);
	printf("2. %d %d %d %d\n", *seatAvailability[1][0], *seatAvailability[1][1], *seatAvailability[1][2], *seatAvailability[1][3]);
	printf("3. %d %d %d %d\n", *seatAvailability[2][0], *seatAvailability[2][1], *seatAvailability[2][2], *seatAvailability[2][3]);
	printf("4. %d %d %d %d\n", *seatAvailability[3][0], *seatAvailability[3][1], *seatAvailability[3][2], *seatAvailability[3][3]);
	printf("5. %d %d %d %d\n", *seatAvailability[4][0], *seatAvailability[4][1], *seatAvailability[4][2], *seatAvailability[4][3]);
	printf("6. %d %d %d %d\n", *seatAvailability[5][0], *seatAvailability[5][1], *seatAvailability[5][2], *seatAvailability[5][3]);
	printf("7. %d %d %d %d\n", *seatAvailability[6][0], *seatAvailability[6][1], *seatAvailability[6][2], *seatAvailability[6][3]);
	printf("8. %d %d %d %d\n", *seatAvailability[7][0], *seatAvailability[7][1], *seatAvailability[7][2], *seatAvailability[7][3]);
	
	int checkSeatAvailability();	
	int printfBusLayout();
	
	 /*	for (int i = 0; i < NUM_ROWS;  i++) {
		for (int j = 0; j < NUM_COLUMNS;j ++) {
			if (seatAvailability[i][j] == 1) {
				printf("0 ");
             } else {
             	printf("X ");
         }
         printf("\n");
        }
     }*/
     return 0;
}

int isSeatAvailable(int row , int column){
	return seatAvailability[row][0][column]  == 0 && seatAvailability[row][1][column]  == 0;


// Function to book a seat
void bookSeat() 
{
      seatAvailability[row][0][column]  = 1;
      seatAvailability[row][1][column]  = 1; 
      return;
}
}

void printfBusLayout() {
	printf("Bus Layout (1 represents booked seat, 0 represents available seat):\n");
	for (int i = 0; i <NUM_ROWS; i++) {
		for (int j = 0; j <NUM_COLUMNS; j++) {
			printf("%d ", seatAvailability[i][0][j]  || seatAvailability[i][1][j]);
		}
		printf("\n");
	}
}

void checkSeatAvailability(){
	int row, column;
	printf("Enter row number (0 to 7): ");
	scanf("%d", &row);
	printf("Enter column number (0 to 3): ");
	scanf("%d", &column);
	
	if (row >= 0 && row < NUM_ROWS && column >= 0 && column < NUM_COLUMNS) {
		if (isSeatAvailable(row, column)) {
			int totalAmount = calculateTotalAmount();
			printf("Seat at row %d, column %d is available! Amount to pay: %dsh/=\n", row, column, totalAmount);
			
			int userAmount;
			printf("Enter the amount to pay: sh");
			scanf("%d", &userAmount);
			
			if (userAmount == totalAmount){
				int bookSeat(row, column);
				printf("Seat at row %d, column %d has been booked.\n", row, column);
			int	printfReceipt();
			int	saveReceiptToFile();
				
			} else {
				printf("Seat at row %d, column %d is not available.\n", row, column);
			}
		} else {
			printf("Invalid seat number.\n");
		}
		return;
	}


int calculateTotalAmount() {
	int SEAT_COST = 800;
	return SEAT_COST;
}
}

int checkBookingStatus(int row, int column){
	if (isSeatAvailable(row, column)){
		return 0; // Booking failed
	} else {
		return 1; //Booking successful
	}
	return 0; 
}

// Function to issue a receipt
int printfReceipt(int *row, int *column, int *totalAmount) {
	printf("Booking Successful!\n");
	printf("Receipt:\n");
	printf("Seat Number: Row %d, Column %d\n", row, column);
	printf("Amount Paid: $&d\n", totalAmount);
	return 0;
} 

int saveReceiptToFile(int row, int column, int totalAmount) {
	FILE *file = fopen("receipt.txt", "a"); 
	if  (file != NULL) {
		fprintf(file, "Seat Number: Row %d, Column %d", row, column);
		
	    fprintf(file, "Amount Paid: $%d\n", totalAmount);
		fprintf(file, "------------------------\n");
		fclose(file);  	
	} else {
		printf("Error: Unable to open the file for writing.\n");
	}
	return 0;
}

// Function to cancel a booking
void cancelBooking() {
	char password[15]; // Password for authentication
	char inputPassword[15]; // User input for password
	
    // Set the correct password
    strcpy(password, "ventura"); // Replace "your password" with the actual password
    
     printf("Enter password to cancel the booking: ");
     scanf("%s", inputPassword);
     
     // Compare the input password with the correct password
     if (strcmp(inputPassword, password) == 0){
		 // Authentication successful, allow cancellation
		 printf("Booking cancellation successful!\n");
		 // Code to remove booking information from receipt.txt
		 // implementation depends on how booking information is stored in the file
		 // Here is an example on how you might remove a specific line containing the booking information:
		 FILE *inputFile = fopen("receipt.txt", "r");
		 FILE *tempFile = fopen("temp.txt", "w");
		 
		 char line[100];
		  int bookingFound = 0;
		  
		  while(fgets(line, sizeof(line), inputFile)){
			  // If line contains the booking information, skip it (removing from file)
			  if (strstr(line, "Seat Number: Row 2, Column 3") != NULL) {
				  bookingFound = 1;
				  continue;
			  }
			  fprintf(tempFile, "%s", line);
		  }
		 
		  fclose(inputFile);
		  fclose(tempFile);
		  
		  // Remove the original file and rename the temporary file to the original file
		  remove("receipt.txt");
		  rename("temp.txt", "receipt.txt");
		  
		  if (bookingFound) {
			 printf("Booking information removed from receipt.txt\n");
		  } else {
			  printf("Booking information not found in receipt.txt\n");
		  }
	} else {
		 //Authentication failed
		 printf("Incorrect password. Booking cancellation failed.\n");
	 }
}

// Functiom to view booking history
void viewBookingHistory() {
	FILE *file = fopen("receipt.txt", "r");
	if (file == NULL) {
		printf("Error: Unable to open receipt file.\n");
		return;
	}
	
	char line[100];
	
	printf("Booking History:\n");
	printf("--------------------------------------\n");
	
	// Display booking history from the file
	while (fgets(line, sizeof(line), file)){
		printf("%s", line);
	}

	fclose(file);
}

// Function to register a newEmployee
void signUp(FILE *details) {
char username[30];
char password[30];
 printf("--------------------------------------------------------------------------------\n");
 printf("Enter username: ");
 scanf("%s",username);
 printf("---------------------------------------------------------------------------------\n");
 printf("Enter password");
scanf("%s",password);
printf("-----------------------------------------------------------------------------------\n");

fprintf(details,"%s %s\n", username, password);
printf("-----------------------------------------------------------------------------------\n");
printf("Registration successful!\n");
printf("------------------------------------------------------------------------------------\n");

}

 // Function to validate employee login
 int login (FILE *details) {
 	char username[30];
 	char password[30];
 	char fileusername[30];
 	char filepassword[30];
	  
    printf("-----------------------------------------------------------------------------\n");	
 	printf("Enter your username: ");
 	scanf("%s", username);
 	printf("------------------------------------------------------------------------------\n");
 	printf("Enter your password: ");
 	scanf("%s", password);
 	rewind (details); // Reset file pointer to the beginning
 	
 	while(fscanf(details, "%s %s", fileusername, filepassword) != EOF) {
      if (strcmp(username, fileusername) == 0 && strcmp(password, filepassword) == 0) {
          printf("-----------------------------------------------------------------------------\n");
          printf("login successful !\n");
          printf("----------------------------------------------------------------------------------\n");
          return 1;
	  }
	}
	 printf("-----------------------------------------------------------------------------------\n");
	 printf("login unsuccessful.check your details.\n");
	 printf("------------------------------------------------------------------------------------\n");
	 return 0;
 }
 
 int main() {
 	
 	FILE*details;
 	details = fopen("details.txt", "a+"); // Open or create the details file
 	
 	char departure[MAX_NAME_LENGTH];
 	char destination[MAX_NAME_LENGTH];
 	
 	if (details == NULL) {
 		printf("---------------------------------------------------------------------------\n");
 		printf("Error: Could not open the details file.\n");
 		printf("---------------------------------------------------------------------------\n");
 		return 1;
	 }
	 
	 int choice1;
	 int choice2;
	 printf("------------------------------------------------------------------------------\n");
	 printf("***************************welcome to the login page!*************************\n");
	 printf("------------------------------------------------------------------------------\n");
	 
	 while (1) {
		 	printf("Select:\n");
		 	printf("1.SignUp\n");
		 	printf("2.Login\n");
		 	printf("3.Exit\n");
		 	scanf("%d", &choice1);
		 	
		 	switch (choice1) {
		 		case 1:
		 		signUp(details);
		 		break;
		 	case 2:
		 		if (login(details)) {
		 			
		 			while  (1) {
						 printf("choose an option:\n");
						 printf("----------------------------------------------------------\n");
						 printf("1. Add new bus schedule\n");
						 printf("2. view bus schedule\n");
						 printf("3. Delete bus schedule\n");
						 printf("4. Modify bus schedule\n");
						 printf("5. Search bus\n");
						 printf("6. Cancel a booking\n");
						 printf("7. View booking history\n");
						 printf("-----------------------------------------------------------\n");
						 
						 scanf("%d", &choice2);
						 
						 switch (choice2) {
							 case 1:
							 	addBusSchedule(busDetails);
							 	break;
							 case 2:
							 	viewAllBusSchedules(busDetails);
							 	break;
							 case 3:
							 	deleteBusSchedule(busDetails);
							 	break;
							 case 4:
							 		modifyBusSchedule(busDetails, numRoutes);
							 		break;
							 case 5:
							 		searchBus(busDetails, NUM_ROUTES, departure, destination, seatAvailability);
								break;
							 case 6:
							 	cancelBooking();
							 	break;
							 case 7:
							 	viewBookingHistory();
							 	break;
							 case 8:
							 	printf("***************************THANK YOU******************\n");
							 	printf("------------------------------------------------------\n");
							 		return 0;
						 }
					 }
				 }
				    break;
			 case 3:
			 	printf("********************************bye******************************\n");
			 	fclose(details);
			 	return 0;
			 	default:
			 		printf("invalid choice. please try again.\n");
			 		break;
			 }
		 }
		 

return 0;
}	 
	 
		 
	

	
	

	
 
