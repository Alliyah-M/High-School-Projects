/********************** Calculator ********************/
/*     This program is a basic calculator that        */
/*     can perform any of the four main calculations. */
/*     The program has a menu that allows the user    */
/*     to select the calculation they would like      */
/*     to do.                                         */
/*                                                    */
/*              Programmer: Alliyah Mohammed          */
/*              Date: January 24th, 2017              */
/******************************************************/

/*-----Preprocessing Directives-----*/
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

/*-----Main Module-----*/
int main(void)
{

    //Code for coloured text
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;
	system ("TITLE Alliyah Mohammed - Basic Calculator"); //Output title

	/*-----Prototypes-----*/
	 void programInfo_fn (void);        //Program information
	 int menu_fn (void);                //Menu
	 float addIntegers_fn (float, float);     //Add integers
	 float subtractIntegers_fn (float, float);//Subtract integers
	 float divideIntegers_fn (float, float);  //Divide integers
	 float multiplyIntegers_fn (float, float);//Multiply integers
	 void finalAnswer_fn (float);         //Print final answer
	 void endProgram_fn (void);         //End message

	/*-----Variables-----*/
	 int menu;		   //Hold menu choice
	 int restart;      //Variable for restart
	 float answer;     //Hold answer
	 float num1;       //Hold first integer
	 float num2;       //Hold second integer
	 float row;        //Variable for for loop
	 float col;        //Variable for for loop
	 int table;        //Variable for tables
	 int value;		   //Variable for tables
	 int tableNum = 1; //Variables for tables
	 float division;   //Variable for division table
	 int correct;      //Variable for error checking

do
{
	 //Clear screen
	 system("cls");


	 programInfo_fn(); //Call to print program info

	 menu = menu_fn(); //Call to print menu

	//Text is now White
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

	 switch(menu)
	 {
		case 1:
				system("cls"); //Clear screen
				printf("\n\t\t\t You have choosen. . .");

				//Text colour is now Green
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );

				printf(" Addition!");

				//Text is now White
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

				//Prompt user to enter first integer
				printf("\n\t Please enter the first integer you would like to use in the calculation and press ENTER: ");
				scanf("%f", &num1);
				fflush(stdin);

				do //Error check input
				{

					//Text is now Red
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

					//Error check input
					printf("\n\n\t\t\t\t\t Are you sure that you entered %.2f ? ", num1);

					//Text is now White
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

					printf("\n\n\t\t\t\t    Enter 1 for YES and 2 for NO then press ENTER. . . ");
					scanf("%d", &correct);
					fflush(stdin);

				}while( correct != 1); //End do while

				//Prompt user to enter second integer
				printf("\n\t Please enter the second integer you would like to use in the calculation and press ENTER: ");
				scanf("%f", &num2);
				fflush(stdin);

				do
				{

					//Text is now Red
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

					//Error check input
					printf("\n\n\t\t\t\t\t Are you sure that you entered %.2f ? ", num2);

					//Text is now White
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

					printf("\n\n\t\t\t\t    Enter 1 for YES and 2 for NO then press ENTER. . . ");
					scanf("%d", &correct);
					fflush(stdin);

				}while( correct != 1); //End do while

				//Text is now Yellow
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );

				printf("\n\t\t\t The answer to your equation %.2f + %.2f = ...", num1, num2);


				answer = addIntegers_fn(num1, num2); //Call to do calculation

				//Text is White
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

				finalAnswer_fn(answer); //Call to print answer

				printf("\n\t\t\t Would you like to see the addition table?");
				printf("\n\n\t\t\t Enter 1 for YES and 2 for NO and press ENTER... ");
				scanf("%d", &table);

				do //Error check input
				{

					//Text is now Red
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

					//Error check input
					printf("\n\n\t\t\t\t\t Are you sure that you entered %d ? ", table);

					//Text is now White
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

					printf("\n\n\t\t\t\t    Enter 1 for YES and 2 for NO then press ENTER. . . ");
					scanf("%d", &correct);
					fflush(stdin);

				}while( correct != 1);//End do while


				while(table == 1) //Print addition table
				{
					//Text colour is now Green
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );

					printf("\n\t\t\t      1   2   3   4   5   6   7   8   9  10  11  12");
					printf("\n\t\t\t    -----------------------------------------------");
					printf("\n\t\t\t %d|", tableNum);
					tableNum++;

					for(row =1; row <= 12; row++) //Print table
					{
						for(col = 1; col <= 12; col++)
						{
							value = row + col;
							printf("%4d", value);
						}//End inner for loop
						if(tableNum <= 12)
						{
							printf("\n\n\t\t\t%2d|", tableNum);
						    tableNum++;
						}
					}//End outer for loop

					table = 0;
					tableNum = 1;
				}//End while

				break;

		case 2:
				system("cls"); //Clear screen
				printf("\n\t\t\t You have choosen...");

				//Text is now Red
	            SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

				printf(" Subtraction!");

				//Text is now White
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

				//Prompt user to enter first integer
				printf("\n\t Please enter the first integer you would like to use in the calculation and press ENTER: ");
				scanf("%f", &num1);
				fflush(stdin);

				do
				{

					//Text is now Red
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

					//Error check input
					printf("\n\n\t\t\t\t\t Are you sure that you entered %.2f ? ", num1);

					//Text is now White
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

					printf("\n\n\t\t\t\t    Enter 1 for YES and 2 for NO then press ENTER. . . ");
					scanf("%d", &correct);
					fflush(stdin);

				}while( correct != 1); //End do while

				//Prompt user to enter second integer
				printf("\n\t Please enter the second integer you would like to use in the calculation and press ENTER: ");
				scanf("%f", &num2);
				fflush(stdin);

				do //Error check input
				{

					//Text is now Red
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

					//Error check input
					printf("\n\n\t\t\t\t\t Are you sure that you entered %.2f ? ", num2);

					//Text is now White
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

					printf("\n\n\t\t\t\t    Enter 1 for YES and 2 for NO then press ENTER. . . ");
					scanf("%d", &correct);
					fflush(stdin);

				}while( correct != 1); //End do while

				//Text is now Yellow
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );


				printf("\n\t\t\t The answer to your equation %.2f - %.2f = ...", num1, num2);


				answer = subtractIntegers_fn(num1, num2); //Call to calculate answer

			    //Text is White
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

				finalAnswer_fn(answer); //Call to print answer

				//Prompt user to see table
				printf("\n\t\t\t Would you like to see the subtraction table?");
				printf("\n\n\t\t\t Enter 1 for YES and 2 for NO and press ENTER... ");
				scanf("%d", &table);

				do //Error check input
				{

					//Text is now Red
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

					//Error check input
					printf("\n\n\t\t\t\t\t Are you sure that you entered %d ? ", table);

					//Text is now White
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

					printf("\n\n\t\t\t\t    Enter 1 for YES and 2 for NO then press ENTER. . . ");
					scanf("%d", &correct);
					fflush(stdin);

				}while( correct != 1); //End while


				while(table == 1) //Print addition table
				{
					//Text colour is now Red
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

					printf("\n\t\t\t      1   2   3   4   5   6   7   8   9  10  11  12");
					printf("\n\t\t\t    -----------------------------------------------");
					printf("\n\t\t\t %d|", tableNum);
					tableNum++;

					for(row =1; row <= 12; row++) //Print table
					{
						for(col = 1; col <= 12; col++)
						{
							value = row - col;
							printf("%4d", value);
						}//End inner for loop
						if(tableNum <= 12)
						{
							printf("\n\n\t\t\t%2d|", tableNum);
						    tableNum++;
						}
					}//End outer for loop

					table = 0;
					tableNum = 1;
				}//End while

				break;

		case 3:
				system("cls"); //Clear screen
				printf("\n\t\t\t You have choosen...");

				//Text is now Blue
				SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );

				printf("Divison!");

				//Text is now White
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

				//Prompt user to enter first integer
				printf("\n\t Please enter the first integer you would like to use in the calculation and press ENTER: ");
				scanf("%f", &num1);
				fflush(stdin);

				do //Error check input
				{

					//Text is now Red
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

					//Error check input
					printf("\n\n\t\t\t\t\t Are you sure that you entered %.2f ? ", num1);

					//Text is now White
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

					printf("\n\n\t\t\t\t    Enter 1 for YES and 2 for NO then press ENTER. . . ");
					scanf("%d", &correct);
					fflush(stdin);

				}while( correct != 1); //End do while

				//Prompt user to enter second integer
				printf("\n\t Please enter the second integer you would like to use in the calculation and press ENTER: ");
				scanf("%f", &num2);
				fflush(stdin);

				do //Error check input
				{

					//Text is now Red
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

					//Error check input
					printf("\n\n\t\t\t\t\t Are you sure that you entered %.2f ? ", num2);

					//Text is now White
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

					printf("\n\n\t\t\t\t    Enter 1 for YES and 2 for NO then press ENTER. . . ");
					scanf("%d", &correct);
					fflush(stdin);

				}while( correct != 1); //End do while

				//Text is now Yellow
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );

				printf("\n\t\t\t The answer to your equation %.2f / %.2f = ...", num1, num2);


				answer = divideIntegers_fn(num1, num2); //Call to calculate answer

			    //Text is White
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

				finalAnswer_fn(answer); //Call to print answer

				//Prompt user to see table
				printf("\n\t\t\t Would you like to see the division table?");
				printf("\n\n\t\t\t Enter 1 for YES and 2 for NO and press ENTER... ");
				scanf("%d", &table);

				do //Error check input
				{

					//Text is now Red
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

					//Error check input
					printf("\n\n\t\t\t\t\t Are you sure that you entered %d ? ", table);

					//Text is now White
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

					printf("\n\n\t\t\t\t    Enter 1 for YES and 2 for NO then press ENTER. . . ");
					scanf("%d", &correct);
					fflush(stdin);

				}while( correct != 1); //End do while


				while(table == 1) //Print addition table
				{

				    //Text colour is now Blue
					SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );

					printf("\n\t\t\t       1     2     3     4     5     6     7     8     9    10    11    12");
					printf("\n\t\t\t    ----------------------------------------------------------------------");
					printf("\n\t\t\t %d|", tableNum);
					tableNum++;

					for(row =1; row <= 12; row++)
					{
						for(col = 1; col <= 12; col++)
						{
							division = row / col;
							printf(" %5.2f", division);
						}//End inner for loop
						if(tableNum <= 12)
						{
							printf("\n\n\t\t\t%2d|", tableNum);
						    tableNum++;
						}
					}//End outer for loop

					table = 0;
					tableNum = 1;
				}//End while
				break;

		case 4:
				system("cls"); //Clear screen
				printf("\n\t\t\t You have choosen... ");

				//Text is now Pink
				SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

				printf("Multiplication !");

				//Text is now White
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

				//Prompt user to enter first integer
				printf("\n\t Please enter the first integer you would like to use in the calculation and press ENTER: ");
				scanf("%f", &num1);
				fflush(stdin);

				do //Error check input
				{

					//Text is now Red
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

					//Error check input
					printf("\n\n\t\t\t\t\t Are you sure that you entered %.2f ? ", num1);

					//Text is now White
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

					printf("\n\n\t\t\t\t    Enter 1 for YES and 2 for NO then press ENTER. . . ");
					scanf("%d", &correct);
					fflush(stdin);

				}while( correct != 1); //End do while

				//Prompt user to enter second integer
				printf("\n\t Please enter the second integer you would like to use in the calculation and press ENTER: ");
				scanf("%f", &num2);
				fflush(stdin);

				do //Error check input
				{

					//Text is now Red
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

					//Error check input
					printf("\n\n\t\t\t\t\t Are you sure that you entered %.2f ? ", num2);

					//Text is now White
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

					printf("\n\n\t\t\t\t    Enter 1 for YES and 2 for NO then press ENTER. . . ");
					scanf("%d", &correct);
					fflush(stdin);

				}while( correct != 1); //End do while

				//Text is now Yellow
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY );

				printf("\n\t\t\t The answer to your equation %.2f * %.2f = ...", num1, num2);


				answer = multiplyIntegers_fn(num1, num2); //Call to calculate answer

			    //Text is White
				SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

				finalAnswer_fn(answer); //Call to print answer

				//Prompt user to see table
				printf("\n\t\t\t Would you like to see the multiplication table?");
				printf("\n\n\t\t\t Enter 1 for YES and 2 for NO and press ENTER... ");
				scanf("%d", &table);

				do //Error check input
				{

					//Text is now Red
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

					//Error check input
					printf("\n\n\t\t\t\t\t Are you sure that you entered %d ? ", table);

					//Text is now White
					SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

					printf("\n\n\t\t\t\t    Enter 1 for YES and 2 for NO then press ENTER. . . ");
					scanf("%d", &correct);
					fflush(stdin);

				}while( correct != 1); //End do while


				while(table == 1) //Print multiplication table
				{

					//Text is Pink
					SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

					printf("\n\t\t\t      1   2   3   4   5   6   7   8   9  10  11  12");
					printf("\n\t\t\t    -----------------------------------------------");
					printf("\n\t\t\t %d|", tableNum);
					tableNum++;

					for(row =1; row <= 12; row++) //Print table
					{
						for(col = 1; col <= 12; col++)
						{
							value = row * col;
							printf("%4d", value);
						}//End inner for loop
						if(tableNum <= 12)
						{
							printf("\n\n\t\t\t%2d|", tableNum);
							tableNum++;
						}
					}//End outer for loop

					table = 0;
					tableNum = 1;

				}//End while

				break;

		case 5:
				system("cls"); //Clear screen
				printf("\n\t\t\t You have chosen to exit the program.");
				break;

		default://Text is now Red
				SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

				//Error message
				printf("\n\t\t\t It seems you did not enter a valid option");

				printf("\n\t\t\t Please restart or exit the program. . . ");
				break;
	 } //End of switch statement

	 //Text is White
	 SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

	 printf("\n\n\t\t\t Would you like to restart the program?");

	 printf("\n\t\t\t Enter 1 to RESTART or 2 to EXIT and press ENTER. . . . .");
	 scanf("%d", &restart);

	 do //Do while to error check
	{

		//Text is now Red
	    SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

		//Error check input
		printf("\n\n\t\t\t\t\t Are you sure that you entered %d ? ", restart);

		//Text is now White
	    SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

		printf("\n\n\t\t\t\t    Enter 1 for YES and 2 for NO then press ENTER. . . ");
		scanf("%d", &correct);
		fflush(stdin);

	}while( correct != 1); //End of do while


	 }while( restart != 2);//End of do while

	 endProgram_fn(); //Call to print end message


	getch();
	return 0;
}/*-----End Main Module-----*/

