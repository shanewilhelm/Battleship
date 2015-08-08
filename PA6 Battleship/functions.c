#include "Header.h"

//Prints the title of the game and instructions on how to play. 
void welcome_screen (void)
{
	//Font from patorjk.com
	printf (
		" ____              __    __    ___               ____    __                    \n"
		"/\\  _`\\           /\\ \\__/\\ \\__/\\_ \\             /\\  _`\\ /\\ \\      __           \n"
		"\\ \\ \\L\\ \\     __  \\ \\ ,_\\ \\ ,_\\//\\ \\      __    \\ \\,\\L\\_\\ \\ \\___ /\\_\\  _____   \n"
		" \\ \\  _ <'  /'__`\\ \\ \\ \\/\\ \\ \\/ \\ \\ \\   /'__`\\   \\/_\\__ \\\\ \\  _ `\\/\\ \\/\\ '__`\\ \n"
  		"  \\ \\ \\L\\ \\/\\ \\L\\.\\_\\ \\ \\_\\ \\ \\_ \\_\\ \\_/\\  __/     /\\ \\L\\ \\ \\ \\ \\ \\ \\ \\ \\ \\L\\ \\\n"
   		"   \\ \\____/\\ \\__/.\\_\\\\ \\__\\\\ \\__\\/\\____\\ \\____\\    \\ `\\____\\ \\_\\ \\_\\ \\_\\ \\ ,__/\n"
    	"    \\/___/  \\/__/\\/_/ \\/__/ \\/__/\\/____/\\/____/     \\/_____/\\/_/\\/_/\\/_/\\ \\ \\/ \n"
        "                                                                         \\ \\_\\ \n"
        "                                                                          \\/_/ \n\n\n"
		);

	printf (
		"BATTLESHIP\n"
		"is the old favorite Navy Game where two players try to sink each other's hidden ships. Players place their \"fleet\" of 5 ships on their \"ocean\", hidden from the opponent's view. Taking turns, players call out their \"shots\" attempting to get \"hits\" on the opponent's ships in order to sink them. Strategy and some luck must be combined to be the first to locate and sink all 5 opponent's ships to win the game.\n"
		"\nTHE OBJECT OF THE GAME\n\n"
		"is to be the first player to sink all five of his opponent's ships.\n"
		"\nGAMEPLAY\n\n"
		"Each player places their 5 ships on the game board.\n"
		"A player is randomly selected to go first. Each player will take turns selecting coordinates to attack.\n"
		"The attacker will be shown whether or not the shot was a hit.\n"
		"A ship is \"sunk\" if each part of the ship is hit. When a ship is sunk, the attacking player is told.\n"
		"\nENDGAME\n\n"
		"A player wins when they sink all of their opponents ships.\n"
		);



}

//Returns randomly a 1 or a 0. 
int select_who_starts_first (void)
{
	int result = 0;

	result = (rand() % 2) + 1;

	return result;
}

//Initializes all elements of the game board to "-"
void initialize_game_board (char board[MAX][MAX], int rows, int columns)
{
	int i = 0, j = 0;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			board[i][j] = '-';
		}
	}
}

//Prints the gameboard in grid. 
void print_board (char board[MAX][MAX], int rows, int columns)
{
	int i = 0, j = 0;
	int list[10] = {0,1,2,3,4,5,6,7,8,9};

	printf ("  "); //The blank upper-left corner of the game board. 
	for (i = 0; i <= 9; i++)
		printf ("%d ", list[i]);

	printf ("\n");

	for (i = 0; i < rows; i++)
	{
		printf ("%d ", list[i]); 

		for (j = 0; j < columns; j++)
		{
			printf ("%c ", board[i][j]);
		}
		
		printf ("\n");
	}

}

