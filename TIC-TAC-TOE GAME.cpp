#include <bits/stdc++.h>
using namespace std;

#define SIDE 3

string PLAYER1, PLAYER2;

void showBoard(char board[][SIDE])
{
	printf("\n\n");

	printf("\t\t\t %c | %c | %c \n",
		board[0][0],
		board[0][1],
		board[0][2]);

	printf("\t\t\t------------\n");

	printf("\t\t\t %c | %c | %c \n",
		board[1][0],
		board[1][1],
		board[1][2]);

	printf("\t\t\t------------\n");
	printf("\t\t\t %c | %c | %c \n\n",
		board[2][0],
		board[2][1],
		board[2][2]);

	return;
}

void showInstructions()
{
	printf("\t\t\t Tic-Tac-Toe\n\n");

	printf("Choose a cell numbered "
		"from 1 to 9 as below"
		" and play\n\n");

	printf("\t\t\t 1 | 2 | 3 \n");
	printf("\t\t\t------------\n");
	printf("\t\t\t 4 | 5 | 6 \n");
	printf("\t\t\t------------\n");
	printf("\t\t\t 7 | 8 | 9 \n\n");

	printf("-\t-\t-\t-\t-\t"
		"-\t-\t-\t-\t-\n\n");

	return;
}

void initialise(char board[][SIDE],
				int moves[])
{
	srand(time(NULL));

	for (int i = 0; i < SIDE; i++) {
		for (int j = 0; j < SIDE; j++)
			board[i][j] = ' ';
	}

	for (int i = 0; i < SIDE * SIDE; i++)
		moves[i] = i;

	random_shuffle(moves,
				moves + SIDE * SIDE);

	return;
}

void declareWinner(string whoseTurn)
{
	if (whoseTurn == PLAYER1)
		cout << PLAYER1 << " has won\n";
	else
		cout << PLAYER1 << " has won\n";
	return;
}

bool rowCrossed(char board[][SIDE])
{
	for (int i = 0; i < SIDE; i++) {
		if (board[i][0] == board[i][1]
			&& board[i][1] == board[i][2]
			&& board[i][0] != ' ')
			return (true);
	}
	return (false);
}

bool columnCrossed(char board[][SIDE])
{
	for (int i = 0; i < SIDE; i++) {
		if (board[0][i] == board[1][i]
			&& board[1][i] == board[2][i]
			&& board[0][i] != ' ')
			return (true);
	}
	return (false);
}

bool diagonalCrossed(char board[][SIDE])
{
	if (board[0][0] == board[1][1]
		&& board[1][1] == board[2][2]
		&& board[0][0] != ' ')
		return (true);

	if (board[0][2] == board[1][1]
		&& board[1][1] == board[2][0]
		&& board[0][2] != ' ')
		return (true);

	return (false);
}

bool gameOver(char board[][SIDE])
{
	return (rowCrossed(board)
			|| columnCrossed(board)
			|| diagonalCrossed(board));
}

void playTicTacToe(string whoseTurn)
{
	char board[SIDE][SIDE];

	int moves[SIDE * SIDE];

	initialise(board, moves);

	showInstructions();

	int moveIndex = 0, x, y;
	int r, c;

	while (gameOver(board) == false
		&& moveIndex != SIDE * SIDE) {
		if (whoseTurn == PLAYER1) {

		player1:

			cout << PLAYER1
				<< " Enter the respective"
				<< " row and column to "
					"insert X :\n";
			cin >> r >> c;

			if (r <= 3 && c <= 3) {

				if (board[r - 1] == ' ')
					board[r - 1] = 'X';

				else {
					cout << "You cannot Overlap"
						<< " on Already "
							"filled position:\n";
					goto player1;
				}
			}

			else {
				cout << "\nInput is not "
					<< "valid please enter "
					<< "right one\n";

				goto player1;
			}

			showBoard(board);
			moveIndex++;
			whoseTurn = PLAYER2;
		}

		else if (whoseTurn == PLAYER2) {

		player2:

			cout << PLAYER2
				<< " Enter the respective"
				<< " row and column to "
					"insert O :";
			cin >> r >> c;
			if (r <= 3 && c <= 3) {

				if (board[r - 1] == ' ')
					board[r - 1] = 'O';

				else {
					cout << "You cannot Overlap"
						<< " on Already "
						<< "filled position:\n";
					goto player2;
				}
			}

			else {
				cout << "\nInput is not "
					<< "valid please enter "
					<< "right one :\n";
				goto player2;
			}

			showBoard(board);
			moveIndex++;
			whoseTurn = PLAYER1;
		}
	}

	if (gameOver(board) == false
		&& moveIndex == SIDE * SIDE)
		printf("It's a draw\n");
	else {

		if (whoseTurn == PLAYER1)
			whoseTurn = PLAYER2;
		else if (whoseTurn == PLAYER2)
			whoseTurn = PLAYER1;

		declareWinner(whoseTurn);
	}
	return;
}

int main()
{
	cout << "Enter name of first Player: ";
	cin >> PLAYER1;

	cout << "Enter name of Second Player: ";
	cin >> PLAYER2;

	srand(time(0));

	int toss = rand() % 2;

	if (toss == 1) {
		cout << "Player "
			<< PLAYER1
			<< " win the toss"
			<< endl;

		playTicTacToe(PLAYER1);
	}
	else {
		cout << "Player "
			<< PLAYER2
			<< " win the toss"
			<< endl;
		playTicTacToe(PLAYER2);
	}

	return (0);
}

