#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


int main(){
	int r;
	int passFlag = 0;
	int seed = 1000;
	int numPlayer = 2;
	int thisPlayer = 0;
	int playerTwo = 1;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				remodel, smithy, village, baron, great_hall};
	struct gameState G;
	struct gameState testG;


	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;

	//initialize game
	initializeGame(numPlayer, k, seed, &G);
	//copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	printf("\nCard Test 2: adventurer\n");
	printf("Testing with 2 players\n");

	//Expect to receive 2 treasure cards, run cardEffect
	int expectedTresureCards = 2;

	cardEffect(adventurer, choice1, choice2, choice3, &G, handpos, &bonus);

	printf("Correct Number of Cards Added\n:");
	printf("Expected hand count = %d\n", testG.handCount[thisPlayer] + expectedTresureCards);
	printf("Actual hand count = %d\n", G.handCount[thisPlayer]);
	if (G.handCount[thisPlayer] == testG.handCount[thisPlayer] + expectedTresureCards)
		printf("PASSED\n");
	else{
		printf("FAILED\n");
		passFlag = 1;
	}

	//tally treasure cards for both game states
	int i = 0;
	int j = 0;
	int treasureCount = 0;
	int treasureCountTestG = 0;

	for (i = 0; i < G.handCount[thisPlayer]; i++){
		if (G.hand[thisPlayer][i] == copper || G.hand[thisPlayer][i] == silver || G.hand[thisPlayer][i] == gold)
			treasureCount++;
	}

	for (j = 0; j < testG.handCount[thisPlayer]; j++){
		if (testG.hand[thisPlayer][j] == copper || testG.hand[thisPlayer][j] == silver || testG.hand[thisPlayer][j] == gold)
			treasureCountTestG++;
	}


	printf("Correct Number of Tresure Cards Added\n:");
	printf("Expected treasure count = %d\n", treasureCountTestG + 2);
	printf("Actual treasure count = %d\n", treasureCount);
	if (treasureCount == treasureCountTestG + 2)
		printf("PASSED\n");
	else{
		printf("FAILED\n");
		passFlag = 1;
	}




	//Check that players deck has decreased by 2 cards, it came from own pile
	printf("Correct Number of Cards Removed From Player Pile\n:");
	printf("Expected deck count = %d\n", testG.deckCount[thisPlayer] - expectedTresureCards);
	printf("Actual deck count = %d\n", G.deckCount[thisPlayer]);
	if (G.deckCount[thisPlayer] == testG.deckCount[thisPlayer] - expectedTresureCards)
		printf("PASSED\n");
	else{
		printf("FAILED\n");
		passFlag = 1;
	}



	//Check no change in other player's state hand count
	printf("Check State of Other Player, Hand Count\n:");
	printf("Expected hand count = %d\n", testG.handCount[playerTwo]);
	printf("Actual hand count = %d\n", G.handCount[playerTwo]);
	if (G.handCount[playerTwo] == testG.handCount[playerTwo])
		printf("PASSED\n");
	else{
		printf("FAILED\n");
		passFlag = 1;
	}


	//Check no change in other player's state deck count
	printf("Check State of Other Player, Deck Count\n:");
	printf("Expected deck count = %d\n", testG.deckCount[playerTwo]);
	printf("Actual deck count = %d\n", G.deckCount[playerTwo]);
	if (G.deckCount[playerTwo] == testG.deckCount[playerTwo])
		printf("PASSED\n");
	else{
		printf("FAILED\n");
		passFlag = 1;
	}


	printf("Card Test 2: adventurer result: ");
	if (passFlag == 0)
		printf("PASSED\n");
	else
		printf("FAILED\n");

	return 0;

}