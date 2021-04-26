#include <iostream>
using namespace std;

//bool isWon(char, char[][3]);
//bool isDraw(char[][3]);
//void displayBoard(char[][3]);
//void makeAMove(char[][3], char);

bool isWon(char currentPlayer, char currentBoard[3][3]) {
	bool isItAWin = false;

	if (currentBoard[0][0] == currentPlayer && currentBoard[0][1] == currentPlayer && currentBoard[0][2] == currentPlayer) { //first line horizontal up to down
		isItAWin = true;
	}
	else if (currentBoard[1][0] == currentPlayer && currentBoard[1][1] == currentPlayer && currentBoard[1][2] == currentPlayer) { //second line horizontal
		isItAWin = true;
	}
	else if (currentBoard[2][0] == currentPlayer && currentBoard[2][1] == currentPlayer && currentBoard[2][2] == currentPlayer) { //third line horizontal
		isItAWin = true;
	}
	else if (currentBoard[0][0] == currentPlayer && currentBoard[1][0] == currentPlayer && currentBoard[2][0] == currentPlayer) { //first line vertical
		isItAWin = true;
	}
	else if (currentBoard[0][1] == currentPlayer && currentBoard[1][1] == currentPlayer && currentBoard[2][1] == currentPlayer) { //second line vertical left to right
		isItAWin = true;
	}
	else if (currentBoard[0][2] == currentPlayer && currentBoard[1][2] == currentPlayer && currentBoard[2][2] == currentPlayer) { //third line vertical
		isItAWin = true;
	}
	else if (currentBoard[0][0] == currentPlayer && currentBoard[1][1] == currentPlayer && currentBoard[2][2] == currentPlayer) { // diagonal left upper corner to right bottom corner
		isItAWin = true;
	}
	else if (currentBoard[0][2] == currentPlayer && currentBoard[1][1] == currentPlayer && currentBoard[2][0] == currentPlayer) { // diagonal right upper corner to left bottom corner
		isItAWin = true;
	}
	return isItAWin;


}
bool isDraw(char currentBoard[3][3]) {

	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (currentBoard[row][col] == ' ') {
				return false;
			}
		}
	}
	return true;

}
void displayBoard(char currentBoard[3][3]) {
	for (int row = 0; row < 3; row++) {
		cout << "-------------" << endl;
		for (int col = 0; col < 3; col++) {
			cout << "| " << currentBoard[row][col] << " ";
		}
		cout << "|" << endl;
	}
	cout << "-------------" << endl;
}
void makeAMove(char currentBoard[3][3], char currentPlayer) {
	int row;
	int column;
	bool continuePlease = true;

	while (continuePlease) {
		cout << "Enter a row (0, 1, 2) for player "<< currentPlayer << "   : ";
		cin >> row;
		cout << "\nEnter a row(0, 1, 2) for player "<< currentPlayer << "   : ";
		cin >> column;
		cout << "\n\n";

		if (currentBoard[row][column] == 'X' || currentBoard[row][column] == 'O') {
			cout << "This cell is already occupied.Try a different cell" << endl;
		}
		else {
			currentBoard[row][column] = currentPlayer;
			continuePlease = false;
		}
	}
}


int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {
		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);
		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}
/*
int main() {
	cout << "HelloWorld" << endl;
}*/