#pragma once

class FGrid
{
public:
    FGrid();
    ~FGrid();

    void MakeMove(char Position, char CharacterMoveIcon);

private:
    void InitializeGrid() const;

    void RePrintGrid();

    char CurrentGridState[9];

    const char* EmptyRow = "     |     |     ";
    const char* BoundaryRow = "-----+-----+-----";
    const char StartCharacter = 'A';
    const char EndCharacter = 'I';
};

