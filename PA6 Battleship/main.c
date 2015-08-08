#include "Header.h"


int main (void)
{
	char p1_board [MAX][MAX], p2_board [MAX][MAX], p1_shots[MAX][MAX], p2_shots[MAX][MAX];
	char ship_type[12] = {'\0'};
	char ship_hit = '\0';
	int p1_ship_health[5] = {5, 4, 3, 3, 2}, p2_ship_health[5] = {5, 4, 3, 3, 2};
	int whose_turn = 1, selection = 0, shot_y = 0, shot_x = 0, hit_or_miss = 0;
	FILE *output = NULL;
	Stats p1 = {0};
	Stats p2 = {0};

	//srand ( (unsigned int) time );

	output = fopen("battleship.log", "w");
	

	initialize_game_board(p1_board, MAX, MAX);
	initialize_game_board(p1_shots, MAX, MAX);
	initialize_game_board(p2_board, MAX, MAX);
	initialize_game_board(p2_shots, MAX, MAX);

	

	welcome_screen ();
	system("Pause");

//Set up the human player's board. 
	do  //Place ships
	{
		system("CLS");
		printf(	"Please select from the following menu:\n"
				"1. Enter positions of your ships manually\n"
				"2. Allow the program to randomly select positions of your ships\n" );
		flushall();
		scanf( "%d", &selection );
	}while ( (selection != 1) && (selection != 2) );

	if (selection == 1)
		manually_place_ships(p1_board, MAX, MAX);
	else
	{
		randomly_place_ships(p1_board, MAX, MAX);
		printf("Your ships have been randomly placed.\n");
	}

//Set up the computer player's board. 

	randomly_place_ships(p2_board, MAX, MAX);
	printf("Player 2 (Computer's) board has been generated.\n");
	
	whose_turn = select_who_starts_first();
	printf("Player %d has been randomly chosen to start.\n", whose_turn);
	fprintf(output, "Player %d has been randomly chosen to start.\n\n", whose_turn);


	system("Pause");

	if (whose_turn == 1)
		goto p1_turn;
	else 
		goto p2_turn;


	do  //Play round of Battleship
	{
		
p1_turn:

		ship_hit = '\0'; //Resets the ship hit. Prevents an "is_sunk" error. 

		do //Displays board and shots. 
		{
			system("CLS");
			printf("Player 1's Board:\n");
			print_board(p1_board, MAX, MAX);
			printf("\nPlayer 2's Board:\n");
			print_board(p1_shots, MAX, MAX);

			//Gathers target. 
			printf("Enter your target: ");
			flushall();
			scanf("%d%d", &shot_y, &shot_x);
		}while ( (shot_y < 0) || (shot_y > 9) || (shot_x < 0) || (shot_x > 9) || //Makes sure shot is within bounds
				 (is_repeat_shot(p1_shots, shot_y, shot_x) == 1) ); //Makes sure shot isn't repeated
		
		fprintf(output, "Player 1 targeted %d %d.\n", shot_y, shot_x);

		hit_or_miss = check_shot(p2_board, shot_y, shot_x);
		
		if (hit_or_miss == 1)
		{
			printf("%d %d is a hit!\n", shot_y, shot_x);
			fprintf(output, "%d %d is a hit!\n", shot_y, shot_x);

			ship_hit = which_ship_hit(p2_board, shot_y, shot_x, ship_type);
			update_ship_health(ship_hit, p2_ship_health);

			if ( is_sunk(ship_hit, p2_ship_health) == 1 )
			{
				printf("You sunk their %s!\n", ship_type);
				fprintf(output, "Player 1 sunk Player 2's %s!\n", ship_type);
			}

			p1.hits ++;
		}

		else
		{
			printf("%d %d is a miss.\n", shot_y, shot_x);
			fprintf(output, "%d %d is a miss.\n", shot_y, shot_x);

			p1.misses ++;
		}
		update_hit_miss(p1_shots, p2_board, hit_or_miss, shot_y, shot_x);

		system("Pause");
		
		p1.turns ++;
		whose_turn = 2;

		if ( 1 == is_victor(p1_ship_health, p2_ship_health) ) //End the game if player 1 has won at the end of their turn. 
		{
			goto end_game;
		}

p2_turn:

		ship_hit = '\0'; //Resets the ship hit. Prevents an "is_sunk" error. 

		//Displays board and shots. 
		system("CLS");
		printf("Player 1's Board:\n");
		print_board(p1_board, MAX, MAX);
		printf("\nPlayer 2's Board:\n");
		print_board(p1_shots, MAX, MAX);

		fprintf(output, "\n"); //Adds a line break between player turns. 

		do //Gathers target.
		{
			shot_y = random_shot();
			shot_x = random_shot();

		}while ( is_repeat_shot(p2_shots, shot_y, shot_x) == 1 ); //Checks if shot is repeated.
		
		printf("Computer Selects: %d %d\n", shot_y, shot_x);
		fprintf(output, "Player 2 (Computer) targeted: %d %d.\n", shot_y, shot_x);

		hit_or_miss = check_shot(p1_board, shot_y, shot_x);
		
		if (hit_or_miss == 1)
		{
			printf("%d %d is a hit!\n", shot_y, shot_x);
			fprintf(output, "%d %d is a hit!\n", shot_y, shot_x);

			ship_hit = which_ship_hit(p1_board, shot_y, shot_x, ship_type);
			update_ship_health(ship_hit, p1_ship_health);

			if ( is_sunk(ship_hit, p1_ship_health) == 1 )
			{
				printf("They sunk your %s!", ship_type);
				fprintf(output, "Player 2 sunk Player 1's %s!\n", ship_type);
			}

			p2.hits ++;

		}

		else
		{
			printf("%d %d is a miss.\n", shot_y, shot_x);
			fprintf(output, "%d %d is a miss.\n", shot_y, shot_x);

			p2.misses ++;
		}

		update_hit_miss(p2_shots, p1_board, hit_or_miss, shot_y, shot_x);

		system("Pause");

		p2.turns ++;
		whose_turn = 1;

		fprintf(output, "\n"); //Adds a line break between player turns. 

	}while ( 0 == is_victor(p1_ship_health, p2_ship_health) ); //Nobody has won. 
	
end_game:

	if ( 1 == is_victor(p1_ship_health, p2_ship_health) )
	{
		printf("Player 1 Wins!!!\n");
		fprintf(output, "Player 1 Wins!!!\n\n");
	}
	else
	{
		printf("Player 2 Wins!!!\n");
		fprintf(output, "Player 2 Wins!!!\n\n");
	}


	
	//Export various data. 
	fprintf(output, "Player 1 shots: %d\n", p1.turns);
	fprintf(output, "Player 1 hits: %d\n", p1.hits);
	fprintf(output, "Player 1 misses: %d\n", p1.misses);

	if ( 0 == p1.misses ) //Prevents a divide by zero error when calculating the hit to miss ratio. 
		p1.misses ++;

	fprintf(output, "Player 1 hit to miss ratio: %%%.2lf\n\n", ( 100 * ((double) p1.hits) / p1.turns ) );



	fprintf(output, "Player 2 shots: %d\n", p2.turns);
	fprintf(output, "Player 2 hits: %d\n", p2.hits);
	fprintf(output, "Player 2 misses: %d\n", p2.misses);

	if ( 0 == p2.misses ) //Prevents a divide by zero error when calculating the hit to miss ratio. 
		p2.misses ++;

	fprintf(output, "Player 2 hit to miss ratio: %%%.2lf\n\n", ( 100 * ((double) p2.hits) / p2.turns ) );

	printf("Log Compiled Successfully.\n");
	fprintf(output, "Log Compiled Successfully.");

	fclose(output);

	return 0;
}