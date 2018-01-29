#ifndef TOURNEUSE_HPP
#define TOURNEUSE_HPP

#include <stdio.h>
#include <iostream>
#include <string>

#include "Board.hpp"
#include "Player.hpp"

using namespace std;

class Tourneuse
{
    private: 
        Board board;
        Player player1;
        Player player2;
        string virtualBoardOfPlayerOne[3][3];
        string virtualBoardOfPlayerTwo[3][3];
        int turn;

    public:
        Tourneuse(Player, Player);
        void PlacePieceOnTheBoard(string[5][17], int, string);
        int IsThereAreWinner();
        void ChangeTheShift();
        bool TurnOfPlayerOne();
        bool TurnOfPlayerTwo();
        bool IsTie();
        void CleanPlays();

    private:
      void placePieceOnTheVirtualBoardOfPlayerOne(int, string);
      void placePieceOnTheVirtualBoardOfPlayerTwo(int, string);
      bool playerOneHasWon();
      bool playerTwoHasWon();
};

#endif