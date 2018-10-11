/*-------------------ECU Simulator-----------------*/
/*		This program simulates the ECU of a car.   */
/*		It will read in speeds from a text file    */
/*		and perform various calculations to get    */
/*		readings from various car sensors.         */
/*                                                 */
/*			Programmer: Alliyah Mohammed           */
/*			Date: November 3rd, 2017               */
/*-------------------------------------------------*/

/*--------Preprocessing Directives-----*/
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

/*---------Main Function--------------*/
int main(void)
{
	//console title
	system("TITLE Alliyah Mohammed - ECU Simulator");

	//Code for coloured text 
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;


/*---------Prototypes-----------------*/
	void programInfo ();                           //print program description
    int speedSensor (int,int[30]);				   //calculate and print difference in speed
	void oxygenSensor (int, int[30], int[30]);     //calculate and print air-fuel ratio
	void throttleSensor (int, int[30]);            //calculate and print throttle angle
	float crankshaftSensor(int, int[30]);          //calculate and print rpm
	void airflowSensor (int, float[30], int [30]); //calculate and print airflow 
	void programEnd ();                            //print end message

/*---------Declare Variables----------*/
	int count;				 //variable for for loop                              
	int counta;				 //second variable for for loop
	int speedArray[30];		 //Array for speeds from text file
	FILE *inputFile;		 //pointer for speed.txt file
	int speedDifference[30]; //Array for change in speed
	float rpm[30];           //Array for rpm of crankshaft

	//text colour is white 
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY );

	programInfo(); //Call to function to print program description 

    //hold screen till user moves on
	getch(); 

	//Clear screen 
	system("cls");

	inputFile = fopen ("d:speed.txt", "r"); //r for read from the file
	
	if (inputFile == NULL) //check to see if file will open or can be found
	{
		//text colour is red
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );
		//prompt user to exit 
		printf("\nThe inputfile is not available.");
		printf("\nPress enter to exit...\n");
		getch();
		exit(1);
	}//end of if statement

	//Account for car starting at rest 
	speedArray[0] = 0;


	for(count=1; !feof(inputFile); count++) //For loop which exits at the end of the file
	{
		fscanf(inputFile, "%d", &speedArray[count]);//Gets speeds from the disk
		fgetc(inputFile);
	}//end of for loop

	//Account for car coming to a stop
	speedArray[9] = 0;

	//close input file
	fclose(inputFile);
	
	//For loop to perform sensor calculations 
	for(counta = 0; counta < count; counta++)
	{
		speedDifference[counta] = speedSensor(counta, speedArray); //call to calculate speed difference 

		oxygenSensor(counta, speedArray, speedDifference); //call to calcluate air-fuel ratio

		throttleSensor(counta, speedArray); //call to calculate throttle angle

		rpm[counta] = crankshaftSensor(counta, speedArray); //call to caluclate rpm 

		airflowSensor(counta, rpm, speedDifference); //call to calculate airflow 

		//Hold screen until user moves to next interval
		getch();
	
		//clear screen
		system("cls");

	}//end of for loop

	//text colour is green 
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
	programEnd(); //call to function to print end message

	//hold screen
	getch();

	return 0;

}//end of main 

/*----------Module: programInfo----------*/
void programInfo(void)
{
	//print program description
	printf("\n\t\t\t\t\t Welcome to the ECU Simulator!");
	printf("\n\n\t\t This program will calculate various sensor readings based on speeds");
	printf(" read from a text file.");
	printf("\n\t\t\t\t This program can read in speeds of up to 70 mph.");
	printf("\n\t\t\t  Please ensure you have a USB connected in order for this program to work!");
	//prompt user to move on
	printf("\n\n\t\t\t\t\t Press ENTER to continue. . .");

	return;
} /* end programInfo module */

