#include <stdio.h>
#include <iostream>
#include <string>
#include "HPPFiles/Board.hpp"

using namespace std;

Board::Board()
{
    numberOfRows = 5;
    numberOfColumns = 17;
}

void Board::Build()
{
    for (int row = 0; row < numberOfRows; row++)
    {
        for (int column = 0; column < numberOfColumns; column++)
        {
            // Adding rows.
            if ((row % 2 == 0) && (column != 5 || column != 10))
                board[row][column] = " ";
            else
                board[row][column] = "-";

            // Adding columns.
            if (column == 5 || column == 11)
                board[row][column] = "|";
        }
    }
}

void Board::Draw()
{
    for (int i = 0; i < numberOfRows; i++)
    {
        cout << "" << endl;
        for (int j = 0; j < numberOfColumns; j++)
        {
            cout << board[i][j];
        }
    }
}

void Board::Erase()
{
    for (int i = 0; i < numberOfColumns; i++)
    {
        for (int j = 0; j< numberOfRows; j++)
        {
            board[i][j] = "";
        }
    }
}