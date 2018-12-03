// Homework 2


#include <iostream>
#include <time.h>

using namespace std;
class FindGoldGame;

//Declare rows and columns
const int ROWS = 8;
const int COLS = 8;
const int GUESSES = 5;
const int GOLD = 5;
const int BOMBS = 1;


// functions
void initializeArray(char board[ROWS][COLS]);
void presentArray(char boardArray[ROWS][COLS]);
void hideGoldBombs(char board[ROWS][COLS]);
void displayInstructions();

// instructions for user
void displayInstructions()
{
	cout << "**" << "***********************" << "**" << endl;
	cout << "**" << "     Find Gold!      " << "**" << endl;
	cout << "**" << " You have 5 guesses,  " << "**" << endl;
	cout << "**" << " 5 pieces of gold    " << "**" << endl;
	cout << "**" << "     and 1 bomb      " << "**" << endl;
	cout << "**" << "  Earn 1 Xtra Point    " << "**" << endl;
	cout << "**" << "  When Find Gold!!!  " << "**" << endl;
	cout << "**" << "      Good Luck!       " << "**" << endl;
	cout << "**" << " ********************* " << "**" << endl;
	cout << endl;

	return 0;

}




int main()
{
	char answer;
	do
	{
		int xCoordinate, yCoordinate;
		int Remainingguess = GUESSES;
		int score = 0;
		char board[ROWS][COLS];

		initializeArray(board);
		presentArray(board);
		hideGoldBombs(board);
		displayInstructions();


		while (Remainingguess > 0)
		{
			//checks wronf input
			cout << endl;
			cout << "Enter a x-coordinate between: ";
			cin >> xCoordinate;

			do
			{
				if (xCoordinate < 1 || xCoordinate>8)
				{
					cout << "Please enter a value between 1-8" << endl;
					cout << "Enter X coordinate: ";
					cin >> xCoordinate;
					cout << endl;
				}
			} while (xCoordinate < 1 || xCoordinate>8);
			cout << endl;
			cout << "Enter a y-coordinate between: ";
			cin >> yCoordinate;
			// check input
			do
			{
				if (yCoordinate < 1 || yCoordinate>8)
				{
					cout << "Please enter a value between 1-8" << endl;
					cout << "Enter y coordinate: ";
					cin >> yCoordinate;
					cout << endl;
				}
			} while (yCoordinate < 1 || yCoordinate>8);

			//checks if they found gold
			if (board[xCoordinate - 1][yCoordinate - 1] == 'G')
			{
				cout << endl;
				cout << "You found GOLD! You earned one extra guess. ";
				//if they found gold adds extra 
				board[xCoordinate - 1][yCoordinate - 1] = 'F';
				score = score + 1;
				Remainingguess--;
				Remainingguess++;
				cout << "You have " << Remainingguess << " guesses to go." << endl;
				cout << endl;
				continue;
			}

			else if (board[xCoordinate - 1][yCoordinate - 1] == 'B')
			{
				cout << endl;
				Remainingguess = 0;
				cout << "Bomb! game over" << endl;
				break;

			}
			else
				cout << endl;
			Remainingguess--;
			cout << "oh no...";
			cout << "You have " << Remainingguess << " guesses remain" << endl;
			cout << endl;

		}
		//displays score and board with contents
		cout << "You earned " << score << " points" << endl;
		cout << "better luck next time" << endl;
		cout << "Here is your board: " << endl;
		cout << endl;

		cout << endl;
		cout << "    ";
		for (xCoordinate = 0; xCoordinate < COLS; xCoordinate++)
			cout << "  " << xCoordinate + 1;
		cout << endl;


		for (yCoordinate = 0; yCoordinate < ROWS; yCoordinate++)
		{
			cout << " " << yCoordinate + 1 << " |";
			for (xCoordinate = 0; xCoordinate < COLS; xCoordinate++)
			{
				cout << "  " << board[xCoordinate][yCoordinate];
			}
			cout << endl;
		}


		// asks player if they want to play again
		cout << "Would you like to play again? Enter y";
		cin >> answer;

	} while (answer == 'y' || answer == 'Y');

	return 0;
}


void initializeArray(char board[ROWS][COLS])
{
	int rows, cols;

	for (rows = 0; rows < ROWS; rows++)
	{

		for (cols = 0; cols < COLS; cols++)
		{
			board[rows][cols] = ' ';
		}
	}
}

// Function used to show board to user
void presentArray(char boardArray[ROWS][COLS])
{
	int rows, cols;

	cout << "   ";

	for (cols = 0; cols < COLS; cols++)

		cout << cols + 1 << "  ";
	cout << endl;



	for (rows = 0; rows < ROWS; rows++)
	{
		cout << rows + 1 << " ";
		cout << "|";
		for (cols = 0; cols < COLS; cols++)
		{
			cout << "?" << "  ";
		}

		cout << endl;

	}

}

//function used to hide gold and bombs
void hideGoldBombs(char board[ROWS][COLS])
{
	int gold = 0;
	int x, y;
	int bombs = 0;
	srand(time(NULL));

	for (gold = 0; gold < GOLD; gold++)
	{
		x = rand() % ROWS;
		y = rand() % COLS;
		board[x][y] = 'G';
	}

	for (bombs = 0; bombs < BOMBS; bombs++)
	{
		x = rand() % ROWS;
		y = rand() % COLS;
		board[x][y] = 'B';
	}

}
