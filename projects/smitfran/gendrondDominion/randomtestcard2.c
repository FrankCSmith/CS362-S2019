#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Some code segments borrowed from testDrawCard.c
//Global variables to keep track of random test result for each function tested
int correctNumCardsAdded = 0;
int correctNumDeckCount = 0;
int correctNumCardsDiscarded = 0;
int correctNumActions = 0;

void checkVillageCard(int p, struct gameState *post) {
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  int bonus = 0;

    
  cardEffect(village, 0, 0, 0, post, 0, &bonus);

  //Check that 1 cards are drawn and 2 actions added compare pre and post
  int i = 0;
  for (i = 0; i < 1; i++)
    drawCard(p, &pre);

  pre.numActions = pre.numActions + 2;

  //Remove one card for gameState pre
  discardCard(0, p, &pre, 0);

  //Pre and Post gamestates should have same hand, deck, and discard counts
  if (pre.handCount[p] == post->handCount[p]){
    printf("Correct Number of Cards Added:\n");
    printf("PASSED\n");
  }
  else{
    printf("Correct Number of Cards Added:\n");
    printf("FAILED\n");
    correctNumCardsAdded++;
  }

  if (pre.deckCount[p] == post->deckCount[p]){
    printf("Correct Number of Cards Removed From Player Pile:\n");
    printf("PASSED\n");
  }
  else{
    printf("Correct Number of Cards Removed From Player Pile:\n");
    printf("FAILED\n");
    correctNumDeckCount++;
  }

  if (pre.discardCount[p] == post->discardCount[p]){
    printf("Correct Number of Cards Discarded:\n");
    printf("PASSED\n");
  }
  else{
    printf("Correct Number of Cards Discarded:\n");
    printf("FAILED\n");
    correctNumCardsDiscarded++;
  }

  if (pre.numActions == post->numActions){
    printf("Correct Number of Actions Added:\n");
    printf("PASSED\n");
  }
  else{
    printf("Correct Number of Actions Added:\n");
    printf("FAILED\n");
    correctNumActions++;
  }

}

int main () {

  int idx;
  int num;
  int p;
 
  SelectStream(2);
  PutSeed(3);
  struct gameState G;

  printf ("Testing randomtestcard2: village\n");


  for (num = 0; num < 2000; num++) {
    for (idx = 0; idx < sizeof(struct gameState); idx++) {
      ((char*)&G)[idx] = floor(Random() * 256);
    }
    p = floor(Random() * 2);
    G.whoseTurn = p;
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    G.playedCardCount = floor(Random() * MAX_DECK);
    checkVillageCard(p, &G);
  }

  if (correctNumCardsAdded == 0 && correctNumDeckCount == 0 && correctNumCardsDiscarded == 0 && correctNumActions == 0)
    printf ("ALL %d TESTS OK\n", num);
  else{ 
    printf ("Correct Number of Cards Added, Number of Tests Failed: %d out of %d\n", correctNumCardsAdded, num);
    printf ("Correct Deck Count, Number of Tests Failed: %d out of %d\n", correctNumDeckCount, num);
    printf ("Correct Discard Count, Number of Tests Failed: %d out of %d\n", correctNumCardsDiscarded, num);
    printf ("Correct Number of Actions Added, Number of Tests Failed: %d out of %d\n", correctNumActions, num);
  }

  

  return 0;
}