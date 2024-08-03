#pragma once

#include "include/prod225colour.h"

class FGrid
{
public:
    FGrid();
    ~FGrid();

    bool MakeMove(char Position, char CharacterMoveIcon, PROD225Colours MoveColour, int& NumInvalidMoves);
    bool PlayerWon(char& OutPlayerWon) const;

private:
    void InitializeGrid() const;

    void RePrintGrid(char ChangedCharacter, char CharacterMoveIcon, PROD225Colours MoveColour, int& NumberOfInvalidAttempts) const;

    char CurrentGridState[10];
    int GridPlacements = 0;

    const char* EmptyRow = "     |     |     ";
    const char* BoundaryRow = "-----+-----+-----";
    const char StartCharacter = 'A';
    const char EndCharacter = 'I';
    const int StartCharGridX = 2;
    const int StartCharGridY = 4;
    const int GridYDiff = 4;
    const int GridXDiff = 6;
    const int NumberOfRows = 3;
    const int NumGridMembers = 9;
    const int BottomRowOffset = 6;
    const int MiddleRowOffset = 3;
};

