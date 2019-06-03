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
int correctNumTreasureCards = 0;

void checkAdventurerCard(int p, struct gameState *post) {
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  //variables taken from cardeffect, adventureCase function
  int bonus = 0;
  int drawntreasure = 0;
  int temphand[MAX_HAND];
  int cardDrawn;
  int z = 0;


    
  cardEffect(adventurer, 0, 0, 0, post, 0, &bonus);

  //Expected treasure card count is 2
  while(drawntreasure<2){
    if (pre.deckCount[p] <1){//if the deck is empty we need to shuffle discard and add to deck
      shuffle(p, &pre);
    }
    drawCard(p, &pre);
    cardDrawn = pre.hand[p][pre.handCount[p]-1];//top card of hand is most recently drawn card.
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      drawntreasure++;
    else{ 
      temphand[z]=cardDrawn;
      pre.handCount[p]--;//this should just remove the top card (the most recently drawn one).
      z++;
    }
  } 
  while(z-1>=0){
    pre.discard[p][pre.discardCount[p]++]=temphand[z-1]; // discard all cards in play that have been drawn
    z=z-1;
  }

  //tally treasure cards for both game states
  int i = 0;
  int j = 0;
  int treasureCountPre = 0;
  int treasureCountPost = 0;

  for (i = 0; i < post->handCount[p]; i++){
    if (post->hand[p][i] == copper || post->hand[p][i] == silver || post->hand[p][i] == gold)
      treasureCountPost++;
  }

  for (j = 0; j < pre.handCount[p]; j++){
    if (pre.hand[p][j] == copper || pre.hand[p][j] == silver || pre.hand[p][j] == gold)
      treasureCountPre++;
  }
 
  //Pre and Post gamestates should have same treasure counts
  if (treasureCountPost == treasureCountPre){
    printf("Correct Number of Treasure Cards Added:\n");
    printf("PASSED\n");
  }
  else{
    printf("Correct Number of Treasure Cards Added:\n");
    printf("FAILED\n");
    correctNumTreasureCards++;
  }


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

}

int main () {

  int idx;
  int num;
  int p;
 
  SelectStream(2);
  PutSeed(3);
  struct gameState G;

  printf ("Testing randomtestadventurer: adventurer\n");


  for (num = 0; num < 2; num++) {
    for (idx = 0; idx < sizeof(struct gameState); idx++) {
      ((char*)&G)[idx] = floor(Random() * 256);
    }
    p = floor(Random() * 2);
    G.whoseTurn = p;
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    G.playedCardCount = floor(Random() * MAX_DECK);
    //set treasure supply count
    //set number of Treasure cards
    G.supplyCount[copper] = 60 - (7 * p);
    G.supplyCount[silver] = 40;
    G.supplyCount[gold] = 30;
    //Add 3 treasures one of each kind to players deck
    G.deck[p][0] = gold;
    G.deck[p][1] = copper;
    G.deck[p][2] = silver;

    checkAdventurerCard(p, &G);
  }

  if (correctNumCardsAdded == 0 && correctNumDeckCount == 0 && correctNumCardsDiscarded == 0 && correctNumTreasureCards == 0)
    printf ("ALL %d TESTS OK\n", num);
  else{ 
    printf ("Correct Number of Cards Added, Number of Tests Failed: %d out of %d\n", correctNumCardsAdded, num);
    printf ("Correct Deck Count, Number of Tests Failed: %d out of %d\n", correctNumDeckCount, num);
    printf ("Correct Discard Count, Number of Tests Failed: %d out of %d\n", correctNumCardsDiscarded, num);
    printf ("Correct Number of Treasure Cards Added, Number of Tests Failed: %d out of %d\n", correctNumTreasureCards, num);
  }

  

  return 0;
}