/*-----Module: programInfo_fn-----*/
void programInfo_fn (void)
{
	//Code for coloured text
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	//Text is White
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

	//Program info
	printf("\n\t\t\t\t\t    Welcome to the basic calculator!\n");
	printf("\n\t\t  This program will allow you to enter two integers and it will calculate one of the four");
	printf("\n\t\t main operations, addition, subtraction, multipliaction, or division, between the two numbers.");

	printf("\n\n\t\t\t\t\t  Press ENTER to be brought to the menu. . .");

	getch();

	return;
}/*-----End programInfo_fn module-----*/

/*-----Module: menu_fn-----*/
int menu_fn (void)
{
	/*-----Local Variables-----*/
	int menuChoice; //Hold menu choice
	int correct;

	//Code for coloured text
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	//Text is now White
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

	system("cls"); //Clear screen

	printf("\n\t * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ MENU ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ~ * ");

	//Text colour is now Green
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
	printf("\n\n\t\t\t\t\t     Addition + . . . . . 1");

	//Text is now Red
	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );
	printf("\n\n\t\t\t\t\t    Subtraction - . . . . 2");

	//Text is now Blue
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
	printf("\n\n\t\t\t\t\t       Division / . . . . 3");

	//Text is now Pink
	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
	printf("\n\n\t\t\t\t\t Multiplication * . . . . 4");

	//Text is White
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
	printf("\n\n\t\t\t\t\t          Exit -> . . . . 5");

	do
	{
		//Text is Light Blue
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
		printf("\n\n\t\t Please enter the character for the selction you would like to make and press ENTER: ");
		scanf("%d", &menuChoice);
		fflush(stdin);

		//Text is now Red
	    SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

		//Error check input
		printf("\n\n\t\t\t\t\t Are you sure that you entered %d ? ", menuChoice);

		//Text is now White
	    SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

		printf("\n\n\t\t\t\t    Enter 1 for YES and 2 for NO then press ENTER. . . ");
		scanf("%d", &correct);
		fflush(stdin);

	}while( correct != 1);


	return(menuChoice);
} /*-----End menu_fn Module-----*/


