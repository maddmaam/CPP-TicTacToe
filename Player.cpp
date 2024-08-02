
#include <iostream>
#include "Player.h"

#include <conio.h>

Player::Player()
= default;

Player::Player(FGrid* Grid, const char IndicatorCharacter)
{
    GameGrid = Grid;
    PlayerChar = IndicatorCharacter;
}

Player::~Player()
= default;

void Player::MakeMove() const
{
    char LastChar = 127;
    do
    {
        if (LastChar != 127)
        {
            std::cout << "Invalid Move!" << '\n';
        }
        std::cout << PlayerChar << "'s turn: ";
        LastChar = _getch();
    }
    while (!GameGrid->MakeMove(LastChar, PlayerChar));
}
