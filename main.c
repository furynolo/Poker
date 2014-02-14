/* This is the programming assignment 8 main file */

#include "poker.h"

int main (void)
{
	const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"}; /* initialize suit array */
	const char *face[13] = {"Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"}; /* initialize face array */
	const char *hand[9] = {"a high card.", "a Pair.", "Two Pairs!", "a Three of a Kind!", "a Straight!", "a Flush!", "a Full House!", "a Four of a Kind!", "a Straight Flush!"}; /* list of possible hands */
	int deck[4][13] = {0}; /* initalize deck array */
	int p1_f[5] = {0}, p1_s[5] = {0}, p2_f[5] = {0}, p2_s[5] = {0}, extra_f[6] = {0}, extra_s[6] = {0};
	int p1_hand = 0, p2_hand = 0, get_cards = 0, exchange_1 = 0, exchange_2 = 0, exchange_3 = 0;

	srand ((unsigned) time (NULL)); /* random-number generator */

	shuffle (deck);
	deal (deck, face, suit, p1_f, p1_s, p2_f, p2_s, extra_f, extra_s);

	p1_hand = determine_hand (p1_f, p1_s);
	p2_hand = determine_hand (p2_f, p2_s);
	printf ("You have %s\n", hand[p1_hand]);
	
	printf ("Your Hand:\n0: %5s of %-8s\n", face[(p1_f[0])], suit[(p1_s[0])]);
	printf ("1: %5s of %-8s\n", face[(p1_f[1])], suit[(p1_s[1])]);
	printf ("2: %5s of %-8s\n", face[(p1_f[2])], suit[(p1_s[2])]);
	printf ("3: %5s of %-8s\n", face[(p1_f[3])], suit[(p1_s[3])]);
	printf ("4: %5s of %-8s\n", face[(p1_f[4])], suit[(p1_s[4])]);
	//printf ("e1: %d\t%d\ne2: %d\t%d\ne3: %d\t%d\ne4: %d\t%d\ne5: %d\t%d\ne6: %d%\t%d\n", extra_f[0], extra_s[0], extra_f[1], extra_s[1], extra_f[2], extra_s[2], extra_f[3], extra_s[3], extra_f[4], extra_s[4], extra_f[5], extra_s[5]);

	printf ("How many cards do you want to exchange (0, 1, 2, or 3)?");
	scanf ("%d", &get_cards);
	if (get_cards == 1)
	{
		printf ("Which card do you wish to exchange (0, 1, 2, 3, 4)?");
		scanf ("%d", &exchange_1);
		p1_f[exchange_1] = -1;
	}
	else if (get_cards == 2)
	{
		printf ("Which cards do you wish to exchange (0, 1, 2, 3, 4)?");
		scanf ("%d %d", &exchange_1, &exchange_2);
		p1_f[exchange_1] = -1;
		p1_f[exchange_2] = -1;
	}
	else if (get_cards == 3)
	{
		printf ("Which cards do you wish to exchange (0, 1, 2, 3, 4)?");
		scanf ("%d %d %d", &exchange_1, &exchange_2, &exchange_3);
		p1_f[exchange_1] = -1;
		p1_f[exchange_2] = -1;
		p1_f[exchange_3] = -1;
	}

	analyze_hand (p2_f, p2_s, p2_hand);
	deal_extra_cards (p1_f, p1_s, p2_f, p2_s, extra_f, extra_s);
	system ("pause");
	system ("cls");

	p1_hand = determine_hand (p1_f, p1_s);
	p2_hand = determine_hand (p2_f, p2_s);
	printf ("You have %s\n", hand[p1_hand]);
	
	printf ("Your New Hand:\n0: %5s of %-8s\n", face[(p1_f[0])], suit[(p1_s[0])]);
	printf ("1: %5s of %-8s\n", face[(p1_f[1])], suit[(p1_s[1])]);
	printf ("2: %5s of %-8s\n", face[(p1_f[2])], suit[(p1_s[2])]);
	printf ("3: %5s of %-8s\n", face[(p1_f[3])], suit[(p1_s[3])]);
	printf ("4: %5s of %-8s\n", face[(p1_f[4])], suit[(p1_s[4])]);

	if (p1_hand > p2_hand)
		printf ("You win with %s\n", hand[p1_hand]);
	else if (p1_hand < p2_hand)
		printf ("The dealer wins with %s\n", hand[p2_hand]);
	else
	{
		if (p1_hand == 8 || p1_hand == 5 || p1_hand == 4)
		{
			if (((p1_f[0] > p2_f[0]) && (p1_f[0] > p2_f[1]) && (p1_f[0] > p2_f[2]) && (p1_f[0] > p2_f[3]) && (p1_f[0] > p2_f[4])) ||
				((p1_f[1] > p2_f[0]) && (p1_f[1] > p2_f[1]) && (p1_f[1] > p2_f[2]) && (p1_f[1] > p2_f[3]) && (p1_f[1] > p2_f[4])) ||
				((p1_f[2] > p2_f[0]) && (p1_f[2] > p2_f[1]) && (p1_f[2] > p2_f[2]) && (p1_f[2] > p2_f[3]) && (p1_f[2] > p2_f[4])) ||
				((p1_f[3] > p2_f[0]) && (p1_f[3] > p2_f[1]) && (p1_f[3] > p2_f[2]) && (p1_f[3] > p2_f[3]) && (p1_f[3] > p2_f[4])) ||
				((p1_f[4] > p2_f[0]) && (p1_f[4] > p2_f[1]) && (p1_f[4] > p2_f[2]) && (p1_f[4] > p2_f[3]) && (p1_f[4] > p2_f[4])))
				printf ("Your win with %s\n", hand[p1_hand]);
			else if (((p1_f[0] < p2_f[0]) && (p1_f[0] < p2_f[1]) && (p1_f[0] < p2_f[2]) && (p1_f[0] < p2_f[3]) && (p1_f[0] < p2_f[4])) ||
				((p1_f[1] < p2_f[0]) && (p1_f[1] < p2_f[1]) && (p1_f[1] < p2_f[2]) && (p1_f[1] < p2_f[3]) && (p1_f[1] < p2_f[4])) ||
				((p1_f[2] < p2_f[0]) && (p1_f[2] < p2_f[1]) && (p1_f[2] < p2_f[2]) && (p1_f[2] < p2_f[3]) && (p1_f[2] < p2_f[4])) ||
				((p1_f[3] < p2_f[0]) && (p1_f[3] < p2_f[1]) && (p1_f[3] < p2_f[2]) && (p1_f[3] < p2_f[3]) && (p1_f[3] < p2_f[4])) ||
				((p1_f[4] < p2_f[0]) && (p1_f[4] < p2_f[1]) && (p1_f[4] < p2_f[2]) && (p1_f[4] < p2_f[3]) && (p1_f[4] < p2_f[4])))
				printf ("You lost to the dealer who had a higher %s\n", hand[p1_hand]);
			else
				printf ("You have tied the dealer, each with %s\n", hand[p1_hand]);
		}
		else if (p1_hand == 7 && p2_hand == 7)
		{
			if ((p1_f[0] == p1_f[1] || p1_f[0] == p1_f[2]) && (p2_f[0] == p2_f[1] || p2_f[0] == p2_f[2]) && p1_f[0] > p2_f[0])
				printf ("You win with a better Four of a Kind than the dealer!\n");
			else if ((p1_f[0] == p1_f[1] || p1_f[0] == p1_f[2]) && (p2_f[1] == p2_f[2] || p2_f[1] == p2_f[3]) && p1_f[0] > p2_f[0])
				printf ("You win with a better Four of a Kind than the dealer!\n");
			else if ((p1_f[1] == p1_f[2] || p1_f[1] == p1_f[3]) && (p2_f[1] == p2_f[2] || p2_f[1] == p2_f[3]) && p1_f[0] > p2_f[0])
				printf ("You win with a better Four of a Kind than the dealer!\n");
			else if ((p1_f[1] == p1_f[2] || p1_f[1] == p1_f[3]) && (p2_f[0] == p2_f[1] || p2_f[0] == p2_f[2]) && p1_f[0] > p2_f[0])
				printf ("You win with a better Four of a Kind than the dealer!\n");
			else if ((p1_f[0] == p1_f[1] || p1_f[0] == p1_f[2]) && (p2_f[0] == p2_f[1] || p2_f[0] == p2_f[2]) && p1_f[0] < p2_f[0])
				printf ("The dealer had a better Four of a Kind than you, sorry.\n");
			else if ((p1_f[0] == p1_f[1] || p1_f[0] == p1_f[2]) && (p2_f[1] == p2_f[2] || p2_f[1] == p2_f[3]) && p1_f[0] < p2_f[0])
				printf ("The dealer had a better Four of a Kind than you, sorry.\n");
			else if ((p1_f[1] == p1_f[2] || p1_f[1] == p1_f[3]) && (p2_f[1] == p2_f[2] || p2_f[1] == p2_f[3]) && p1_f[0] < p2_f[0])
				printf ("The dealer had a better Four of a Kind than you, sorry.\n");
			else if ((p1_f[1] == p1_f[2] || p1_f[1] == p1_f[3]) && (p2_f[0] == p2_f[1] || p2_f[0] == p2_f[2]) && p1_f[0] < p2_f[0])
				printf ("The dealer had a better Four of a Kind than you, sorry.\n");
			else
			{
				if ((p1_f[0] != p1_f[1] && p1_f[0] != p1_f[2] && p1_f[0] != p1_f[3] && p1_f[0] != p1_f[4]) && (p2_f[0] != p2_f[1] && p2_f[0] != p2_f[2] && p2_f[0] != p2_f[3] && p2_f[0] != p2_f[4]) && p1_f[0] > p2_f[0])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[1] != p1_f[0] && p1_f[1] != p1_f[2] && p1_f[1] != p1_f[3] && p1_f[1] != p1_f[4]) && (p2_f[0] != p2_f[1] && p2_f[0] != p2_f[2] && p2_f[0] != p2_f[3] && p2_f[0] != p2_f[4]) && p1_f[1] > p2_f[0])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[2] != p1_f[1] && p1_f[2] != p1_f[0] && p1_f[2] != p1_f[3] && p1_f[2] != p1_f[4]) && (p2_f[0] != p2_f[1] && p2_f[0] != p2_f[2] && p2_f[0] != p2_f[3] && p2_f[0] != p2_f[4]) && p1_f[2] > p2_f[0])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[3] != p1_f[1] && p1_f[3] != p1_f[2] && p1_f[3] != p1_f[0] && p1_f[3] != p1_f[4]) && (p2_f[0] != p2_f[1] && p2_f[0] != p2_f[2] && p2_f[0] != p2_f[3] && p2_f[0] != p2_f[4]) && p1_f[3] > p2_f[0])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[4] != p1_f[1] && p1_f[4] != p1_f[2] && p1_f[4] != p1_f[3] && p1_f[4] != p1_f[0]) && (p2_f[0] != p2_f[1] && p2_f[0] != p2_f[2] && p2_f[0] != p2_f[3] && p2_f[0] != p2_f[4]) && p1_f[4] > p2_f[0])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[0] != p1_f[1] && p1_f[0] != p1_f[2] && p1_f[0] != p1_f[3] && p1_f[0] != p1_f[4]) && (p2_f[1] != p2_f[0] && p2_f[1] != p2_f[2] && p2_f[1] != p2_f[3] && p2_f[1] != p2_f[4]) && p1_f[0] > p2_f[1])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[1] != p1_f[0] && p1_f[1] != p1_f[2] && p1_f[1] != p1_f[3] && p1_f[1] != p1_f[4]) && (p2_f[1] != p2_f[0] && p2_f[1] != p2_f[2] && p2_f[1] != p2_f[3] && p2_f[1] != p2_f[4]) && p1_f[1] > p2_f[1])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[2] != p1_f[1] && p1_f[2] != p1_f[0] && p1_f[2] != p1_f[3] && p1_f[2] != p1_f[4]) && (p2_f[1] != p2_f[0] && p2_f[1] != p2_f[2] && p2_f[1] != p2_f[3] && p2_f[1] != p2_f[4]) && p1_f[2] > p2_f[1])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[3] != p1_f[1] && p1_f[3] != p1_f[2] && p1_f[3] != p1_f[0] && p1_f[3] != p1_f[4]) && (p2_f[1] != p2_f[0] && p2_f[1] != p2_f[2] && p2_f[1] != p2_f[3] && p2_f[1] != p2_f[4]) && p1_f[3] > p2_f[1])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[4] != p1_f[1] && p1_f[4] != p1_f[2] && p1_f[4] != p1_f[3] && p1_f[4] != p1_f[0]) && (p2_f[1] != p2_f[0] && p2_f[1] != p2_f[2] && p2_f[1] != p2_f[3] && p2_f[1] != p2_f[4]) && p1_f[4] > p2_f[1])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[0] != p1_f[1] && p1_f[0] != p1_f[2] && p1_f[0] != p1_f[3] && p1_f[0] != p1_f[4]) && (p2_f[2] != p2_f[1] && p2_f[2] != p2_f[0] && p2_f[2] != p2_f[3] && p2_f[2] != p2_f[4]) && p1_f[0] > p2_f[2])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[1] != p1_f[0] && p1_f[1] != p1_f[2] && p1_f[1] != p1_f[3] && p1_f[1] != p1_f[4]) && (p2_f[2] != p2_f[1] && p2_f[2] != p2_f[0] && p2_f[2] != p2_f[3] && p2_f[2] != p2_f[4]) && p1_f[1] > p2_f[2])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[2] != p1_f[1] && p1_f[2] != p1_f[0] && p1_f[2] != p1_f[3] && p1_f[2] != p1_f[4]) && (p2_f[2] != p2_f[1] && p2_f[2] != p2_f[0] && p2_f[2] != p2_f[3] && p2_f[2] != p2_f[4]) && p1_f[2] > p2_f[2])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[3] != p1_f[1] && p1_f[3] != p1_f[2] && p1_f[3] != p1_f[0] && p1_f[3] != p1_f[4]) && (p2_f[2] != p2_f[1] && p2_f[2] != p2_f[0] && p2_f[2] != p2_f[3] && p2_f[2] != p2_f[4]) && p1_f[3] > p2_f[2])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[4] != p1_f[1] && p1_f[4] != p1_f[2] && p1_f[4] != p1_f[3] && p1_f[4] != p1_f[0]) && (p2_f[2] != p2_f[1] && p2_f[2] != p2_f[0] && p2_f[2] != p2_f[3] && p2_f[2] != p2_f[4]) && p1_f[4] > p2_f[2])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[0] != p1_f[1] && p1_f[0] != p1_f[2] && p1_f[0] != p1_f[3] && p1_f[0] != p1_f[4]) && (p2_f[3] != p2_f[1] && p2_f[3] != p2_f[2] && p2_f[3] != p2_f[0] && p2_f[3] != p2_f[4]) && p1_f[0] > p2_f[3])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[1] != p1_f[0] && p1_f[1] != p1_f[2] && p1_f[1] != p1_f[3] && p1_f[1] != p1_f[4]) && (p2_f[3] != p2_f[1] && p2_f[3] != p2_f[2] && p2_f[3] != p2_f[0] && p2_f[3] != p2_f[4]) && p1_f[1] > p2_f[3])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[2] != p1_f[1] && p1_f[2] != p1_f[0] && p1_f[2] != p1_f[3] && p1_f[2] != p1_f[4]) && (p2_f[3] != p2_f[1] && p2_f[3] != p2_f[2] && p2_f[3] != p2_f[0] && p2_f[3] != p2_f[4]) && p1_f[2] > p2_f[3])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[3] != p1_f[1] && p1_f[3] != p1_f[2] && p1_f[3] != p1_f[0] && p1_f[3] != p1_f[4]) && (p2_f[3] != p2_f[1] && p2_f[3] != p2_f[2] && p2_f[3] != p2_f[0] && p2_f[3] != p2_f[4]) && p1_f[3] > p2_f[3])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[4] != p1_f[1] && p1_f[4] != p1_f[2] && p1_f[4] != p1_f[3] && p1_f[4] != p1_f[0]) && (p2_f[3] != p2_f[1] && p2_f[3] != p2_f[2] && p2_f[3] != p2_f[0] && p2_f[3] != p2_f[4]) && p1_f[4] > p2_f[3])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[0] != p1_f[1] && p1_f[0] != p1_f[2] && p1_f[0] != p1_f[3] && p1_f[0] != p1_f[4]) && (p2_f[4] != p2_f[1] && p2_f[4] != p2_f[2] && p2_f[4] != p2_f[3] && p2_f[4] != p2_f[0]) && p1_f[0] > p2_f[4])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[1] != p1_f[0] && p1_f[1] != p1_f[2] && p1_f[1] != p1_f[3] && p1_f[1] != p1_f[4]) && (p2_f[4] != p2_f[1] && p2_f[4] != p2_f[2] && p2_f[4] != p2_f[3] && p2_f[4] != p2_f[0]) && p1_f[1] > p2_f[4])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[2] != p1_f[1] && p1_f[2] != p1_f[0] && p1_f[2] != p1_f[3] && p1_f[2] != p1_f[4]) && (p2_f[4] != p2_f[1] && p2_f[4] != p2_f[2] && p2_f[4] != p2_f[3] && p2_f[4] != p2_f[0]) && p1_f[2] > p2_f[4])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[3] != p1_f[1] && p1_f[3] != p1_f[2] && p1_f[3] != p1_f[0] && p1_f[3] != p1_f[4]) && (p2_f[4] != p2_f[1] && p2_f[4] != p2_f[2] && p2_f[4] != p2_f[3] && p2_f[4] != p2_f[0]) && p1_f[3] > p2_f[4])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else if ((p1_f[4] != p1_f[1] && p1_f[4] != p1_f[2] && p1_f[4] != p1_f[3] && p1_f[4] != p1_f[0]) && (p2_f[4] != p2_f[1] && p2_f[4] != p2_f[2] && p2_f[4] != p2_f[3] && p2_f[4] != p2_f[0]) && p1_f[4] > p2_f[4])
					printf ("You win with a better high card with your Four of a Kind than the dealer!\n");
				else
					printf ("The dealer wins with a better high card with their Four of a Kind than you, sorry.\n");
			}
		}
		else if (p1_hand == 6 && p2_hand == 6)
			printf ("You tied the dealers Full House!\n");
		else if (p1_hand == 3 && p2_hand == 3)
			printf ("You tied the dealers three of a kind!\n");
		else if (p1_hand == 2 && p2_hand == 2)
			printf ("You tied the deaelrs two pair hand!\n");
		else if (p1_hand == 1 && p2_hand == 1)
			printf ("You tied the dealers pair!\n");
		else
		{
			if (((p1_f[0] > p2_f[0]) && (p1_f[0] > p2_f[1]) && (p1_f[0] > p2_f[2]) && (p1_f[0] > p2_f[3]) && (p1_f[0] > p2_f[4])) ||
				((p1_f[1] > p2_f[0]) && (p1_f[1] > p2_f[1]) && (p1_f[1] > p2_f[2]) && (p1_f[1] > p2_f[3]) && (p1_f[1] > p2_f[4])) ||
				((p1_f[2] > p2_f[0]) && (p1_f[2] > p2_f[1]) && (p1_f[2] > p2_f[2]) && (p1_f[2] > p2_f[3]) && (p1_f[2] > p2_f[4])) ||
				((p1_f[3] > p2_f[0]) && (p1_f[3] > p2_f[1]) && (p1_f[3] > p2_f[2]) && (p1_f[3] > p2_f[3]) && (p1_f[3] > p2_f[4])) ||
				((p1_f[4] > p2_f[0]) && (p1_f[4] > p2_f[1]) && (p1_f[4] > p2_f[2]) && (p1_f[4] > p2_f[3]) && (p1_f[4] > p2_f[4])))
				printf ("Your win with a better High Card than the dealer!\n", hand[p1_hand]);
			else if (((p1_f[0] < p2_f[0]) && (p1_f[0] < p2_f[1]) && (p1_f[0] < p2_f[2]) && (p1_f[0] < p2_f[3]) && (p1_f[0] < p2_f[4])) ||
				((p1_f[1] < p2_f[0]) && (p1_f[1] < p2_f[1]) && (p1_f[1] < p2_f[2]) && (p1_f[1] < p2_f[3]) && (p1_f[1] < p2_f[4])) ||
				((p1_f[2] < p2_f[0]) && (p1_f[2] < p2_f[1]) && (p1_f[2] < p2_f[2]) && (p1_f[2] < p2_f[3]) && (p1_f[2] < p2_f[4])) ||
				((p1_f[3] < p2_f[0]) && (p1_f[3] < p2_f[1]) && (p1_f[3] < p2_f[2]) && (p1_f[3] < p2_f[3]) && (p1_f[3] < p2_f[4])) ||
				((p1_f[4] < p2_f[0]) && (p1_f[4] < p2_f[1]) && (p1_f[4] < p2_f[2]) && (p1_f[4] < p2_f[3]) && (p1_f[4] < p2_f[4])))
				printf ("The dealer had a better High Card than you, sorry.\n");
			else
				printf ("You tied the dealer with the same High Card.\n");
		}
	}

	return 0;
}