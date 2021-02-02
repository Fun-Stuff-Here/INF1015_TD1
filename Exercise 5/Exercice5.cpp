

#include <iostream>
#include <fstream>
using namespace std;

//number of lines in a Tic-Tac-toe board
const int numberOfLine = 3;
string getGameState(string board[][numberOfLine])
{
    //check rows
    for (size_t i = 0; i < numberOfLine; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    //check columns
    for (size_t i = 0; i < numberOfLine; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    //check diagonal
    if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[1][1] == board[2][0]))
    {
        return board[1][1];
    }
    else
    {
        return "";
    }
}

void getGameData(string fileName, string board[][numberOfLine])
{
    ifstream boardFile(fileName);
    for (size_t i = 0; i < numberOfLine; i++)
    {
        for (size_t j = 0; j < numberOfLine; j++)
        {
            boardFile >> board[i][j];
        } 
    }

}


void displayWinner(string winner){
    if (winner == "x")
    {
        cout << "Le joueur 1 gagne." << endl;
    }
    else if (winner == "o")
    {
        cout << "Le joueur 2 gagne." << endl;
    }
    else
    {
        cout << "Egalite" << endl;
    }
}


int main()
{
    string fileName = "";
    cout << "Saisissez un nom de fichier contenant la grille du Tic-Tac-Toe pour déterminer le joueur gagant : " << endl;
    cin >> fileName;

    string board[numberOfLine][numberOfLine];
    getGameData(fileName, board);
    

    string winner = getGameState(board);
    displayWinner(winner);


}
