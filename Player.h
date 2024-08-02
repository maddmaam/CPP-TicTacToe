#pragma once
#include <cstdint>

#include "FGrid.h"

class Player
{
public:
    Player();
    Player(FGrid* Grid, char IndicatorCharacter);
    ~Player();

    void MakeMove() const;

private:
    FGrid* GameGrid;
    char PlayerChar;
    const char StartChar = 'A';
    const char EndValidChar = 'I';
};
