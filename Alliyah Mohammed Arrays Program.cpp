/*******************Concert Ticket Database*****************/
/*     This program uses array's. The user is met with     */
/*     an array of concert tickets, and their prices.      */
/*     They then must enter the tickets and quantity       */
/*     and the program will calculate the final price      */
/*     and display this information.                       */
/*                                                         */  
/*				Programmer: Alliyah Mohammed               */
/*				Date: December 8th, 2016                   */
/***********************************************************/
 
/*------Preprocessing Directives------*/
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <windows.h>

int main(void)
{
	//Console title
	system("TITLE Alliyah Mohammed - Concert Ticket Database ");

	//Code for coloured text
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs; 
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
    
	
/*------Declare Variables-------*/
	int count;
	int row, col;
	char name[20]; //User's name 
	char concerts[5][20] = {"Madeon", "Chime", "San Holo", "Savant", "Zomboy"}; //5 element 20 string array
	int code[5] = {1,2,3,4,5}; //Ticket code
	float ticketCost[30] = {25.45, 26.37, 30.00, 29.98, 28.41}; //Single array for cost
	int chosenConcert = 0; //Concert chosen 
	int qtyTickets = 0; //Tickets being purchased 
	float totalCost = 0; //Final cost
	float tax = 1.13; //tax
	int reset; //Reset variable
	char choices[5][20] = {"Name", "Concert", "Ticket Price", "Qty of Tickets", "Total Cost"}; //Array for output
	int correct; //Check user input

 
	do //Do-while to execute program and restart if needed
	{
	//Text colour is white
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
	system("cls");
	printf("\n\t\t\t\t\t  Welcome to the concert ticket database!\n");
	
	do //Do while to check for error in input 
	{
		//Text colour is white
	    SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );

		//Prompt user to enter their name
		printf("\n\t\t\t\tPlease enter your name to begin and press ENTER: ");
		scanf("%s", name);
		fflush(stdin);
		
		//Text colour now red
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

		printf("\n\t\t\tAre you sure you entered %s? Enter 1 for YES and 2 for NO and press ENTER: ", name);
		scanf("%d", &correct);

	}while(correct != 1); //end of nested do while 

	//Text colour is white
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );

	printf("\n\t\t\t    Here are the concerts available as well as the ticket prices and codes.\n\n");
	
	//Text colour is Light Blue
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY );

	//Titles for array
	printf("\t\t\t\t\t Concert \t Ticket Price \t Ticket Code\n");
	printf("\t\t\t\t\t____________________________________________\n");
	
	for(row = 0; row < 5; row++) //Array of concert information 
	{
		printf("\t\t\t\t\t  %s \t    $%.2f \t       %d \n", concerts[row], ticketCost[row], code[row]);
		printf("\t\t\t\t\t____________________________________________\n");
	}
	
	
	do //Do while to check for error in input
	{
		//Text colour is Yellow
	    SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );

		//Prompt user to enter ticket code
		printf("\n\tPlease enter the ticket code of the concert you would like to buy tickets for and press ENTER: ");
		scanf("%d", &chosenConcert);
		fflush(stdin);
		
		//Text colour now red
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

		printf("\n\t\t\tAre you sure you entered %d? Enter 1 for YES and 2 for NO and press ENTER: ", chosenConcert);
		scanf("%d", &correct);

	}while(correct != 1); //End of nested do while
	

	do //Do while to check for error in input
	{
		//Text colour is Yellow
	    SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );

		//Prompt user to enter number of tickets
		printf("\n\t\t\tPlease enter the number of tickets you would like to buy and press ENTER: "); 
		scanf("%d", &qtyTickets);
		fflush(stdin);
		
		//Text colour now red
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

		printf("\n\t\t\tAre you sure you entered %d? Enter 1 for YES and 2 for NO and press ENTER: ", qtyTickets);
		scanf("%d", &correct);

	}while(correct != 1); //End of nested do while

	switch(chosenConcert) //Determine the price of tickets
	{

	case 1:chosenConcert = 1;
		   //Calculate the total cost for concert 1
		   totalCost = ticketCost[0] * qtyTickets * tax;
		   printf("\n\t\t\t\t\t   The total cost including tax is $%.2f\n", totalCost);

		   	for(row = 0; row <1; row++) //Array for info output
	{
		//Text colour now Blue
		SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
		printf("\n\n\t\t      \t%s   \t\t%s     %s    %s     %s", choices[row], choices[1], choices[2], choices[3], choices[4]);
		for(col = 0; col <1; col++)
		{
		//Text colour now Pink
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
		printf("\n\t\t\t%s   \t %s    \t$%.2f         \t  %d  \t\t$%.2f\n\n", name, concerts[0], ticketCost[0], qtyTickets, totalCost);
		}//End of inner loops
	
	}//End of outer for loop
		   break; 

	case 2:chosenConcert = 2;
		   //Calculate the total cost for concert 2
		   totalCost = ticketCost[1] * qtyTickets * tax;
		   printf("\n\t\t\t\t\t   The total cost including tax is $%.2f\n", totalCost);

		   	for(row = 0; row <1; row++) //Array for info output
	{
		//Text colour now Blue
		SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
		printf("\n\n\t\t      \t%s   \t\t%s     %s    %s     %s", choices[row], choices[1], choices[2], choices[3], choices[4]);
		for(col = 0; col <1; col++)
		{
		//Text colour now Pink
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
		printf("\n\t\t\t%s   \t %s    \t$%.2f         \t  %d  \t\t$%.2f\n\n", name, concerts[1], ticketCost[1], qtyTickets, totalCost);
		}//End of inner loops
	
	}//End of outer for loop
		   break;

	case 3:chosenConcert = 3;
		   //Calculate the total cost for concert 3
		   totalCost = ticketCost[2] * qtyTickets * tax;
		   printf("\n\t\t\t\t\t   The total cost including tax is $%.2f\n", totalCost);

		   	for(row = 0; row <1; row++) //Array for info output
	{
		//Text colour now Blue
		SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
		printf("\n\n\t\t      \t%s   \t\t%s     %s    %s     %s", choices[row], choices[1], choices[2], choices[3], choices[4]);
		for(col = 0; col <1; col++)
		{
		//Text colour now Pink
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
		printf("\n\t\t\t%s   \t %s    \t$%.2f         \t  %d  \t\t$%.2f\n\n", name, concerts[2], ticketCost[2], qtyTickets, totalCost);
		}//End of inner loops
	
	}//End of outer for loop
		   break;

	case 4:chosenConcert = 4;
		   //Calculate the total cost for concert 4
		   totalCost = ticketCost[3] * qtyTickets * tax;
		   printf("\n\t\t\t\t\t   The total cost including tax is $%.2f\n", totalCost);

		   	for(row = 0; row <1; row++) //Array for info output
	{
		//Text colour now Blue
		SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
		printf("\n\n\t\t      \t%s   \t\t%s     %s    %s     %s", choices[row], choices[1], choices[2], choices[3], choices[4]);
		for(col = 0; col <1; col++)
		{
		//Text colour now Pink
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
		printf("\n\t\t\t%s   \t %s    \t$%.2f         \t  %d  \t\t$%.2f\n\n", name, concerts[3], ticketCost[3], qtyTickets, totalCost);
		}//End of inner loops
	
	}//End of outer for loop
		   break;
		   
	case 5:chosenConcert = 5;
		   //Calculate the total cost for concert 5
		   totalCost = ticketCost[4] * qtyTickets * tax;
		   printf("\n\t\t\t\t\t   The total cost including tax is $%.2f\n", totalCost);

		   	for(row = 0; row <1; row++) //Array for info output
	{
		//Text colour now Blue
		SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
		printf("\n\n\t\t      \t%s   \t\t%s     %s    %s     %s", choices[row], choices[1], choices[2], choices[3], choices[4]);
		for(col = 0; col <1; col++)
		{
		//Text colour now Pink
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
		printf("\n\t\t\t%s   \t %s    \t$%.2f         \t  %d  \t\t$%.2f\n\n", name, concerts[4], ticketCost[4], qtyTickets, totalCost);
		}//End of inner loops
	
	}//End of outer for loop
		   break;


	default: //Error message for invalid code
			 //Text colour now red
			 SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );
			 printf("\n\t\t\t\t\t   It seems you did not enter a valid code!\n");
		     printf("\t\t\t\t\t     Please restart or exit the program.\n");
	 }//End of switch structure

	do //Check for error in user input
	{

		//Prompt user to exit or restart
		//Text colour now Green 
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
		printf("\n\t\t\t\t\t    Would you like to restart the program?");
		printf("\n\n\t\t\t\t      Enter 1 to quit or 2 to restart and press ENTER: ");
		scanf("%d", &reset);

		//Text colour now red
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

		printf("\n\t\t\tAre tou sure you entered %d? Enter 1 for YES and 2 for NO and press ENTER: ", reset);
		scanf("%d", &correct);

	}while(correct != 1); //End of nested do while 

		

	}while(reset != 1); //End of do-while structure

	//Text colour is white
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );

	printf("\n\n\t\t\t\t\t      Thank you for using this program!\n\n");
	//Text colour is Light Blue
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY );

	//Music Note Image	
	printf("\n\t\t\t~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~");
	printf("\n\t\t\t*     ____               ____              ____              ____               *");
	printf("\n\t\t\t~    |    |             |    |            |    |            |    |              ~");
	printf("\n\t\t\t*    |    |             |    |            |    |            |    |              *");
	printf("\n\t\t\t~   (|   (|            (|   (|           (|   (|           (|   (|              ~");
	printf("\n\t\t\t*                                                                               *");
	printf("\n\t\t\t~                                                                               ~");
	printf("\n\t\t\t*              ____               ____              ____               ____     *");
	printf("\n\t\t\t~             |    |             |    |            |    |             |    |    ~");
	printf("\n\t\t\t*             |    |             |    |            |    |             |    |    *");    
	printf("\n\t\t\t~            (|   (|            (|   (|           (|   (|            (|   (|    ~");
	printf("\n\t\t\t*                                                                               *");
	printf("\n\t\t\t~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ \n\n");

	//Text colour is white
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
	
	printf("\n\t\t\t\t\t\t     Press ENTER to exit...\n\n\t\t\t\t\t\t  ");

	getch();

	return 0;
}//End of main function 

