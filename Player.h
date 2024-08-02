#pragma once
#include <cstdint>

#include "FGrid.h"

class Player
{
public:
    Player();
    Player(const FGrid& Grid);
    ~Player();

    void MakeMove(char GridChar);

private:
    FGrid GameGrid;
};