/*----------Module: speedSensor----------*/
int speedSensor(int counta, int speedArray[30])
{
	FILE *outputFile; //pointer for speeds.txt file
	int difference;   //local variable for speed difference
	int speed;        //variable for condition of speed

	outputFile = fopen ("d:speeds.txt", "a"); //a for appending to existing file 

	//Code for coloured text 
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

		if(speedArray[counta] > speedArray[counta + 1]) // if the first speed is greater than the second (decelerating)
		{
			//calculate difference in speeed
			difference = ( -1 * (speedArray[counta + 1] - speedArray[counta]));

			//vehicle is decelerating 
			speed = 1;

			//print values to output file
			fprintf(outputFile, "\n\n-----------------New Entry!--------------------");
			fprintf(outputFile, "\nSpeed Sensor");
			fprintf(outputFile, "\nFrom %2d to %2d the car is decelerating, and less air is being taken into the ", 
				speedArray[counta], speedArray[counta + 1]);
			fprintf(outputFile, "\nengine.\n");
			fprintf(outputFile, "\nThe car decreased by a speed of %d mph", difference);

			//print to screen
			//text is white
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
			printf("\t\t\t\t%d mph ", speedArray[counta]);
			//spaces are red
			SetConsoleTextAttribute ( h, BACKGROUND_RED |FOREGROUND_INTENSITY );
			printf("                         ");
			//text is white
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
			printf(" %d mph", speedArray[counta + 1]);

			//text is light blue
			SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY );
			printf("\n\nSpeed Sensor");
			//text is white
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
			printf("\nFrom %2d to %2d the car is decelerating, and less air is being taken into the ", 
				speedArray[counta], speedArray[counta + 1]);
			printf("\nengine.\n");
			
			printf("\nThe car ");
			//text is red
			SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );
			printf("decreased"); 

			//text is white
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
			printf(" by a speed of %d mph", difference);	
		}//end of if statement

		else if(speedArray[counta] == speedArray[counta + 1]) // if the two speeds are equal to each other (constant)
		{
			//calculate difference in speed
			difference = speedArray[counta + 1] - speedArray[counta];

			//vehicle is coasting 
			speed = 2;


			//print to output file
			fprintf(outputFile, "\n\n-----------------New Entry!--------------------");
			fprintf(outputFile, "\nSpeed Sensor");
			fprintf(outputFile, "\nFrom %2d to %2d the car is staying at a constant speed, and the amount of", speedArray[counta], 
				speedArray[counta + 1]);
			fprintf(outputFile, "\nair in the engine remains the same.\n");
			fprintf(outputFile, "\nThe car has maintained the same speed of %d mph", speedArray[counta]);


			//print to screen
			//text is white
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
			printf("\t\t\t\t%d mph ", speedArray[counta]);
			//spaces are yellow
			SetConsoleTextAttribute ( h, BACKGROUND_GREEN | BACKGROUND_RED |FOREGROUND_INTENSITY );
			printf("                         ");
			//text is white
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
			printf(" %d mph", speedArray[counta + 1]);

			//text is light blue
			SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY );
			printf("\n\nSpeed Sensor");
			//text is white
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
			printf("\nFrom %2d to %2d the car is staying at a constant speed, and the amount of", speedArray[counta], 
				speedArray[counta + 1]);
			printf("\nair in the engine remains the same.\n");

			printf("\nThe car has ");
			//text is yellow
			SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY );
			printf("maintained ");
			//text is white
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
			printf("the same speed of %d mph", speedArray[counta]);
		}//end of else if statement

		else if(speedArray[counta] < speedArray[counta + 1]) // if the first speed is less than the second speed (accelerating)
		{
			//calculate difference in speed
			difference = speedArray[counta + 1] - speedArray[counta];

			//vehicle is accelerating 
			speed = 3; 

			//print to output file
			fprintf(outputFile, "\n\n-----------------New Entry!-------------------");
			fprintf(outputFile, "\nSpeed Sensor");
			fprintf(outputFile, "\nFrom %2d to %2d the car is accelerating, and more air is used in the engine.\n", 
				speedArray[counta], speedArray[counta + 1]);
			
			fprintf(outputFile, "\nThe car increased by a speed of %d mph", difference);


			//print to screen
			//text is white
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
			printf("\t\t\t\t%d mph ", speedArray[counta]);
			//spaces are green
			SetConsoleTextAttribute ( h, BACKGROUND_GREEN | FOREGROUND_INTENSITY );
			printf("                         ");
			//text is white
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
			printf(" %d mph", speedArray[counta + 1]);

			//text is light blue
			SetConsoleTextAttribute ( h, FOREGROUND_BLUE | FOREGROUND_GREEN |FOREGROUND_INTENSITY );
			printf("\n\nSpeed Sensor");

			//text is white
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );

			printf("\nFrom %2d to %2d the car is accelerating, and more air is used in the engine.\n", 
				speedArray[counta], speedArray[counta + 1]);	
			printf("\nThe car has ");
			//spaces are green
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
			printf("increased ");
			//text is white
			SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
			printf("by a speed of %d mph", difference);
		}//end of else if statement

		//close the output file
		fclose(outputFile);

		//return type of speed difference to array in main 
		return(speed);
}/* end speedSensor module */

