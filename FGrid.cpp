#include <cstring>
#include <iostream>

#include "include/prod225colour.h"

#include "FGrid.h"

FGrid::FGrid()
{
    InitializeGrid();
    constexpr char GridState[] {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', '\0'};
    strcpy_s(CurrentGridState, GridState);
}

FGrid::~FGrid()
{}

bool FGrid::MakeMove(char Position, char CharacterMoveIcon)
{
    if (Position > EndCharacter)
    {
        return false;
    }
    const int GridPosition = Position - StartCharacter;
    if (CurrentGridState[GridPosition] == 'X' || CurrentGridState[GridPosition] == 'O')
    {
        return false;
    }
    CurrentGridState[GridPosition] = CharacterMoveIcon;
    RePrintGrid(Position, CharacterMoveIcon);
    return true;
}

bool FGrid::PlayerWon(char& OutPlayerWon)
{
    // TODO: CHECK DIAGONALS AND HORIZONTAL/VERTICAL
    return false;
}

void FGrid::InitializeGrid() const
{
    for (char StartingCharacter = StartCharacter; StartingCharacter < 'H'; StartingCharacter += NumberOfRows)
    {
        std::cout << EmptyRow << '\n';
        std::cout << "  " << StartingCharacter << "  |  " << static_cast<char>(StartingCharacter+1) <<"  |  " << static_cast<char>(StartingCharacter+2) << '\n';
        std::cout << EmptyRow << '\n';
        std::cout << BoundaryRow << '\n';
    }
}

void FGrid::RePrintGrid(char ChangedCharacter, char CharacterMoveIcon) const
{
    const int RawCharacterPosition = StartCharGridX + (ChangedCharacter - StartCharacter) * GridXDiff;
    const int CharacterPositionX = RawCharacterPosition % (NumberOfRows * GridXDiff);
    const int CharacterPositionY = RawCharacterPosition / (NumberOfRows * GridXDiff) * GridYDiff + StartCharGridY;
    MoveCursorTo(CharacterPositionX, CharacterPositionY);
    std::cout << CharacterMoveIcon;
    MoveCursorTo(0, NumberOfRows * GridYDiff + StartCharGridY - 1);
}
