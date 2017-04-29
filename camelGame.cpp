/*
	Chad Fry ITSE 2421  | Prof Welch.
	4/27/2017
	Camel Game Description:

	Camel Game is a choice-based RPG game where the user has stolen a camel,
	and is attempting to escape from the natives.
	to do so, the user will make a "move" each turn 
	from a list of options. The program needs to be
	as modularized as possible for points.


	github Link: https://github.com/cfrybb/camelGame.git
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
int medTravelRand(); //RNG for medium-paced travel.
char userChoiceValidation(char& userChoice); //takes the users choice and validates it
void nightTimePicture(); //a pretty picture at night
void travelFullSpeed(int& camel, int& natives, int& Thirst, int& miles); //called when the user wants to travel ahead at full speed.
void travelModerateSpeed(int& camel, int& natives, int& Thirst, int& miles);
void canteenDrink(int& thirst, int& canteen); //called if user wants to drink from canteen.
bool foundOasis(); //Handles the RNG for the oasis.
void oasisPicture(); //a picture of the oasis!
void oasis(int& thirst, int& camel, int& canteen);
void nativeGameOver(bool& quit);
void victory(bool& quit);

//since this function will be handling *most* of the logic, it is necessary for it to receive the most variables.
void logic(bool& quit, char choice, int& miles, int& canteen, int& thirst, int& natives, int& camel );

void victoryPic();

int main()
{
	bool done = false;
	char choice;
	int milesTraveled = 0;
	int Thirst = 0;
	int camelTiredness = 0;
	int nativesDistance = -20;
	int canteenDrinks = 3;


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
	int maxVal = 17;
	int minVal = 10;


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

int medTravelRand()
{
	int maxVal = 5;
	int minVal = 12;


	srand(time(0));

	int distance;

	distance = (rand() % (maxVal - minVal + 1)) + minVal; //generate a random number between min and max.

	return distance;
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
	
		canteenDrink(thirst, canteen);
		pause();
		break;

	case 'B':
	
		travelModerateSpeed(camel, natives, thirst, miles);
		if(foundOasis())
		{
			oasis(thirst, camel, canteen);
		}
		pause();
		break;

	case 'C':

		travelFullSpeed(camel, natives, thirst, miles);
		if(foundOasis())
		{
			oasis(thirst, camel, canteen);
		}
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

	//an if-structure containing Game-over scenarios should go here.

	if(thirst > 4)
	{
		clearScreen();
		cout << "You are getting really thirsty..." << endl;
		pause();
	}
	if(thirst > 6)
	{
		clearScreen();
		cout << "The heat of the desert has finally gotten to you," << endl;
		cout << "and you collapse from exaustion, and thirst." << endl;
		cout << " 			GAME 			OVER			 " << endl;
		cout << endl << endl << "...least the natives get their camel back." << endl;
		quit = true;
	}

	if(camel > 5)
	{
		clearScreen();
		cout << "Your camel is getting really tired..." << endl;
		cout << "He looks like he doesn't feel so good." << endl;
		pause();
	}

	if(camel > 8)
	{
		clearScreen();
		cout << "Tired of your Shenanaigans, your camel rears up," << endl;
		cout << "boots you off, and runs far into the distance- " << endl;
		cout << "Leaving you behind." << endl;
		cout << "		GAME 		OVER" << endl;
		cout << endl << endl << "...maybe be nicer to mr. camel next time :( " << endl;
		quit = true;
	}
	if(miles - natives < 15)
	{
		clearScreen();
		cout << "You see a large rumble of dust, and small figures on the horizon..." << endl;
		cout << "The natives are getting close..." << endl;
		pause();
	}
	if (natives >= miles )
	{
		nativeGameOver(quit); //give the user the native's gameOver screen, and exit the game.
	}
	if(miles >= 200)
	{
		victory(quit); //give the user a victory message, then set quit/done = true. (exit game).
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
	int milesTraveled;

	camel += camelRand(); //add a random amount to the camel's tiredness
	natives += nativesRand(); //randomly increase the native's distance
	Thirst++; //add one to thirst

	milesTraveled = fastTravelRand(); //randomly increase the number of miles traveled.
	miles += milesTraveled;
	clearScreen();
	cout << "Shooting foward at a breakneck pace, you travled " << milesTraveled << " miles!" << endl;

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

void oasisPicture()
{
 cout << "    ___ __" << endl; 
 cout << "   (_  ( _ ) )__                  '.       :   /    .'" << endl;
 cout << "     '(___(_____)      __           '.     :  /   .'" << endl;
 cout << "                     /. _`            '.   : /  .'" << endl;
 cout << "                .--.|/_/__      -----____   _  _____-----" << endl;
 cout << "_______________''.--o/___  `_______________(_)___________" << endl;
 cout << "       ~        /.'o|_o  '.|  ~                   ~   ~" << endl;
 cout << "  ~            |/    |_|  ~'         ~" << endl;
 cout << "               '  ~  |_|        ~       ~     ~     ~" << endl;
 cout << "      ~    ~          |_|O  ~                       ~" << endl;
 cout << "             ~     ___|_||_____     ~       ~    ~" << endl;
 cout << "   ~    ~      .'':. .|_|A:. ..::''." << endl;
 cout << "             /:.  .:::|_|.` .:.  :.:`  ~" << endl;
 cout << "  ~         :..:. .:. .::..:  .:  ..:.       ~   ~    ~" << endl;
 cout << "             .: .:  :. .: ..:: .  /" << endl;
 cout << "    ~      ~ ----------------------     ~    ~    ~         ~" << endl;
 cout << "               ~           ~    ~   ~             ~" << endl;
 cout << "        ~         ~            ~   ~                 ~" << endl;
 cout << "   ~                  ~    ~ ~                 ~" << endl;
}

void travelModerateSpeed(int& camel, int& natives, int& Thirst, int& miles)
{
	int milesTraveled;

	camel++; //one to the camel's tiredness
	natives += nativesRand(); //randomly increase the native's distance
	Thirst++; //add one to thirst

	milesTraveled = medTravelRand(); //randomly increase the number of miles traveled.
	miles += milesTraveled;
	clearScreen();
	cout << "Taking a steady pace, you travled " << milesTraveled << " miles!" << endl;

}

void canteenDrink(int& thirst, int& canteen)
{
	if(canteen > 0)
	{
		canteen--;
		thirst = 0;
		
	clearScreen();
	cout << "You Take a big, refresing gulp from your canteen... Ahhhh!" << endl;
	cout << "(thirst has been reset)" << endl; 
	}
	else
	{
		clearScreen();
		cout << "Uh oh... Looks like your canteen is empty... " << endl;
	}
}

void victoryPic()
{
 cout << "	                  /-----/                        |" << endl;
 cout << "  *                 | |n| |                       -#-       *            *" << endl;
 cout << "                    | ||_||                        |" << endl;
 cout << "                   /  \\Y//      *" << endl;
 cout << "            )(__X,,|__|   |;;//--\\" << endl;
 cout << "           /  \\;;;;;;;;;;;;/|----|                              *" << endl;
 cout << "           |A | |            | U  |" << endl;
 cout << "         )_|  | |____)-----( |    |" << endl;
 cout << "        ///|__|-'////       \\|___)=(__X" << endl;
 cout << "       /////////////         \\///   \\/ \\                              *" << endl;
 cout << "       |           |  U    U |//     \\u||" << endl;
 cout << "       |   )_,-,___|_)=(     | |  U  |_|_X" << endl;
 cout << "       |  ///   \\|//   \\   | |  __ |/// \\" << endl;
 cout << "     )_')(//     \\/     >---)=( /  \\  | |-----------------..," << endl;
 cout << "    //// ,\\u   u |   u /////   \\  ||__|A|----------------.., ," << endl;
 cout << "   |  | .. |      |    ///// ,-, \\__||--------------------.., ," << endl;
 cout << "---'--'_::_|______'----| u | | | |-----------------------.., ," << endl;
 cout << "                       |___|_|_|_|----------------------.., " << endl;
 cout << "                            `--------------------------.., " << endl;

}

bool foundOasis()
{
	int maxVal = 20;
	int minVal = 1;


	srand(time(0));

	int chance;

	chance = (rand() % (maxVal - minVal + 1)) + minVal; //generate a random number between min and max.

	if(chance == 7) //pick an arbitrary number between 1 and 20. if that number has been chosen, the oasis is found.
	{
		return true;
	}
	else
	{
		return false;
	}
}


void oasis(int& thirst, int& camel, int& canteen)
{
	thirst = 0;
	camel = 0;
	canteen = 3;

	clearScreen();
	cout << "In the corner of your eye you see... a Mirage...? " << endl;
	cout << "No, an Oasis! How Lucky! " << endl;
	cout << "Your thirst has been reset." << endl;
	cout << "Your canteen was refilled." << endl;
	cout << "your camel got some rest." << endl;

	oasisPicture();
}

void victory(bool& quit)
{
	clearScreen();

	cout << "in the distance you see it! civilization..." << endl;
	cout << "The mobi desert is behind you, as are the natives." << endl;
	cout << "YOU 		WON!!! " << endl;
	cout << endl << endl << endl;
	victoryPic();
	quit = true;
}

void nativeGameOver(bool& quit)
{
	clearScreen();
	cout << "The natives caught up with you, ruffed you up, and took" << endl;
	cout << "their camel BACK." << endl;
	cout << endl << endl << "		Game 		OVER" << endl;
	quit = true;
}