/*-----Module: addIntegers_fn-----*/
float addIntegers_fn (float num1, float num2)
{
	/*-----Local Variables-----*/
	float sum; //Hold sum

	//Calculate sum
	sum = num1 + num2;

	return(sum);

} /*-----End addIntegers_fn Module-----*/


/*-----Module: subtractIntegers-----*/
float subtractIntegers_fn (float num1, float num2)
{	/*-----Local Variables-----*/
	float difference; //Hold difference

	//Calculate difference
	difference = num1 - num2;

	return(difference);

} /*-----End subtractIntegers_fn Module-----*/


/*-----Module: divideIntegers_fn Module-----*/
float divideIntegers_fn (float num1, float num2)
{	/*-----Local Variables-----*/
	float quotient; //Hold quotient

	//Calculate quotient
	quotient = num1 / num2;

	return(quotient);

} /*-----End divideIntegers_fn Module-----*/


/*-----Module: multiplyIntegers_fn-----*/
float multiplyIntegers_fn (float num1, float num2)
{	/*-----Local Variables-----*/
	float product; //Hold product

	//Calculate product
	product = num1 * num2;

	return(product);

} /*-----End multiplyIntegers_fn Module-----*/


/*-----Module: finalAnswer_fn-----*/
void finalAnswer_fn (float answer)
{
	//Code for coloured text
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	//Text is now Green
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );

	//Print answer
	printf(" %.2f !", answer);

	//Text is White
    SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

	return;
} /*-----End finalAnswer_fn Module-----*/


/*-----Module: endProgram_fn-----*/
void endProgram_fn (void)
{
	//Prompt user to exit
	printf("\n\t\t\t Thank you for using the program!");
	printf("\n\t\t\t Press ENTER to exit. . . ");

	return;
} /*-----End endProgram_fn Module-----*/
