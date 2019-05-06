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
	printf("\nUnit Test 4: getCost Function\n");
	printf("Testing with 2 players\n");

	//get cost of adventurer
	r = getCost(adventurer);
	printf("getCost of adventurer expected: 6, actual: %d\n", r);
	if (r == 6)
		printf("getCost test PASSED\n");
	else{
		printf("getCost test FAILED\n");
		passFlag = -1;
	}

	//get cost of card not in current Kingdom card set
	r = getCost(outpost);
	printf("getCost of outpost expected: 5, actual: %d\n", r);
	if (r == 5)
		printf("getCost test PASSED\n");
	else{
		printf("getCost test FAILED\n");
		passFlag = -1;
	}

	//report if testcase passed or failed
	if (passFlag == 0)
		printf("Unit Test 4: getCost Function: PASSED\n");
	else
		printf("Unit Test 4: getCost Function: FAILED\n");
}