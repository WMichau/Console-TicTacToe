#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;

char board[3][3] = {
	' ', ' ', ' ',
	' ', ' ', ' ',
	' ', ' ', ' '
};

int check()
{

	if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') || (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O'))
		return 1;
	else if ((board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') || (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O'))
		return 1;
	else if ((board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') || (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O'))
		return 1;

	else if ((board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') || (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'))
		return 1;
	else if ((board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') || (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'))
		return 1;
	else if ((board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') || (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'))
		return 1;

	else if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'))
		return 1;
	else if ((board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
		return 1;


	else if (board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' &&
		board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
		board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ')
		return 2;
	else
		return 3;
}

void draw()
{
	cout << endl;
	cout << "\t" << "  A " << "  B " << "  C " << endl;
	cout << endl;
	cout << "\t" << "1 " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "\t" << "  --+---+--" << endl;
	cout << "\t" << "2 " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "\t" << "  --+---+--" << endl;
	cout << "\t" << "3 " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
	cout << endl;
}


int main()
{
	srand(time(NULL));

	int player = rand() % 2 + 1, result;
	char chr;
	string selection;

	do
	{
		system("cls");
		cout << "player 1 - ( X )    player 2 - ( O }" << endl;

		draw();

		if (player % 2)
			player = 1;
		else
			player = 2;

		cout << "player: " << player << " - ";
		cin >> selection;

		if (player == 1)
			chr = 'X';
		else
			chr = 'O';

		if ((selection == "A1" || selection == "a1") && board[0][0] == ' ')
			board[0][0] = chr;
		else if ((selection == "B1" || selection == "b1") && board[0][1] == ' ')
			board[0][1] = chr;
		else if ((selection == "C1" || selection == "c1") && board[0][2] == ' ')
			board[0][2] = chr;
		else if ((selection == "A2" || selection == "a2") && board[1][0] == ' ')
			board[1][0] = chr;
		else if ((selection == "B2" || selection == "b2") && board[1][1] == ' ')
			board[1][1] = chr;
		else if ((selection == "C2" || selection == "c2") && board[1][2] == ' ')
			board[1][2] = chr;
		else if ((selection == "A3" || selection == "a3") && board[2][0] == ' ')
			board[2][0] = chr;
		else if ((selection == "B3" || selection == "b3") && board[2][1] == ' ')
			board[2][1] = chr;
		else if ((selection == "C3" || selection == "c3") && board[2][2] == ' ')
			board[2][2] = chr;
		else
		{
			//cout << endl;
			//cout << "Worng move" << endl;
			player--;
		}

		player++;

		result = check();

	} while (result == 3);

	system("cls");

	cout << "player 1 - ( X )    player 2 - ( O }" << endl;
	draw();

	if (result == 1)
		cout << "player " << --player << " wins";
	else
		cout << "Draw";

	cout << endl;

	system("PAUSE");
	return 0;
}
