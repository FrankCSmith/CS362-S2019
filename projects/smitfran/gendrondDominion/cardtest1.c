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

	printf("\nCard Test 1: smithy\n");
	printf("Testing with 2 players\n");

	//Expect to receive 3 cards, run cardEffect
	int addedCards = 3;

	cardEffect(smithy, choice1, choice2, choice3, &G, handpos, &bonus);

	printf("Correct Number of Cards Added\n:");
	printf("Expected hand count = %d\n", testG.handCount[thisPlayer] + addedCards);
	printf("Actual hand count = %d\n", G.handCount[thisPlayer]);
	if (G.handCount[thisPlayer] == testG.handCount[thisPlayer] + addedCards)
		printf("PASSED\n");
	else{
		printf("FAILED\n");
		passFlag = 1;
	}

	//Check that players deck has decreased by 3 cards, it came from own pile
	printf("Correct Number of Cards Removed From Player Pile\n:");
	printf("Expected deck count = %d\n", testG.deckCount[thisPlayer] - addedCards);
	printf("Actual deck count = %d\n", G.deckCount[thisPlayer]);
	if (G.deckCount[thisPlayer] == testG.deckCount[thisPlayer] - addedCards)
		printf("PASSED\n");
	else{
		printf("FAILED\n");
		passFlag = 1;
	}

	//Check that one card was discarded
	printf("Card Discarded After Use:\n");
	printf("Expected discard count = %d\n", 1);
	printf("Actual discard count = %d\n", G.discardCount[thisPlayer]);
	if (G.discardCount[thisPlayer] == 1)
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


	printf("Card Test 1: smithy result: ");
	if (passFlag == 0)
		printf("PASSED\n");
	else
		printf("FAILED\n");

	return 0;

}