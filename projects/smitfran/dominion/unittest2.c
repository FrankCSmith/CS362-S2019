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
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};
	struct gameState G;
	//initialize game
	initializeGame(numPlayer, k, seed, &G);
	printf("\nUnit Test 2: isGameOver Function\n");
	printf("Testing with 2 players\n");

	//just started game, expect that it's not already over
	r = isGameOver(&G);
	printf("isGameOver just started game expected: 0, actual: %d\n", r);
	if (r == 0)
		printf("isGameOver test PASSED\n");
	else{
		printf("isGameOver test FAILED\n");
		passFlag = -1;
	}

	//set province supply count to 0, this means the game should be over
	G.supplyCount[province] = 0;
	r = isGameOver(&G);
	printf("isGameOver province supply count = 0 expected: 1, actual: %d\n", r);
	if (r == 1)
		printf("isGameOver test PASSED\n");
	else{
		printf("isGameOver test FAILED\n");
		passFlag = -1;
	}

	//reset province supply count to 1, this means the game is back on
	G.supplyCount[province] = 1;
	r = isGameOver(&G);
	printf("isGameOver province supply count = 1 expected: 0, actual: %d\n", r);
	if (r == 0)
		printf("isGameOver test PASSED\n");
	else{
		printf("isGameOver test FAILED\n");
		passFlag = -1;
	}

	//test if 3 supply count piles are at 0, not province
	G.supplyCount[adventurer] = 0;
	G.supplyCount[council_room] = 0;
	G.supplyCount[feast] = 0;
	r = isGameOver(&G);
	printf("isGameOver 3 supply count piles are at 0 expected: 1, actual: %d\n", r);
	if (r == 1)
		printf("isGameOver test PASSED\n");
	else{
		printf("isGameOver test FAILED\n");
		passFlag = -1;
	}

	//report if test case passed or failed
	if (passFlag == 0)
		printf("Unit Test 2: isGameOver Function: PASSED\n");
	else
		printf("Unit Test 2: isGameOver Function: FAILED\n");

}