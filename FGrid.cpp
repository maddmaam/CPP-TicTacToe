#include <cstring>
#include <iostream>

#include "include/prod225colour.h"

#include "FGrid.h"

FGrid::FGrid()
{
    InitializeGrid();
    constexpr char GridState[] {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    strcpy_s(CurrentGridState, GridState);
}

FGrid::~FGrid()
= default;

void FGrid::MakeMove(char Position, char CharacterMoveIcon)
{
    if (Position > EndCharacter)
    {
        return;
    }
    const int GridPosition = StartCharacter - Position;
    if (CurrentGridState[GridPosition] == 'X' || CurrentGridState[GridPosition] == 'O')
    {
        std::cout << "Invalid Move!" << '\n';
    }
    CurrentGridState[GridPosition] = CharacterMoveIcon;
}

void FGrid::InitializeGrid() const
{
    for (char StartingCharacter = StartCharacter; StartingCharacter < 'H'; StartingCharacter += 3)
    {
        std::cout << EmptyRow << '\n';
        std::cout << "  " << StartingCharacter << "  |  " << static_cast<char>(StartingCharacter+1) <<"  |  " << static_cast<char>(StartingCharacter+2) << '\n';
        std::cout << EmptyRow << '\n';
        std::cout << BoundaryRow << '\n';
    }
}

void FGrid::RePrintGrid()
{
    // MoveCursorTo();
}
