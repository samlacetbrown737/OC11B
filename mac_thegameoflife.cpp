//Conway's Game of Life
//OC11B Final Project
//	By Sam Lacet-Brown
#include <iostream>
#include <iomanip>
using namespace std;

//Global variables
int neighbor = 0;
const char L = '*'; //display '*' for living cell
const char D = '-';//display '-' for dead cell
char newBoard[12][12]; //temp board for updates
char board[12][12] =   {{'.','.','.','.','.','.','.','.','.','.','.','.'},
						{'.','*','-','-','-','-','-','-','-','-','*','.'},
						{'.','-','*','-','-','-','-','-','-','*','-','.'},
						{'.','-','-','*','-','-','-','-','*','-','-','.'},
						{'.','-','-','-','*','-','-','*','-','-','-','.'},
						{'.','-','-','-','-','*','*','-','-','-','-','.'},
						{'.','-','-','-','-','*','*','-','-','-','-','.'},
						{'.','-','-','-','*','-','-','*','-','-','-','.'},
						{'.','-','-','*','-','-','-','-','*','-','-','.'},
						{'.','-','*','-','-','-','-','-','-','*','-','.'},
						{'.','*','-','-','-','-','-','-','-','-','*','.'},
						{'.','.','.','.','.','.','.','.','.','.','.','.'}}; //set inital design

//Functions
void updateBoard();
int neighborCount(int r, int c);
void liveDead(int neighbor, int r, int c);

//Main loop - Forms board ands runs loops when prompted to continue
int main() {
	int gen;
	cout<<"Generations to run? ";
	cin>>gen;
	int generation = 2; //so that the stated count is accurate
	for (int r=1; r<11; r++) {
		for (int c=1; c<11; c++) {
            cout<<setw(2)<<board[r][c];
        }
		cout<<endl;
	}
	cout<<endl;
	while(generation<=gen) {
		cout<<"Generation "<<generation<<endl;
		updateBoard();
		generation++;
	}
}
//Update loop - sets each part to what it has been calculated to be
void updateBoard() {
	for(int row=1; row<11; row++) {
		for(int column=1; column<11; column++) {
			int neighbor = 0;
			neighbor = neighborCount(row,column); //sets number of neighbors
			liveDead(neighbor, row, column); //decide if alive or dead
		}
	}

	for(int row=1; row<11; row++) {
		for(int column=1; column<11; column++) {
			board[row][column]=newBoard[row][column]; //update the board
		}
	}

	for (int r=1; r<11; r++) {
		for (int c=1; c<11; c++) {
            cout<<setw(2)<<board[r][c];
		}
		cout<<endl;
	}
	cout<<endl;
}

//counting loop - returns how many neighbors the cell has
int neighborCount(int r, int c) {
	int neighbor=0;
	if (board[r-1][c-1]==L) { //top left
		neighbor++;
	}
	if (board[r-1][c]==L) { //top
		neighbor++;
	}
	if (board[r-1][c+1]==L) { //top right
		neighbor++;
	}
	if (board[r][c-1]==L) { //left
		neighbor++;
	}
	if (board[r][c+1]==L) { //right
		neighbor++;
	}
	if (board[r+1][c-1]==L) { //bottom left
		neighbor++;
	}
	if (board[r+1][c]==L) { //bottom
		neighbor++;
	}
	if (board[r+1][c+1]==L) { //bottom right 
		neighbor++;
	}
	return neighbor;
}
//living loop - check if number of neighbors leads to life or death
void liveDead(int neighbor, int r, int c) {
	if(board[r][c] == L) { //currently alive
		if(neighbor<2) { //less than two neighbors, loneliness kills it
			newBoard[r][c] = D; //the cell will be dead
		}
		else if(neighbor==2) { //two neighbors, nothing happens, stay alive
			newBoard[r][c] = L; //the cell will be living
		}
		else if(neighbor==3) { //three neighbors, nothing happens, stay alive
			newBoard[r][c] = L;
		}
		else { //more than three neighbors, crowding kills it
			newBoard[r][c] = D;
		}
	}
	else if (board[r][c] == D) { //currently dead
		if(neighbor==3) { //three neighbors, reproduction create new cell
			newBoard[r][c] = L;
		}
		else { //stays dead
			newBoard[r][c] = D;
		}
	}
}
