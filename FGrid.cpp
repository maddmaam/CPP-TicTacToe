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

bool FGrid::MakeMove(char Position, char CharacterMoveIcon, PROD225Colours MoveColour, int& NumInvalidMoves)
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
    RePrintGrid(Position, CharacterMoveIcon, MoveColour, NumInvalidMoves);
    GridPlacements++;
    return true;
}


/**
 * \brief Call to determine if a player has won the game (or it has ended as a result of a draw)
 * \param OutPlayerWon The Player (or in the case of the draw the draw message) that won.
 * \return True if the game is over
 */
bool FGrid::PlayerWon(char& OutPlayerWon) const
{
    // Check Diagonals
    const char TopLeftPlayer = CurrentGridState[0];
    if (TopLeftPlayer == CurrentGridState[4] && TopLeftPlayer == CurrentGridState[8])
    {   // Diagonal Top Left to Bottom Right
        OutPlayerWon = TopLeftPlayer;
        return true;
    }
    const char TopRightPlayer = CurrentGridState[2];
    if (TopRightPlayer == CurrentGridState[4] && TopRightPlayer == CurrentGridState[6])
    {   // Diagonal Top Right to Bottom Left
        OutPlayerWon = TopRightPlayer;
        return true;
    }

    for (int GridPos = 1; GridPos < NumGridMembers; GridPos+=NumberOfRows)
    {   // Check the Horizontals
        if (CurrentGridState[GridPos-1] == CurrentGridState[GridPos]
            && CurrentGridState[GridPos] == CurrentGridState[GridPos+1])
        {
            OutPlayerWon = CurrentGridState[GridPos];
            return true;
        }
    }

    for (int GridMiddlePos = 0; GridMiddlePos < MiddleRowOffset; GridMiddlePos++)
    {   // Check the Verticals
        if (CurrentGridState[GridMiddlePos] == CurrentGridState[GridMiddlePos+MiddleRowOffset] &&
            CurrentGridState[GridMiddlePos] == CurrentGridState[GridMiddlePos+BottomRowOffset])
        {
            OutPlayerWon = CurrentGridState[GridMiddlePos];
            return true;
        }
    }

    if (GridPlacements >= 9)
    {
        OutPlayerWon = 'Z';
        return true;
    }
    
    return false;
}

void FGrid::InitializeGrid() const
{
    std::cout << BoundaryRow << '\n';
    for (char StartingCharacter = StartCharacter; StartingCharacter < 'H'; StartingCharacter += NumberOfRows)
    {
        std::cout << EmptyRow << '\n';
        std::cout << "  " << StartingCharacter << "  |  " << static_cast<char>(StartingCharacter+1) <<"  |  " << static_cast<char>(StartingCharacter+2) << '\n';
        std::cout << EmptyRow << '\n';
        std::cout << BoundaryRow << '\n';
    }
}

void FGrid::RePrintGrid(char ChangedCharacter, char CharacterMoveIcon, PROD225Colours MoveColour, int& NumberOfInvalidAttempts) const
{
    const int RawCharacterPosition = StartCharGridX + (ChangedCharacter - StartCharacter) * GridXDiff;
    const int CharacterPositionX = RawCharacterPosition % (NumberOfRows * GridXDiff);
    const int CharacterPositionY = RawCharacterPosition / (NumberOfRows * GridXDiff) * GridYDiff + StartCharGridY;
    // The lines below Replace the current printed grid with a coloured background version with the symbol (O or X) of the player
    SetTextColour(WHITE, MoveColour);
    MoveCursorTo(CharacterPositionX-1, CharacterPositionY-1);
    std::cout << "   ";
    MoveCursorTo(CharacterPositionX-1, CharacterPositionY); 
    std::cout << " " << CharacterMoveIcon << " ";
    MoveCursorTo(CharacterPositionX-1, CharacterPositionY+1);
    std::cout << "   ";

    for (int InvalidAttemptRowOffset = 0; InvalidAttemptRowOffset <= NumberOfInvalidAttempts; InvalidAttemptRowOffset++)
    {
        SetTextColour(WHITE, BLACK);
        MoveCursorTo(0, NumberOfRows * GridYDiff + StartCharGridY - 1 + InvalidAttemptRowOffset);
        std::cout << "                                  " << '\n'; // Massive string of spaces to clear all text
    }
    MoveCursorTo(0, NumberOfRows * GridYDiff + StartCharGridY - 1);
}
