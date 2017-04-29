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

void clearScreen(); //clears the screen upon call.
void pause(); //pauses until the user presses Enter.

void camelWelcomeText();
void superEpicCamelMenu();
void mainActionMenu();
void statusCheck(int miles, int canteen, int natives);
void rest(int& camel, int& natives);
int nativesRand(int& nativesDistance);//the RNG behind how far the natives move
int camelRand(); //RNG for how. tired the camel is.
int fastTravelRand(); //RNG for fast-paced travel.
char userChoiceValidation(char& userChoice);
void nightTimePicture();
void travelFullSpeed(int& camel, int& natives, int& Thirst, int& miles); //called when the user wants to travel ahead at full speed.

//since this function will be handling *most* of the logic, it is necessary for it to receive the most variables.
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
		userChoiceValidation(choice); //validate the user's choice
		logic(done, choice, milesTraveled, canteenDrinks, Thirst, nativesDistance, camelTiredness); //perform logic based on this choice

	}while(done == false);


	return 0;
}

int nativesRand()
{
	int maxVal = 13;
	int minVal = 7;


	srand(time(0));

	int distance;

	distance = (rand() % (maxVal - minVal + 1)) + minVal; //generate a random number between min and max.

	return distance;
}

int camelRand() //generates a random number for how tired the camel is. (fast travel)
{
	int maxVal = 1;
	int minVal = 3;


	srand(time(0));

	int tired;

	tired = (rand() % (maxVal - minVal + 1)) + minVal; //generate a random number between min and max.

	return tired;
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

		travelFullSpeed(camel, natives, thirst, miles);
		pause();
		break;

	
	case 'D':
		rest(camel, natives);		
		pause();
		break;

	case 'E':

		statusCheck(miles, canteen, natives);
		break;

	default:
		clearScreen();
		cout << "Sorry, but that isn't a valid choice! :(" << endl;
		pause();
		break;
	}
}

void statusCheck(int miles, int canteen, int natives) //called when the user checks their status
{
	clearScreen();

	cout << "Current Status: " << endl;
	cout << "________________" << endl << endl;
	cout << "Miles Traveled: " << miles << endl;
	cout << "Drinks left in canteen: " << canteen << endl;
	cout << "The natives are " << (miles - natives) << " Miles behind you." << endl;

	pause();
}

void rest(int& camel, int& natives) //called when the user chooses to rest
{
	camel = 0;
	natives += nativesRand(); //incress the distance the natives traveled by a random amount.

	clearScreen();
	cout << "You Stop and rest for the night..." << endl;
	cout << "While the natives may be getting closer," << endl;
	cout << "at least your camel seems pretty happy." << endl;
	cout << endl << endl;
	nightTimePicture();
}

void nightTimePicture() //display a pretty nighttime picturre
{

 cout << "                               *                " << endl;
 cout << "                *                         " << endl;
 cout << "   *                                     " << endl;
 cout << "                      *                             *           * " << endl;
 cout << "  *         _                                                     " << endl;
 cout << "       _-''/`                *              |                       - _" << endl;
 cout << "    _-'   ( '-_            _              - # -                  .-''.`." << endl;
 cout << "_.-'       '.   `'-._   .-'/'.              |                _-''   (   '-_" << endl;
 cout << "             '.      _-`   (   '-_                       _.-'       )     '-._" << endl;
 cout << "           _.'   _.-'       (     `-._                 '`'        .-'" << endl;
 cout << "         '               .-'          `'             '            )   " << endl;
 cout << "__  _  ____ _____  ___ ____________ _______________  ___  ___________ " << endl;
 cout << "                                                                        " << endl;
 cout << "                   c       C" << endl;
 cout << "              C        C" << endl;
 cout << "                   C                                                              " << endl; 
}

void travelFullSpeed(int& camel, int& natives, int& Thirst, int& miles)
{
	camel += camelRand(); //add a random amount to the camel's tiredness
	natives += nativesRand(); //randomly increase the native's distance
	Thirst++; //add one to thirst.
	miles += fastTravelRand(); //randomly increase the number of miles traveled.
}

int fastTravelRand() //generates a random number for how far the user travel, then returns it.
{
	int maxVal = 20;
	int minVal = 10;


	srand(time(0));

	int distance;

	distance = (rand() % (maxVal - minVal + 1)) + minVal; //generate a random number between min and max.

	return distance;
}