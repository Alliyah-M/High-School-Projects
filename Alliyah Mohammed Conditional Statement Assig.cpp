/*--------------------Age and Zodiac Sign Calculator-------------------*/
/*    This program uses the scanf function and a nested else-if.       */
/*    The user enters their name and date of birth and                 */
/*    the program will calculate their age.It will also                */
/*    tell them their zodiac sign then print an end message.           */ 
/*      PROGRAM ID: Alliyah Mohammed Conditional Statement Assig.cpp   */
/*      PROGRAMMER: Alliyah Mohammed                                   */
/*      RUN DATE: 27/10/16                                             */
/*---------------------------------------------------------------------*/

/*--------PREPROCESSING DIRECTIVES-------*/
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(void)
{
	system("TITLE Alliyah Mohammed - Age and Zodiac Sign Calculator"); //Title the program console

    //Declare Variables 
	int currentYear; /* Current year */ 
	int birthYear;   /* Birth year   */
	int birthDay;    /* Birth day    */
	int birthMonth;  /* Birth month  */
	char name[20];   /* User's name  */
	int age;         /* Declare age  */ 

	//Prompt User to Enter Name
	printf("Welcome to the Age and Zodiac Sign Calculator!\n");
	printf("\nBy entering your full birthday, this program will calculate your age and tell you your zodiac sign.\n");
	printf("\nTo begin, please enter your name and press ENTER: ");
	scanf("%s", name);
    /* Get input from user */
	printf("\nPlease enter the current year and press ENTER: ");
	scanf("%d", &currentYear);

	printf("\nPlease enter your year of birth and press ENTER: ");
	scanf("%d", &birthYear);
	
	printf("\nPlease enter your birth month using its number (April would be 4, January 1, etc) then press ENTER: ");
	scanf("%d", &birthMonth);

	printf("\nPlease enter your day of birth and press ENTER: ");
	scanf("%d", &birthDay);

	fflush(stdin); //Clear digital garbage

	//Calculations 
	age = currentYear - birthYear;

	//Conditional Statements & Output - begining if nested else-if
    if((birthMonth == 3) && (birthDay >= 21 && birthDay <= 31))
		/* FIRST Condition for ARIES */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Aries!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 4) && (birthDay >=1 && birthDay <=19))
		/* SECOND Condition for ARIES */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Aries!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 4) && (birthDay >= 20 && birthDay <= 30))
		/* FIRST Condition for TAURUS */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Taurus!\n", name, age);
    	printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth ==5) && (birthDay >=1 && birthDay <=20))
		/* Second Condition for TAURUS */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Taurus!\n", name, age);
    	printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 5) && (birthDay >= 21 &&  birthDay <= 31))
		/* FIRST Condition for GEMINI */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Gemini!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 6) && (birthDay >=1 && birthDay <= 20))
		/* SECOND Condition for GEMINI */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Gemini!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 6) && (birthDay >= 21 && birthDay <= 30)) 
		/* FIRST Condition for CANCER */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Cancer!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 7) && (birthDay >=1 && birthDay <= 22))
		/* SECOND Condition for CANCER */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Cancer!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 7) && (birthDay >= 23 && birthDay <= 31))
		/* FIRST Condition for LEO */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Leo!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 8) && (birthDay >=1 && birthDay <=22))
		/* SECOND Condition for LEO */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Leo!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 8) && (birthDay >= 23 && birthDay <= 31)) 
		/* FIRST Condition for VIRGO */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Virgo!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 9) && (birthDay >=1 && birthDay <=22))
		/* SECOND Condition for VIRGO */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Virgo!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 9) && (birthDay >= 23 && birthDay <= 30)) 
		/* FIRST Condition for LIBRA */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Libra!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 10) && (birthDay >=1 && birthDay <=22))
	    /* SECOND Condition for LIBRA */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Libra!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 10) && (birthDay >=23 && birthDay <= 31))
		/* FIRST Condition for SCORPIO */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Scorpio!\n", name, age);
	    printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 11) && (birthDay >=1 && birthDay <=21))
		/* SECOND Condition for SCORPIO */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Scorpio!\n", name, age);
	    printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 11) && (birthDay >= 22 && birthDay <=30))
		/* FIRST Condition for SAGITTARIUS */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Sagittarius!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 12) && (birthDay >= 1 && birthDay <= 21))
		/* SECOND Condition for SAGITTARIUS */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Sagittarius!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 12) && (birthDay >= 22 && birthDay <= 31))
		/* FIRST Condition for CAPRICORN */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Capricorn!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 1) && (birthDay >=1 && birthDay <=19))
		/* SECOND Condition for CAPRICORN */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Capricorn!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 1) && (birthDay >= 20 && birthDay <=31)) 
		/* FIRST Condition for AQUARIUS */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Aquarius!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 2) && (birthDay >= 1 && birthDay <= 18))
		/* SECOND Condition for AQUARIUS */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Aquarius!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 2) && (birthDay >= 19 && birthDay <= 29))
		/* FIRST Condition for PISCES */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Pisces!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else if((birthMonth == 3) && (birthDay >=1 && birthDay <=20))
		/* SECOND Condition for PISCES */
	{
		printf("\n%s, you will be %d years old this year and your zodiac sign is Pisces!\n", name, age);
		printf("\nPlease press ENTER to exit the program!\n");
	}

	else /* If the user enteres an invalid date */
	{
		printf("It seems the date you entered is invalid.\n");
		printf("Please press ENTER to exit the program.\n");
	} //End of nested else-if 

    getch();
	return 0;

} //End of main function 
