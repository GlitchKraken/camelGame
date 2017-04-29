/*
	Chad Fry ITSE 2421  | Prof Welch.
	4/27/2017
	Camel Game Description:

	Camel Game is a choice-based RPG game where the user has stolen a camel,
	and is attempting to escape from the natives.
	to do so, the user will make a "move" each turn 
	from a list of options. The program needs to be
	as modularized as possible for points.
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void clearScreen();
void pause();

void camelWelcomeText();
void superEpicCamelMenu();
void mainActionMenu();
void statusCheck(int miles, int canteen, int natives);

char userChoiceValidation(char& userChoice);

//since logic will be handling *most* of the logic, it is necessary for it to receive the most variables.
void logic(bool& quit, char choice, int& miles, int& canteen, int& thirst, int& natives, int& camel );

int main()
{
	bool done = false;
	char choice;
	int milesTraveled = 0;
	int Thirst = 0;
	int camelTiredness = 0;
	int nativesDistance = -20;
	int canteenDrinks = 6;


	superEpicCamelMenu(); //display the amazing title screen, once.

	do
	{
		mainActionMenu(); //display main-menu
		cin >> choice; //get the user's choice
		userChoiceValidation(choice); //validate it
		logic(done, choice, milesTraveled, canteenDrinks, Thirst, nativesDistance, camelTiredness); //perform logic based on this choice

	}while(done == false);


	return 0;
}

void clearScreen() //clears the screen.
{
	cout << endl << endl  << endl << endl  << endl << endl; 
	cout << endl << endl  << endl << endl  << endl << endl; 
	cout << endl << endl  << endl << endl  << endl << endl; 
	cout << endl << endl  << endl << endl  << endl << endl; 
	cout << endl << endl  << endl << endl  << endl << endl; 
	cout << endl << endl  << endl << endl  << endl << endl; 
	cout << endl << endl  << endl << endl  << endl << endl; 
}

void pause() //pauses the program until the user presses Enter.
{

	cout << endl << "Press Enter to continue! " << endl;
	cin.get();
	cin.ignore();
	cin.clear();
}


void superEpicCamelMenu() //Displays the one-time EPIC camel menu.
{

 clearScreen();
 cout << " _______                      __      __   __           ___ __        ______                        __      ______" << endl;
 cout << "|     __|.----.---.-.-----.--|  |    |  |_|  |--.-----.'  _|  |_     |      |.---.-.--------.-----.|  |    |    __|" << endl;
 cout << "|    |  ||   _|  _  |     |  _  |    |   _|     |  -__|   _|   _|    |   ---||  _  |        |  -__||  |    |__    |" << endl;
 cout << "|_______||__| |___._|__|__|_____|    |____|__|__|_____|__| |____|    |______||___._|__|__|__|_____||__|    |______|" << endl;
 cout << endl << endl << endl;
 cout << endl;
 camelWelcomeText(); //display game description;
 cout << "                                                         =--_" << endl;
 cout << "                                         .-````````-.     |* _)" << endl;
 cout << "                                        /          \\   /  /" << endl;
 cout << "                                       /            \\_/  /" << endl;
 cout << "           _                          /|                /" << endl;
 cout << "       _-''/\\                        / |    ____    _.--            _" << endl;
 cout << "    _-'   (  '-_            _       (    | |  /\\  ||           .-''.`." << endl;
 cout << "_.-'       '.   `'-._   .-'/'.      `   | |/ /  | |/        _-''   (   '-_" << endl;
 cout << "             '.      _-`   (   '-_        | /   \\ |     _.-'       )     '-._" << endl;
 cout << "           _.'   _.-'       (     `-._    ||\\   |\\  '`'        .-'" << endl;
 cout << "         '               .-'          `'  || \\  ||))" << endl;
 cout << "A Game By Chad Fry__  _  ____ _____  ___ _|\\ _|\\_|\\/ _______________  ___  ___________ " << endl;
 cout << "                       c  c  ` c C ` C  ` ``  `` ``" << endl;
 cout << "                   c       C" << endl;
 cout << "              C        C" << endl;
 cout << "                   C                                                              " << endl;
 pause();
}

void camelWelcomeText() //game description goes here
{
	cout << "WELCOME TO GRAND THEFT CAMEL 5!!!" << endl;
	cout << "_________________________________" << endl << endl;
	cout << "In order to get back home from the Mobi desert," << endl;
	cout << "you decided it would be the best decision to steal a camel." << endl;
	cout << "But now, the natives want their camel BACK." << endl;
	cout << endl << "Will you survive?";
	cout << endl << endl;
}

void mainActionMenu() //displays the menu where the user can make choices.
{
	clearScreen();
	
	cout << "What would you like to do? " << endl << endl;
	cout << "A. Drink from your canteen." << endl;
	cout << "B. Continue riding at a moderate speed." << endl;
	cout << "C. Continue riding at full speed." << endl;
	cout << "D. Stop and rest." << endl;
	cout << "E. Status Check." << endl; 
	cout << endl << endl << "Q. Quit Game." << endl; 
}

char userChoiceValidation(char& userChoice) //Takes user's choice, then validates it.
{

	switch(userChoice)
	{
		case 'A':
		userChoice = 'A';
		break;

		case 'a':
		userChoice = 'A';
		break;

		case 'B':
		userChoice = 'B';
		break;

		case 'b':
		userChoice = 'B';
		break;

		case 'C':
		userChoice ='C';
		break;

		case 'c':
		userChoice ='C';
		break;

		case 'D':
		userChoice = 'D';
		break;

		case 'd':
		userChoice = 'D';
		break;
	
		case 'E':
		userChoice = 'E';
		break;

		case 'e':
		userChoice = 'E';
		break;

		case 'Q':
		userChoice =  'Q';
		break;

		case 'q':
		userChoice = 'Q';
		break;

		default: 
		userChoice = '0';
	}

}

void logic(bool& quit, char choice, int& miles, int& canteen, int& thirst, int& natives, int& camel )
{
	switch(choice)
	{

	case 'Q': 

		quit = true;
		cout << "Ending Game..." << endl;
		break;

	case 'A':
	
		cout << "You Chose A!" << endl;
		pause();
		break;

	case 'B':
	
		cout << "You chose B!" << endl;
		pause();
		break;

	case 'C':

		cout << "You chose C!";
		pause();
		break;

	
	case 'D':
		cout << "you chose D!" << endl;
		pause();
		break;

	case 'E':

		statusCheck(miles, canteen, natives);
		break;

	default:
		cout << "Sorry, but that isn't a valid choice! :(" << endl;
		pause();
		break;
	}
}

void statusCheck(int miles, int canteen, int natives)
{
	clearScreen();

	cout << "Current Status: " << endl;
	cout << "________________" << endl << endl;
	cout << "Miles Traveled: " << miles << endl;
	cout << "Drinks left in canteen: " << canteen << endl;
	cout << "The natives are " << (miles - natives) << " Miles behind you." << endl;

	pause();
}