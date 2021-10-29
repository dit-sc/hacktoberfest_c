#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#define MINLIVES 1
#define MAXLIVES 10

#define MINPATHLENGTH 10
#define MAXPATHLENGTH 70
#define MULTIPLE 5

int i, t, done, min_moves, max_moves;

struct PlayerInfo
{
	int lives;
	char symbol;
	int treasure;
	int history[MAXPATHLENGTH];
};

struct GameInfo
{
	int moves;
	int pathlength;
	int bombs[MAXPATHLENGTH];
	int treasure[MAXPATHLENGTH];
};


int main(void)
{
	struct PlayerInfo PI;
	struct GameInfo GI;
	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");

	// player configuration start
	printf("PLAYER Configuration\n");
	printf("--------------------\n");

	printf("Enter a single character to represent the player: ");
	scanf(" %c", &PI.symbol);

	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &PI.lives);

		if (PI.lives < MINLIVES || PI.lives > MAXLIVES)
		{
			printf("     Must be between %d and %d!\n", MINLIVES, MAXLIVES);
			done = 0;
		}
		else
		{
			done = 1;
		}
	} while (done == 0);

	printf("Player configuration set-up is complete\n\n");
	// player configuration end


	//game configuration start
	printf("GAME Configuration\n");
	printf("------------------\n");

	do
	{
		printf("Set the path length (a multiple of %d between %2d-%2d): ", MULTIPLE, MINPATHLENGTH, MAXPATHLENGTH);
		scanf("%d", &GI.pathlength);
		if (GI.pathlength < MINPATHLENGTH || GI.pathlength > MAXPATHLENGTH || GI.pathlength % MULTIPLE != 0)
		{
			printf("     Must be a multiple of %d and between %2d-%2d!!!\n", MULTIPLE, MINPATHLENGTH, MAXPATHLENGTH);
			done = 0;
		}
		else
		{
			done = 1;
		}
	} while (done == 0);



	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &GI.moves);

		min_moves = PI.lives;
		max_moves = GI.pathlength * 0.75;

		if (GI.moves < min_moves || GI.moves > max_moves)
		{
			printf("    Value must be between %d and %d\n", min_moves, max_moves);
		}
	} while (GI.moves < min_moves || GI.moves > max_moves);



	// Bomb Placement
	printf("\nBOMB Placement");
	printf("\n--------------\n");
	printf("Enter the bomb positions in sets of %d where a value\n", MULTIPLE);
	printf("of 1=BOMB,and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", GI.pathlength);

	for (i = 0; i < (GI.pathlength / MULTIPLE); i++)
	{
		printf("  Positions [%2d-%2d]: ", MULTIPLE * i + 1, MULTIPLE * i + MULTIPLE);

		for (t = 0; t < MULTIPLE; t++)
		{
			scanf("%d", &GI.bombs[t + (MULTIPLE * i)]);
		}
	}
	printf("\nBOMB placement set\n\n");


	// Treasure Placement
	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of %d where a value\n", MULTIPLE);
	printf("of 1 = TREASURE, and 0 = NO TREASURE.Space - delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", GI.pathlength);

	for (i = 0; i < (GI.pathlength / MULTIPLE); i++)
	{
		printf("  Positions [%2d-%2d]: ", MULTIPLE * i + 1, MULTIPLE * i + MULTIPLE);

		for (t = 0; t < MULTIPLE; t++)
		{
			scanf("%d", &GI.treasure[t + (MULTIPLE * i)]);
		}
	}

	printf("\nTREASURE placement set\n\n");

	printf("GAME configuration set-up is complete...\n\n");
	//game configuration end


	// Treasure hunt configuration settings
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");

	// Player summary
	printf("Player:");
	printf("\n  Symbol     : %c", PI.symbol);
	printf("\n  Lives      : %d", PI.lives);
	printf("\n  Treasure   : [ready for gameplay]");
	printf("\n  History    : [ready for gameplay]");


	// Game summary
	printf("\n\nGame: ");
	printf("\n  Path Length: %d\n", GI.pathlength);
	printf("  Bombs      : ");
	for (i = 0; i < GI.pathlength; i++)
	{
		printf("%d", GI.bombs[i]);
	}
	printf("\n");
	printf("  Treasure   : ");
	for (i = 0; i < GI.pathlength; i++)
	{
		printf("%d", GI.treasure[i]);
	}

	//End
	printf("\n\n====================================");
	printf("\n~ Get ready to play TREASURE HUNT! ~");
	printf("\n====================================");


	return 0;
}
