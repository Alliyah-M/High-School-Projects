/********************** Functions Program ***********************/
/*      This program is a clothing catalog for the clothing     */
/*      store Ardenes. This program uses functions. The user    */
/*      selects an item and inputs the quantity they want to    */
/*      purchase. The program then calculates the finale price  */
/*      price with tax and displays this information.           */
/*                                                              */
/*                  Programmer: Alliyah Mohammed                */            
/*                  Date: January 10th, 2016                    */
/****************************************************************/

/*-----Preprocessing Directives-----*/
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>


 /*-----Main Module-----*/
int main(void)
{
	system (" TITLE Alliyah Mohammed - Ardenes Catalog"); //Title of output
	

	/*-----Prototypes-----*/
	void info_fn (char[20]);								//  Program info          
	int ClothingCatalog_fn (int[7], char[7][20], float[7]); //  Array of catolog      
	int QuantityOfItem_fn (void);                           // Input quantity        
	float CartTotal_fn (int, int, float[7]);                //  Calculate final price 
	void ShowPrice_fn (float);                              //  Print final price     
	void ProgramEnd_fn (void);                              // End message           

	/*-----Local Variables-----*/
	int itemCode[7] = {1, 2, 3, 4, 5, 6, 7}; // Item code      
	int chosenCode; //User entered code 
	int itemQuantity; //Quantity of Item  
	float finalPrice; //Total Price       
	char name[20]; //User Name 
	char clothingItems[7][20] = {"Shirts", "Pants", "Skirts", "Dresses", "Jackets", "Socks", "Hoodies"}; //Item Array
	float itemPrices[7] = {14.00, 18.99, 12.99, 15.45, 25.98, 5.99, 21.20}; // Item Prices
	int restart = 0; //Restart Variable
	int correct; //Error check variable
    
	//Code for Coloured Text
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);  
	wOldColorAttrs = csbiInfo.wAttributes;

	do //Do while to restart program
	{
		system("cls"); //Clear screen
		
		//Text colour is White
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

		info_fn(name); //Call to print info

		chosenCode = ClothingCatalog_fn(itemCode, clothingItems, itemPrices); //Call to get code

		itemQuantity = QuantityOfItem_fn(); //Call to get quantity

		finalPrice = CartTotal_fn(chosenCode, itemQuantity, itemPrices); //Call to calculate total

		ShowPrice_fn(finalPrice); //Call to show price
	
		do //Do while for error checking
		{

	    //Text colour is White
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

		//Prompt user to exit 
		printf("\n\n\t\t\t\t\t Would you like to restart the program?");
		printf("\n\t\t\t\t    Enter 1 to EXIT and 2 to RESTART and press ENTER: ");
		scanf("%d", &restart);
		
		//Text colour is Red
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );
		printf("\n\n\t\t\t\t\t       Are you sure you entered %d?", restart);
		printf("\n\t\t\t\t      Enter 1 for yes or 2 for no and press ENTER: ");
		scanf("%d", &correct);
		}while( correct != 1); //End do while

	}while( restart != 1); //End of Do while
	
	ProgramEnd_fn(); //Call to exit message

	return 0;
}/*-----End of Main module-----*/

/*-----Module: info_fn-----*/
void info_fn (char name[20])
{
	//Prompt user to 
	printf("\n\t\t\t\t\t Welcome to the Ardenes Clothing Catalog!");
	printf("\n\t\t\t\t   Please enter your name and press ENTER to begin: ");
	scanf("%s", name);

	return;
}/*-----End info_fn module-----*/

/*-----Module: ClothingCatalog_fn-----*/
int ClothingCatalog_fn (int itemCode[7], char clothingItems[7][20], float itemPrices[7])
{
	int row, col; //Variables for array
	int code; //Variable for item code
	int correct; //Variable for error checking

	//Code for Coloured Text
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);  
	wOldColorAttrs = csbiInfo.wAttributes;
	
	//Text colour Light Blue 
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY );

	printf("\n\n\t\t\t\t      Here is the catalog of the store inventory.\n");

	printf("\n\t\t\t\t      Clothing Item    \t Price \t\t Item Code");
	printf("\n\t\t\t\t   ___________________________________________________");
	
	//Print catalog array
	for(row = 0; row < 7; row++)
	{
		printf("\n\t\t\t\t        %s\t\t $%5.2f\t\t     %d", clothingItems[row], itemPrices[row], itemCode[row]);
		printf("\n\t\t\t\t   ___________________________________________________");
	}//End of for loop
	
	do //Start of do while for input
	{
	code = 0; //Reset variable

	//Text colour Yellow
	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
	
	//Prompt user to enter code
	printf("\n\n\t\tPlease enter the item code of the item you would like to purchase and press ENTER: ");
	scanf("%d", &code);
	
	//Text colour Red
	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

	//Error checking
	printf("\n\t\t Are you sure you entered %d?", code);
	printf("\n\t\t If yes, then enter 1, if no enter 2 and press ENTER: ");
	scanf("%d", &correct);

	}while( correct != 1); //End of nested do while

	return(code);
}/*-----End ClothingCatalog_fn module-----*/

