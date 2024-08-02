#pragma once

class FGrid
{
public:
    FGrid();
    ~FGrid();

    bool MakeMove(char Position, char CharacterMoveIcon);
    bool PlayerWon(char& OutPlayerWon);

private:
    void InitializeGrid() const;

    void RePrintGrid(char ChangedCharacter, char CharacterMoveIcon) const;

    char CurrentGridState[10];

    const char* EmptyRow = "     |     |     ";
    const char* BoundaryRow = "-----+-----+-----";
    const char StartCharacter = 'A';
    const char EndCharacter = 'I';
    const int StartCharGridX = 2;
    const int StartCharGridY = 1;
    const int GridYDiff = 4;
    const int GridXDiff = 6;
    const int NumberOfRows = 3;
};

