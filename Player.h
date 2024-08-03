#pragma once

#include <prod225colour.h>

#include "FGrid.h"

class Player
{
public:
    Player();
    Player(FGrid* Grid, char IndicatorCharacter, PROD225Colours PlayerColour);
    ~Player();

    void MakeMove(bool& PlayerQuit) const;

private:
    FGrid* GameGrid;
    char PlayerChar;
    const char StartChar = 'A';
    const char EndValidChar = 'I';
    PROD225Colours Colour;
};