/*----------Module: oxygenSensor--------*/
void oxygenSensor(int counta, int speedArray[30], int speedDifference[30])
{
	
	FILE *outputFile; //pointer for speeds.txt file
	float ratio;      //variable for air-fuel ratio

	//Code for coloured text 
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	outputFile = fopen ("d:speeds.txt", "a"); //a for appending to existing file 


	//vehicle is accelerating 
	if(speedDifference[counta] == 3)
	{
		//calculate rich ratio
		ratio = (14.7 - ((2.2 / 69) * speedArray[counta + 1]));

		//print to output file
		fprintf(outputFile, "\n\nOxygen Sensor");
		fprintf(outputFile, "\nThe air to fuel ratio after this change in speed is %.1f : 1", ratio);

		//print to screen
		//text is pink
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
		printf("\n\nOxygen Sensor");
		//text is white
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
		printf("\nThe air to fuel ratio after this change in speed is %.1f : 1", ratio);
	}//end of if statement

	//vehicle is decelerating
	else if(speedDifference[counta] == 1)
	{
		//calculate lean ratio
		ratio = (14.7 - ((1.3 / 69) * speedArray[counta + 1]));

		//print to output file
		fprintf(outputFile, "\n\nOxygen Sensor");
		fprintf(outputFile, "\nThe air to fuel ratio after this change in speed is %.1f : 1", ratio);


		//print to screen
		//text is pink
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
		printf("\n\nOxygen Sensor");
		//text is white
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
		printf("\nThe air to fuel ratio after this change in speed is %.1f : 1", ratio);

	}//end of else if statement

	//vehicle is coasting 
	else 
	{
		//print to output file
		fprintf(outputFile, "\n\nOxygen Sensor");
		fprintf(outputFile, "\nThe air to fuel ratio is at the theoretical value of 14.7 : 1");

		//print to screen
		//text is pink
		SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
		printf("\n\nOxygen Sensor");
		//text is white
		SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
		printf("\nThe air to fuel ratio is at the theoretical value of 14.7 : 1");
	}//end of if else statement

	//close output file
	fclose(outputFile);


	return;
} /* end oxygenSensor module */

/*----Module: throttleSensor----*/
void throttleSensor (int counta, int speedArray[30])
{
	FILE *outputFile; //pointer for speeds.txt file
	float angle;      //Local variable for angle calculation 


	//Code for coloured text 
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	outputFile = fopen ("d:speeds.txt", "a"); //a for appending to existing file 

	//calculate the angle of the throttle
	angle = (45.0 / 70.0) * speedArray[counta + 1];

	//print to output file
	fprintf(outputFile, "\n\nThrottle Sensor");
	fprintf(outputFile, "\nThe angle of the throttle at %d mph is %.1f degrees", speedArray[counta + 1], angle);

	//print to screen
	//text is green
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
	printf("\n\nThrottle Sensor");
	//text is white
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
	printf("\nThe angle of the throttle at %d mph is %.1f degrees", speedArray[counta + 1], angle);

	//close output file
	fclose(outputFile);

	return;
}/* end module throttleSensor */

