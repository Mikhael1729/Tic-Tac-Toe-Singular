#include <stdio.h>
#include <iostream>
#include "HPPFiles/Board.hpp"
#include "HPPFiles/Tourneuse.hpp"
#include "HPPFiles/Player.hpp"

using namespace std;

string title = "UN TIC TAC TOE SINGULAR";
string line = "-----------------------";

// Instantiating the board.
Board board = Board();
Player player1 = Player("Jugador 1", "x");
Player player2 = Player("Jugador 2", "o");

Tourneuse tourneuse = Tourneuse(player1, player2);

void refreshTheScreen()
{
    system("cls");
    cout << title << endl;
    cout << line << endl;
    board.Draw();
    cout << "" << endl;
    cout << "" << endl;
    tourneuse.ChangeTheShift();
}

int main () 
{
    cout << title << endl;
    cout << line << endl;

    board.Build();
    board.Draw();
    cout << "" << endl;
    cout << "" << endl;

    Player currentPlayer = Player();
    bool gameOver = false;

    do 
    {
        if (tourneuse.TurnOfPlayerOne())
            currentPlayer = player1;
        else 
            currentPlayer = player2;

        int position;
        cout << "Turno de " + currentPlayer.Name + ": ";
        cin >> position;

        tourneuse.PlacePieceOnTheBoard(board.board, position, currentPlayer.Piece);
        refreshTheScreen();

        int winner = tourneuse.IsThereAreWinner();

        if (winner == 1)
        {
            refreshTheScreen();
            cout << "El ganador es: "  + player1.Name << endl;
        }
        else if(winner == -1)
        {
            refreshTheScreen();
            cout << "El ganador es: " + player2.Name << endl;
        }
        else if (winner == 2)
        {
            refreshTheScreen();
            cout << "Es un empate." << endl;
        }
        
        if (winner != 0)
        {
            char choice;
            cout << "" << endl;
            cout << "- Desean jugar nuevamente (s/n): ";
            cin >> choice;

            if (choice == 's')
            {
                board.Build();
                tourneuse.CleanPlays();
                refreshTheScreen();
                if (tourneuse.TurnOfPlayerTwo())
                    tourneuse.ChangeTheShift();
                gameOver = false;
            }
            else
                gameOver = true;
        }
        
        else
            gameOver = false;


    } while(!gameOver);

    cout << "" << endl;
    cout << "" << endl;

    system("pause");
}