#include <winerror.h>
#include <conio.h>
#include <iostream>

#include "FGrid.h"
#include "Player.h"

int main() 
{
	std::cout << "   Tic-Tac-Toe" << '\n';
	std::cout << " Press Q to quit" << '\n';
	FGrid Grid;
	Player PlayerOne(&Grid, 'X', RED);
	Player PlayerTwo(&Grid, 'O', BLUE);
	char WinnerPlayer;
	bool PlayerQuit = false;
	while (!Grid.PlayerWon(WinnerPlayer))
	{
		PlayerOne.MakeMove(PlayerQuit);
		if (PlayerQuit)
		{
			return NO_ERROR;
		}
		PlayerTwo.MakeMove(PlayerQuit);
		if (PlayerQuit)
		{
			return NO_ERROR;
		}
	}
	if (WinnerPlayer == 'Z')
	{
		std::cout << "RESULT:      Draw" << '\n';
	}
	else
	{
		std::cout << "RESULT:    " << WinnerPlayer << " wins" << '\n';
	}
	return NO_ERROR;
}