/*---Module: crankshaftSensor----*/
float crankshaftSensor (int counta, int speedArray[30])
{
	FILE *outputFile; 	//pointer for speeds.txt file
	float rpm;          //rpm of the crankshaft 

	//Code for coloured text 
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	outputFile = fopen ("d:speeds.txt", "a"); //a for appending to existing file 

	//calculate the rpm of the crankshaft
	rpm = ((speedArray[counta + 1] * 4.86 * 88) / 6.3);

	//print to output File
	fprintf(outputFile, "\n\nCrankshaft Sensor");
	fprintf(outputFile, "\nThe rpm of the crankshaft after this change in speed is %.f", rpm);

	//print to screen
	//text is yellow
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED |FOREGROUND_INTENSITY );
	printf("\n\nCrankshaft Sensor");
	//text is white
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
	printf("\nThe rpm of the crankshaft is %.f", rpm);

	//close output file
	fclose(outputFile);
	
	//return rpm to array in main 
	return(rpm);
}/* end module crankshaftSensor */

/*---Module: airflowSensor----*/
void airflowSensor (int counta, float rpm[30], int speedDifference[30])
{
	FILE *outputFile; 	//pointer for speeds.txt file
	float CFM;          //intake airflow
	int count;          //variable for animation
	int countz;         //variable for animation

	//Code for coloured text 
	HANDLE h = GetStdHandle (STD_OUTPUT_HANDLE);
	WORD wOldColorAttrs;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	wOldColorAttrs = csbiInfo.wAttributes;

	outputFile = fopen ("d:speeds.txt", "a"); //a for appending to existing file 

	//calculate the airflow
	CFM = ((91.0 * rpm[counta] * 1.00) / 3456);

	//print to output file
	fprintf(outputFile, "\n\nIntake Airflow Sensor");
	fprintf(outputFile, "\nThe airflow is now %.f cubic ft per meter", CFM);

	//print to screen
	//text is red
	SetConsoleTextAttribute ( h, FOREGROUND_RED |FOREGROUND_INTENSITY );
	printf("\n\nIntake Airflow Sensor");
	//text is white
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_INTENSITY );
	printf("\nThe airflow is now %.f cubic ft per meter", CFM);

	//text is Blue
	SetConsoleTextAttribute ( h, FOREGROUND_BLUE |FOREGROUND_INTENSITY );
	printf("\n\nAppending data to file . . .");

	//Car animation colour
	if(speedDifference[counta] == 1) //decelerating
	//text is red
	SetConsoleTextAttribute ( h, FOREGROUND_RED | FOREGROUND_INTENSITY );

	else if(speedDifference[counta] == 2) //coasting
	//text is yellow
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_RED |FOREGROUND_INTENSITY );

	else //accelerating 
	//text is green
	SetConsoleTextAttribute ( h, FOREGROUND_GREEN | FOREGROUND_INTENSITY );

	//car animation 
	printf("\n\n");
	for(count = 0; count <counta; count++)
	printf("  ");
	printf("     ___________  \n");
	for(count = 0; count <counta; count++)
	printf("  ");
	printf("    //   |||   \\\\  \n");
	for(count = 0; count <counta; count++)
	printf("  ");
	printf("  _//____|||____\\\\____  \n");
	for(count = 0; count <counta; count++)
	printf("  ");
	printf(" | _|      |       _  || \n");
	for(count = 0; count <counta; count++)
	printf("  ");
	printf(" |/ \\______|______/ \\_|| \n");
	
	if(count > 0)
	{
		for(countz = 0; countz < counta; countz++)
			printf("__");
	} 

	printf("__\\_/_____________\\_/_________ ");


	//close output file
	fclose(outputFile);

	return;
}/* end module airflowSensor */

/*---Module: programEnd----*/
void programEnd (void)
{
	//prompt user to exit the program 
	printf("\n\n\n\n\n\n\n\n \t\t\t\t\t Thank you for using the program!");
	printf("\n\n \t\t\t\t\t Please press ENTER to exit. . .\n\t\t\t\t\t ");

	return;

}/* end module programEnd */

   
