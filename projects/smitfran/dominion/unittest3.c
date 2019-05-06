#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(){
	int r;
	int passFlag = 0;
	int seed = 1000;
	int numPlayer = 2;
	int player1 = 0;
	int player2 = 1;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};
	struct gameState G;
	//initialize game
	initializeGame(numPlayer, k, seed, &G);
	printf("\nUnit Test 3: whoseTurn Function\n");
	printf("Testing with 2 players\n");

	//game starts with player1 turn
	r = whoseTurn(&G);
	printf("whoseTurn just started game expected: 0, actual: %d\n", r);
	if (r == 0)
		printf("whoseTurn test PASSED\n");
	else{
		printf("whoseTurn test FAILED\n");
		passFlag = -1;
	}

	//set to player2 turn
	G.whoseTurn = player2;
	r = whoseTurn(&G);
	printf("whoseTurn set to player2 expected: 1, actual: %d\n", r);
	if (r == 1)
		printf("whoseTurn test PASSED\n");
	else{
		printf("whoseTurn test FAILED\n");
		passFlag = -1;
	}

	//report if testcase passed or failed
	if (passFlag == 0)
		printf("Unit Test 3: whoseTurn Function: PASSED\n");
	else
		printf("Unit Test 3: whoseTurn Function: FAILED\n");

}