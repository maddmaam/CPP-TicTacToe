
#include <iostream>
#include "Player.h"

#include <conio.h>
#include <locale>

Player::Player()
= default;

Player::Player(FGrid* Grid, const char IndicatorCharacter, PROD225Colours PlayerColour)
{
    GameGrid = Grid;
    PlayerChar = IndicatorCharacter;
    Colour = PlayerColour;
}

Player::~Player()
= default;

void Player::MakeMove(bool& PlayerQuit) const
{
    char PlayerWon;
    if (GameGrid->PlayerWon(PlayerWon))
    {
        return;
    }
    SetTextColour(WHITE, Colour);
    int NumInvalidMoves = 0;
    char LastChar = 127;
    do
    {
        if (LastChar != 127)
        {
            std::cout << "Invalid Move!" << '\n';
            NumInvalidMoves++;
        }
        std::cout << PlayerChar << "'s turn: ";
        LastChar = _getch();
        if (LastChar == 'q' || LastChar == 'Q')
        {
            PlayerQuit = true;
            return;
        }
        LastChar = std::toupper(LastChar);
    }
    while (!GameGrid->MakeMove(LastChar, PlayerChar, Colour, NumInvalidMoves));
}
