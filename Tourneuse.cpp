#include "HPPFiles/Tourneuse.hpp"

using namespace std;

Tourneuse::Tourneuse(Player p1, Player p2)
{
    player1 = p1;
    player2 = p2;
    turn = 1;
}

void Tourneuse::PlacePieceOnTheBoard(string board[5][17], int position, string piece)
{
    int travelThroughTheAvailableColumns = 0; // Recorrido del array bidimensional como si fuera unidireccional.
    int availableColumns[3] = { 2, 8, 14 };
    bool disableRow;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 17; j++)
        {
            if ((i % 2 == 0) && (j == availableColumns[0] || j == availableColumns[1] || j == availableColumns[2]))
            {
                travelThroughTheAvailableColumns ++;

                if (travelThroughTheAvailableColumns == position) 
                {
                    board[i][j] = piece;

                    if (TurnOfPlayerOne())
                        placePieceOnTheVirtualBoardOfPlayerOne(position, piece);
                    else
                        placePieceOnTheVirtualBoardOfPlayerTwo(position, piece);
                }
            }   
        }
    }
}

void Tourneuse::placePieceOnTheVirtualBoardOfPlayerOne(int position, string piece)
{
    int travel = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            travel ++;
            if (travel == position)
                virtualBoardOfPlayerOne[i][j] = piece;
        }
    }   
}

void Tourneuse::placePieceOnTheVirtualBoardOfPlayerTwo(int position, string piece)
{
    int travel = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            travel++;
            if (travel == position)
                virtualBoardOfPlayerTwo[i][j] = piece;
        }
    }
}

void Tourneuse::ChangeTheShift()
{
    turn = turn * -1;
}

bool Tourneuse::TurnOfPlayerOne()
{
    if (turn == 1)
        return true;
    else
        return false;
}

bool Tourneuse::TurnOfPlayerTwo()
{
    if (turn != 1)
        return true;
    else
        return false;
}

int Tourneuse::IsThereAreWinner()
{
    bool playerOneIsTheWinner = playerOneHasWon();
    bool playerTwoIsTheWinner = playerTwoHasWon();
    bool isTie = IsTie();

    if (playerOneIsTheWinner)
        return 1;
    else if (playerTwoIsTheWinner)
        return -1;
    else if (isTie)
        return 2;
    else
        return 0;
}

bool Tourneuse::IsTie()
{
    int count = 0; 
    string mergeOfVirtualBoards[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {   
            mergeOfVirtualBoards[i][j] = virtualBoardOfPlayerOne[i][j];
            if (mergeOfVirtualBoards[i][j] == player1.Piece)
                count++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mergeOfVirtualBoards[i][j] = virtualBoardOfPlayerTwo[i][j];
            if (mergeOfVirtualBoards[i][j] == player2.Piece)
                count++;
        }
    }

    if (count == 9)
        return true;
    else    
        return false;    
}

bool Tourneuse::playerOneHasWon()
{
    string row1, row2, row3;
    string col1, col2, col3;
    string diag1, diag2;

    string espectedSection = player1.Piece + player1.Piece + player1.Piece;

    // Reading cols and rows
    for (int i = 0; i < 3; i++) 
    {
        // Row.
        col1 += virtualBoardOfPlayerOne[i][0];
        col2 += virtualBoardOfPlayerOne[i][1];
        col3 += virtualBoardOfPlayerOne[i][2];

        // Cols.
        row1 += virtualBoardOfPlayerOne[0][i];
        row2 += virtualBoardOfPlayerOne[1][i];
        row3 += virtualBoardOfPlayerOne[2][i];
    }

    // Reading diagonals
    for (int i = 0; i < 3; i++)
    {
        // Diagonal left.
        for (int j = 0; j < 3; j++)
        {
            if (j == i)
                diag1 +=  virtualBoardOfPlayerOne[i][j];
        }

        // Diagonal right.
        for (int j = 2; j >= 0; j--)
        {
            if((j==2 && i == 0) || (j == 1 && i == 1) || (j == 0 && i == 2))
                diag2 +=  virtualBoardOfPlayerOne[i][j];
        }
    }

    // Evaluating.
    if (row1 == espectedSection || row2 == espectedSection || row3 == espectedSection || col1 == espectedSection || col2 == espectedSection || col3 == espectedSection || diag1 == espectedSection || diag2 == espectedSection)
        return true;
    else
        return false;
}

bool Tourneuse::playerTwoHasWon()
{
    string row1, row2, row3;
    string col1, col2, col3;
    string diag1, diag2, diag3, diag4;

    string espectedSection = "" + player2.Piece + player2.Piece + player2.Piece;

    // Reading cols and rows
    for (int i = 0; i < 3; i++)
    {
        // Row.
        col1 +=  virtualBoardOfPlayerTwo[i][0];
        col2 +=  virtualBoardOfPlayerTwo[i][1];
        col3 +=  virtualBoardOfPlayerTwo[i][2];

        // Cols.
        row1 +=  virtualBoardOfPlayerTwo[0][i];
        row2 +=  virtualBoardOfPlayerTwo[1][i];
        row3 +=  virtualBoardOfPlayerTwo[2][i];
    }

    // Reading diagonals
    for (int i = 0; i < 3; i++)
    {
        // Diagonal left.
        for (int j = 0; j < 3; j++)
        {
            if (j == i)
                diag1 +=  virtualBoardOfPlayerTwo[i][j];
        }

        // Diagonal right.
        for (int j = 2; j >= 0; j--)
        {
            if ((j == 2 && i == 0) || (j == 1 && i == 1) || (j == 0 && i == 2))
                diag2 +=  virtualBoardOfPlayerTwo[i][j];
        }
    }

    // Evaluating.
    if (row1 == espectedSection || row2 == espectedSection || row3 == espectedSection || col1 == espectedSection || col2 == espectedSection || col3 == espectedSection || diag1 == espectedSection || diag2 == espectedSection)
        return true;
    else
        return false;
}

void Tourneuse::CleanPlays()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            virtualBoardOfPlayerOne[i][j] = " ";
            virtualBoardOfPlayerTwo[i][j] = " ";
        }
    }
}