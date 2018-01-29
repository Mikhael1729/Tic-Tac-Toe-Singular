#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Player 
{
    public:
        string Name;
        string Piece;
        
    public:
        Player(string, string);
        Player();
};

#endif