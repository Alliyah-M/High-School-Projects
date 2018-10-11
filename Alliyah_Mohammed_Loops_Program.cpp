/*-------------------Factorial Calculator--------------------*/
/*     This program uses loops. It will calculate            */
/*     the factorial of the integer inputted by the          */
/*     user. It will then print this along with their        */
/*     their name and an ending message.                     */
/*         PROGRAMMER: Alliyah Mohammed                      */
/*         RUN DATE: November 16th, 2016                     */
/*-----------------------------------------------------------*/

/*--------Preprocessing Directives--------*/

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

/*--------Main Module--------*/
int main(void)
{
	system(" TITLE Alliyah Mohammed - Factorial Calculator"); //Console title
    
	//Change settings for coloured text 
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

/*--------Variables--------*/ 
	char name[15];     //User's name
	int restart;       //Restart 
	char correct;      //Error checking 
	int integer = 0;   //User inputted integer
	int count = 0;     //Variable for calculation 
	int factorial = 1; //Factorial value 

/*--------Conditional Statements----------*/ 

	do //Do while loop to get user input and do calculations 
	{

	system("cls"); //Clear screen

	//Change text colour to LIGHT BLUE 
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

	printf("\n\t\t\t\t\tWelcome to the factorial Calculator!\n");
	printf("\n\t\t\tThis program will calculate the factorial of any integer you enter.");

	//Change text colour to BLUE 
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
	printf("\n\n\t\t\t\tThe factorial of a non-negative integer n, denoted by n!,");
	printf("\n\t\t\t    is the product of all positive integers less than or equal to n.");

    //Prompt user to enter their name
	printf("\n\t\t\t\tTo begin, please enter your name and press ENTER: ");
	scanf("%s", name);
	fflush(stdin);
    
	//Change text colour to PINK
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );

	//Prompt user to enter an integer
	printf("\n\t\tPlease enter the integer you would like to calculate the factorial of and press ENTER: ");
	scanf("%d", &integer);
	fflush(stdin);

    //Check for error during input
	printf("\n\t\t\t\t\t\tAre you sure you entered %d?", integer);
	printf("\n\t\t\tEnter * if this is TRUE or any other character if this is FALSE and press ENTER: ");
	scanf("%c", &correct);
	fflush(stdin);

	if(correct != '*') //Error check user input 
	{
		//Change text colour to RED
        SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

		printf("\n\t\t\t\t Seems you may have not inputted your intentional integer");
		printf("\n\t\t\t\t\tPlease restart the program and try again!");
	}

	else if(integer < 0) //Error check user input
	{ 
		//Change text colour to RED
        SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

		printf("\n\t\t\t\t  Error! Factorial of a negative number doesn't exist!");
	}

		else //If user enters a valid integer 
		{
			for(count = 1; count <= integer; count++)
			{
			 factorial *= count; //Calculate factorial 
			}//End of for loop
            
			//Change text colour to YELLOW 
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );

			printf("\n\t\t\t\t\t  %s, The factorial of %d or, %d! = %d",name, integer, integer, factorial);
		}//End of if else statement 

		//Change text colour to GREEN 
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );

		//Prompt user to enter their choice to restart or exit 
		printf("\n\n\t\t   Would you like to restart the program? Enter 1 for YES or 2 for NO and press ENTER: ");
		scanf("%d", &restart);

	}while(restart == 1); //End do while loop, restart if user entered 1

	if(restart = 2) //If the user chose to exit  
	{
		printf("\n\t\t\t\t\t    Thank you for using this program.");
		printf("\n\t\t\t\t\t      Please press ENTER to exit...\n");
	}

	getch();
	return 0;
}//end of main function 
