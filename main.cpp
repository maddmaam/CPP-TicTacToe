#include <winerror.h>
#include <conio.h>
#include "FGrid.h"
#include "Player.h"

int main() 
{
	FGrid Grid;
	Player PlayerOne(&Grid, 'X');
	Player PlayerTwo(&Grid, 'O');
	char WinnerPlayer;
	while (!Grid.PlayerWon(WinnerPlayer))
	{
		PlayerOne.MakeMove();
		PlayerTwo.MakeMove();
	}
	return NO_ERROR;
}
