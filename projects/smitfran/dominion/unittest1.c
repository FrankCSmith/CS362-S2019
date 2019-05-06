
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
	printf("\nUnit Test 1: supplyCount Function\n");
	printf("Testing with 2 players\n");

	//Check supplyCount for Kingdom Cards: adventurer and numPlayer set to 2, should return 10
	r = supplyCount(adventurer, &G);
	printf("adventurer supplyCount expected: 10, actual: %d\n", r);
	if (r == 10)
		printf("supplyCount test PASSED\n");
	else{
		printf("supplyCount test FAILED\n");
		passFlag = -1;
	}

	//Check supplyCount for Kingdom Cards: great_hall and numPlayer set to 2, should return 8
	r = supplyCount(great_hall, &G);
	printf("great_hall supplyCount expected: 8, actual: %d\n", r);
	if (r == 8)
		printf("supplyCount test PASSED\n");
	else{
		printf("supplyCount test FAILED\n");
		passFlag = -1;
	}

	//Check supplyCount for Kingdom Cards: feast (not in current set being played) and numPlayer set to 2, should return -1
	r = supplyCount(outpost, &G);
	printf("feast supplyCount expected: -1, actual: %d\n", r);
	if (r == -1)
		printf("supplyCount test PASSED\n");
	else{
		printf("supplyCount test FAILED\n");
		passFlag = -1;
	}

	//Test with numPlayer set to 4
	numPlayer = 4;
	struct gameState G2;
	//initialize game
	initializeGame(numPlayer, k, seed, &G2);
	printf("Testing with 4 players\n");

	//Check supplyCount for Kingdom Cards: adventurer and numPlayer set to 4, should still return 10
	r = supplyCount(adventurer, &G2);
	printf("adventurer supplyCount expected: 10, actual: %d\n", r);
	if (r == 10)
		printf("supplyCount test PASSED\n");
	else{
		printf("supplyCount test FAILED\n");
		passFlag = -1;
	}

	//Check supplyCount for Kingdom Cards: great_hall and numPlayer set to 4, should return 12
	r = supplyCount(great_hall, &G2);
	printf("great_hall supplyCount expected: 12, actual: %d\n", r);
	if (r == 12)
		printf("supplyCount test PASSED\n");
	else{
		printf("supplyCount test FAILED\n");
		passFlag = -1;
	}

	//Check supplyCount for Kingdom Cards: feast (not in current set being played) and numPlayer set to 4, should return -1
	r = supplyCount(outpost, &G2);
	printf("feast supplyCount expected: -1, actual: %d\n", r);
	if (r == -1)
		printf("supplyCount test PASSED\n");
	else{
		printf("supplyCount test FAILED\n");
		passFlag = -1;
	}

	//Report if test case has passed all steps or not
	if (passFlag == 0)
		printf("Unit Test 1: supplyCount Function: PASSED\n");
	else
		printf("Unit Test 1: supplyCount Function: FAILED\n");

}