//Allows the player to select where their ships will be placed. 
void manually_place_ships (char board[MAX][MAX], int rows, int columns)
{
	int i = 0, x = 0, y = 0, ship = 0, ship_size = 0;
	char ship_character = '\0';
	char orientation = '\0';

	while (ship <= 4) //Loop until all ships are placed. 
	{

		switch (ship)
		{
		case 0: //Carrier
			{
				ship_size = 5;
				ship_character = 'c';
				do
				{
					system ("CLS");
					print_board (board, MAX, MAX);
					printf ("Would you like to place the Carrier (Length %d) horizontally or vertically? (h/v) ", ship_size);
					flushall();
					scanf ("%c", &orientation);
					orientation = tolower (orientation);
				}while ( (orientation != 'h') && (orientation != 'v') );
				ship ++;
				break;
			}
		case 1: //Battleship
			{
				ship_size = 4;
				ship_character = 'b';
				do
				{
					system ("CLS");
					print_board (board, MAX, MAX);
					printf ("Would you like to place the Battleship (Length %d) horizontally or vertically? (h/v) ", ship_size);
					flushall();
					scanf ("%c", &orientation);
					orientation = tolower (orientation);
				}while ( (orientation != 'h') && (orientation != 'v') );
				ship ++;
				break;
			}
		case 2: //Submarine
			{
				ship_size = 3;
				ship_character = 's';
				do
				{
					system ("CLS");
					print_board (board, MAX, MAX);
					printf ("Would you like to place the Submarine (Length %d) horizontally or vertically? (h/v) ", ship_size);
					flushall();
					scanf ("%c", &orientation);
					orientation = tolower (orientation);
				}while ( (orientation != 'h') && (orientation != 'v') );
				ship ++;
				break;
			}
		case 3: //Cruiser
			{
				ship_size = 3;
				ship_character = 'r';
				do
				{
					system ("CLS");
					print_board (board, MAX, MAX);
					printf ("Would you like to place the Cruiser (Length %d) horizontally or vertically? (h/v) ", ship_size);
					flushall();
					scanf ("%c", &orientation);
					orientation = tolower (orientation);
				}while ( (orientation != 'h') && (orientation != 'v') );
				ship ++;
				break;
			}
		case 4: //Destroyer
			{
				ship_size = 2;
				ship_character = 'd';
				do
				{
					system ("CLS");
					print_board (board, MAX, MAX);
					printf ("Would you like to place the Destroyer (Length %d) horizontally or vertically? (h/v) ", ship_size);
					flushall();
					scanf ("%c", &orientation);
					orientation = tolower (orientation);
				}while ( (orientation != 'h') && (orientation != 'v') );
				ship ++;
				break;
			}
		}


		if ( (orientation == 'h') ) //Place horizontal
		{
			do //Prompt: Where to place ship.
			{
				system ("CLS");
				print_board (board, MAX, MAX);
				printf ("Where would you like to place the left-most point of the ship? (e.g. \"2 5\") ");
				scanf ("%d%d", &y, &x);

			}while (is_valid_placement(1, board, rows, columns, ship_size, orientation, y, x) != 1);

			for (i = 0; i < ship_size; i++)
			{
				board[y][x + i] = ship_character; 
			}

		}

		else
		{
			do //Prompt: Where to place ship. 
			{
				system ("CLS");
				print_board (board, MAX, MAX);
				printf ("Where would you like to place the upper-most point of the ship? (e.g. \"2 5\") ");
				scanf ("%d%d", &y, &x);

			}while (is_valid_placement(1, board, rows, columns, ship_size, orientation, y, x) != 1);

			for (i = 0; i < ship_size; i++)
			{
				board[y + i][x] = ship_character; 
			}
		}
	}
}

//Checks to see if a ship can be placed somewhere within the bounds of the rules.  
int is_valid_placement (int prompt, char board[MAX][MAX], int rows, int columns, int ship_size, char orientation, char y, char x)
{
	int i = 0;

	if ( (x > 9) || (x < 0) || (y > 9) || (y < 0) )
		return 0;

	if (orientation == 'h') //Ship is placed horizontal
	{
		if ((x + ship_size) > 9) //Check if ship fits on board
		{
			if (prompt == 1) {
				printf ("Error: The ship cannot run off the board!\n");
				system ("Pause");
			}
			return 0;
		}

		for (i = 0; i < ship_size; i++) //Check if 2 ships overlap
		{
			if ( (board[y][x + i]) != '-' )
			{
				if (prompt == 1) {
					printf ("Error: Ships cannot overlap!\n");
					system ("Pause");
				}
				return 0;
			}
		}
	}

	else if (orientation == 'v') //Ship placed vertically
	{
		if ((y + ship_size) > 9) //Check if ship fits on board
		{
			if (prompt == 1) {
				printf ("Error: The ship cannot run off the board!\n");
				system ("Pause");
			}
			return 0;
		}

		for (i = 0; i < ship_size; i++) //Check if 2 ships overlap
		{
			if ( (board[y + i][x]) != '-' )
			{
				if (prompt == 1) {
					printf ("Error: Ships cannot overlap!\n");
					system ("Pause");
				}
				return 0;
			}
		}
	}
		
	return 1; //Return 1 if none of the fail conditions are met 
}

//Randomly places the ships on the game board. 
void randomly_place_ships (char board[MAX][MAX], int rows, int columns)
{
	int i = 0, x = 0, y = 0, ship = 0, ship_size = 0;
	char ship_character = '\0';
	char orientation = '\0';

	while (ship <= 4) //Loop until all ships are placed. 
	{

		switch (ship)
		{
		case 0: //Carrier
			{
				ship_size = 5;
				ship_character = 'c';

				if (0 == ( rand() % 2 ))
					orientation = 'h';
				else 
					orientation = 'v';

				ship ++;
				break;
			}
		case 1:
			{
				ship_size = 4;
				ship_character = 'b';

				if (0 == ( rand() % 2 ))
					orientation = 'h';
				else 
					orientation = 'v';

				ship ++;
				break;
			}
		case 2:
			{
				ship_size = 3;
				ship_character = 's';

				if (0 == ( rand() % 2 ))
					orientation = 'h';
				else 
					orientation = 'v';

				ship ++;
				break;
			}
		case 3:
			{
				ship_size = 3;
				ship_character = 'r';
				
				if (0 == ( rand() % 2 ))
					orientation = 'h';
				else 
					orientation = 'v';

				ship ++;
				break;
			}
		case 4:
			{
				ship_size = 2;
				ship_character = 'd';

				if (0 == ( rand() % 2 ))
					orientation = 'h';
				else 
					orientation = 'v';

				ship ++;
				break;
			}
		}


		if ( (orientation == 'h') ) //Place horizontal
		{
			do //Randomly pick two coordinates
			{
				y = rand() % 9 + 1;
				x = rand() % 9 + 1;

			}while (is_valid_placement(0, board, rows, columns, ship_size, orientation, y, x) != 1);

			for (i = 0; i < ship_size; i++)
			{
				board[y][x + i] = ship_character; 
			}

		}

		else
		{
			do //Randomly pick two coordinates
			{
				y = rand() % 9 + 1;
				x = rand() % 9 + 1;

			}while (is_valid_placement(0, board, rows, columns, ship_size, orientation, y, x) != 1);

			for (i = 0; i < ship_size; i++)
			{
				board[y + i][x] = ship_character; 
			}
		}
	}
}

