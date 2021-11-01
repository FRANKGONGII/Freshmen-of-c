//get a number and deal a random hand of card of that number
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define NUM_SUIT 4
#define NUM_RANKS 13
#define _CRT_SECURE_NO_WARNINGS 1
int main()
{
	bool in_hand[NUM_SUIT][NUM_RANKS] = { false };
	//initialize the in_hand array to 0, when we get a card, make its value 1
	int num_cards, rank, suit;
	const char rank_code[] = { '2','3','4','5','6','7','8','9','t','q','k','a','j' };
	const char suit_code[] = { 'c','d','h','s' };
	//initialize the const array of rank and suit
	srand((unsigned)time(NULL));
	//get a random number

	printf("Enter number of card in hand: ");
	scanf("%d", &num_cards);
	//get the number of cards we want

	printf("your hand:");
	while (num_cards>0)
	{
		suit = rand() % NUM_SUIT;
		rank = rand() % NUM_RANKS;
		//get the random card, use module to narrow its range
		if (!in_hand[suit][rank])
		{
			in_hand[suit][rank] = true;
			num_cards--;
			printf(" %c%c", rank_code[rank], suit_code[suit]);
		}
	}
	printf("\n");
	return 0;
}