/*-----Module: QuantityOfItem_fn-----*/
int QuantityOfItem_fn (void)
{
	//Declare local variables
	int num; //Variable to hold quantity
	int correct; //Variable for error checking

	//Code for Coloured Text

	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);  
	wOldColorAttrs = csbiInfo.wAttributes;
	
	do //Start of do while for input
	{ 
	  num = 0; //reset variable

	  //Text colour Blue
	  SetConsoleTextAttribute ( h, FOREGROUND_BLUE| FOREGROUND_INTENSITY );

	  //Prompt user to enter quantity
	  printf("\n\t\tPlease enter the quantity of this item that you would like to purchase and press ENTER: ");
	  scanf("%d", &num);
	
	  //Text colour Red
	  SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

	  //Error checking
	  printf("\n\t\t Are you sure you entered %d?", num);
	  printf("\n\t\t If yes, then enter 1, if no enter 2 and press ENTER: ");
	  scanf("%d", &correct);

	}while( correct != 1); //End of nested do while
	
	return(num);
}/*-----End QuantityOfItem_fn module-----*/

/*-----Module: CartToal_fn-----*/
float CartTotal_fn (int chosenCode, int itemQuantity, float itemPrices[7])
{
	float total; 

	//Code for Coloured Text
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);  
	wOldColorAttrs = csbiInfo.wAttributes;
	
	//Text colour Pink
	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

	switch(chosenCode) //Switch to check chosen item
	{
		//Item one is chosen
	    case 1: total = (itemQuantity * itemPrices[0]) * 1.13;
			printf("\n\t\t\t\t\t  Chosen Item |   Price   |  Quantity");
			printf("\n\t\t\t\t\t  ____________________________________");
			printf("\n\t\t\t\t\t     Shirts   |   $14.00  |    %d\n", itemQuantity);
		        break;

		//Item two is chosen
		case 2: total = (itemQuantity * itemPrices[1]) * 1.13;
			printf("\n\t\t\t\t\t  Chosen Item |   Price  |  Quantity");
			printf("\n\t\t\t\t\t  ____________________________________");
			printf("\n\t\t\t\t\t     Pants    |   $18.99 |    %d\n", itemQuantity);
		        break;
		
		//Item three is chosen 
		case 3: total = (itemQuantity * itemPrices[2]) * 1.13;
			printf("\n\t\t\t\t\t  Chosen Item |   Price  |  Quantity");
			printf("\n\t\t\t\t\t  ____________________________________");
			printf("\n\t\t\t\t\t     Skirts   |   $12.99 |    %d\n", itemQuantity);
				break;
		
		//Item four is chosen
		case 4: total = (itemQuantity * itemPrices[3]) * 1.13;
			printf("\n\t\t\t\t\t  Chosen Item |   Price  |  Quantity");
			printf("\n\t\t\t\t\t  ____________________________________");
			printf("\n\t\t\t\t\t     Dresses  |   $15.45 |    %d\n", itemQuantity);
				break;
		
		//Item five is chosen
		case 5: total = (itemQuantity * itemPrices[4])  * 1.13;
			printf("\n\t\t\t\t\t  Chosen Item |   Price  |  Quantity");
			printf("\n\t\t\t\t\t  ____________________________________");
			printf("\n\t\t\t\t\t     Jackets  |   $25.98 |    %d\n", itemQuantity);
				break;
		
		//Item six is chosen
		case 6: total = (itemQuantity * itemPrices[5]) * 1.13;
			printf("\n\t\t\t\t\t  Chosen Item |   Price  |  Quantity");
			printf("\n\t\t\t\t\t  ____________________________________");
			printf("\n\t\t\t\t\t     Socks    |   $5.99  |    %d\n", itemQuantity);
				break;
		
		//Item seven is chosen
		case 7: total = (itemQuantity * itemPrices[6]) * 1.13;
			printf("\n\t\t\t\t\t  Chosen Item |   Price  |  Quantity");
			printf("\n\t\t\t\t\t  ____________________________________");
			printf("\n\t\t\t\t\t     Hoodies  |   $21.20 |    %d\n", itemQuantity);
				break;

        //Erroneous input 
		default: SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );
				 printf("\n\t\t\t\t\t  It seems you did not enter a valid code.\n");
			     printf("\t\t\t\t\t     Please restart or exit the program\n\n"); 
	}//End of switch structure

	return(total);
}/*-----End CartTotal_fn module-----*/

/*-----Module: ShowPrice_fn-----*/
void ShowPrice_fn (float finalPrice)
{
	//Code for Coloured Text
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);  
	wOldColorAttrs = csbiInfo.wAttributes;
	
	//Text is White
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );
	printf("\n\t\t\t\t   The total cost of your selection including tax is:\n");
	
	//Text is Light Blue
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
	
	//Display final price
	printf("\n\t\t\t\t\t\t        $%.2f ", finalPrice);
 
	return;
}/*-----End ShowPrice_fn module-----*/

/*-----Module: ProgramEnd_fn-----*/
void ProgramEnd_fn (void)
{
	//Code for Coloured Text
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);  
	wOldColorAttrs = csbiInfo.wAttributes;
	
	//Text colour is Green 
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );

	//Prompt user to exit
	printf("\n\n\t\t\t\t\t    Thank you for using the program.\n");
	printf("\n\t\t\t\t\t        Press ENTER to exit...\n");

	return;
}/*-----End ProgramEnd_fn module-----*/