//Determine if shot was hit or miss.
int check_shot (char target_board[MAX][MAX], int shot_y, int shot_x)
{
	if (target_board[shot_y][shot_x] == '-')
		return 0;
	else if (target_board[shot_y][shot_x] == 'm')
		return -1;
	else
		return 1;
}

//Places the appropriate hit/miss symbol on the shot board and the victim's ship board.
void update_hit_miss (char shot_board[MAX][MAX], char victim_board[MAX][MAX], int hit_or_miss, int shot_y, int shot_x)
{
	if (hit_or_miss == 1) {
		shot_board[shot_y][shot_x] = '*';
		victim_board[shot_y][shot_x] = '*';
	}

	else {
		shot_board[shot_y][shot_x] = 'm';
		victim_board[shot_y][shot_x] = 'm';	
	}
}

//updates the health of each ship.
void update_ship_health (char ship_hit, int ship_health[5])
{
	switch ( ship_hit ) 
	{
	case 'c': //Cruiser
		{
			ship_health[0] --;
			break;
		}
	case 'b': //Battleship
		{
			ship_health[1] --;
			break;
		}
	case 's': //Submarine
		{
			ship_health[2] --;
			break;
		}
	case 'r': //Cruiser
		{
			ship_health[3] --;
			break;
		}
	case 'd': //Destroyer
		{
			ship_health[4] --;
			break;
		}
	}
}

//WARNING: Assumes the shot was a hit. 
//Changes the "ship_type" character array to the full name of the ship. Also returns single character sign of ship hit. 
int which_ship_hit (char victim_board[MAX][MAX], int shot_y, int shot_x, char ship_type[12])
{
	char *ship[12];

	ship[0] = ship_type;

	switch ( victim_board[shot_y][shot_x] )
	{
	case 'b':
		{
			strcpy(ship[0], "Battleship");
			break;
		}
	case 'c':
		{
			strcpy(ship[0], "Carrier");
			break;
		}
	case 'r':
		{
			strcpy(ship[0], "Cruiser");
			break;
		}
	case 's':
		{
			strcpy(ship[0], "Submarine");
			break;
		}
	case 'd':
		{
			strcpy(ship[0], "Destroyer");
			break;
		}
	}

	return ( victim_board[shot_y][shot_x] );
}

//Determines if a ship has been sunk. 
int is_sunk (char ship_hit, int ship_health[5])
{
	switch (ship_hit)
	{
	case 'c': //Carrier
		{
			if ( ship_health[0] == 0 )
				return 1;
			break;
		}
	case 'b': //Battleship
		{
			if ( ship_health[1] == 0 )
				return 1;
			break;
		}
	case 's': //Submarine
		{
			if ( ship_health[2] == 0 )
				return 1;
			break;
		}
	case 'r': //Cruiser
		{
			if ( ship_health[3] == 0 )
				return 1;
			break;
		}
	case 'd': //Destroyer
		{
			if ( ship_health[4] == 0 )
				return 1;
			break;
		}
	}
	
	return 0; //If no ships have been sunk.
}

//Checks is comebody has won and returns the victor. 
int is_victor (int p1_ship_health[5], int p2_ship_health[5])
{
	int i = 0, sunk_ships = 0;

	for (i = 0; i < 5; i++)
	{
		if ( p1_ship_health[i] == 0 )
			sunk_ships ++;
	}
	if (sunk_ships == 5)
		return 2; //If player 1 is dead, player 2 wins 
	
	sunk_ships = 0;

	for (i = 0; i < 5; i++)
	{
		if ( p2_ship_health[i] == 0 )
			sunk_ships ++;
	}
	if (sunk_ships == 5)
		return 1; //I player 2 is dead, player 1 wins

	return 0; //Nobody has lost. 
}

//Checks if a shot has been taken before. 
int is_repeat_shot (char shot_board[MAX][MAX], int shot_y, int shot_x)
{
	if ( shot_board[shot_y][shot_x] == '-' )
		return 0;
	else
		return 1;
}

//Picks a nummber between 1 and 9. 
int random_shot ()
{
	return ( rand() % 10 );
}

