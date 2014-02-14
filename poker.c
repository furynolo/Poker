/* This is the programming assignment 8 function file */

#include "pa8.h"

void shuffle (int wDeck[][13]) /* shuffle cards in deck */
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	for (card = 1; card <= 16; card++) /* for each of the cards, choose slot of deck randomly */
	{
		do /* choose new random location until unoccupied slot found */
		{
			row = rand () % 4;
			column = rand () % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

void deal (const int wDeck[][13], const char *wFace[], const char *wSuit[], int p1_f[], int p1_s[], int p2_f[], int p2_s[], int extra_f[], int extra_s[]) /* deal cards in deck */
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
 
	for (card = 1; card <= 52; card++) /* deal each of the 52 cards */
	{
		for (row = 0; row <= 3; row++) /* loop through rows of wDeck */
		{
			for (column = 0; column <= 12; column++) /* loop through columns of wDeck for current row */
			{
				if (wDeck[row][column] == card) /* if slot contains current card, display card */
				{
					//printf ("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
					if (card < 11)
					{
						if (card % 2 == 1)
						{
							p1_f[card / 2] = column;
							p1_s[card / 2] = row;
						}
						else if (card % 2 == 0)
						{
							p2_f[(card - 1) / 2] = column;
							p2_s[(card - 1) / 2] = row;
						}
					}
					else
					{
						extra_f[card - 11] = column;
						extra_s[card - 11] = row;
					}
				}
			}
		}
	}
}

int is_it_a_pair (int f[])
{
	if (f[0] == f[1] || f[0] == f[2] || f[0] == f[3] || f[0] == f[4] || f[1] == f[2] || f[1] == f[3] || f[1] == f[4] || f[2] == f[3] || f[2] == f[4] || f[3] == f[4])
		return 1;
	else
		return 0;
}

int is_it_two_pair (int f[])
{
	if (((f[0] == f[1]) && (f[2] == f[3])) || ((f[0] == f[2]) && (f[3] == f[1])) || ((f[0] == f[3]) && (f[2] == f[1])) || ((f[0] == f[1]) && (f[2] == f[4])) || ((f[0] == f[2]) && (f[4] == f[1])) || ((f[0] == f[4]) && (f[2] == f[1])) || ((f[0] == f[1]) && (f[4] == f[3])) || ((f[0] == f[3]) && (f[1] == f[4])) || ((f[0] == f[4]) && (f[1] == f[3])) || ((f[0] == f[2]) && (f[4] == f[3])) || ((f[0] == f[3]) && (f[2] == f[4])) || ((f[0] == f[4]) && (f[2] == f[3])) || ((f[2] == f[1]) && (f[4] == f[3])) || ((f[3] == f[1]) && (f[2] == f[4])) || ((f[4] == f[1]) && (f[2] == f[3])))
		return 1;
	else
		return 0;
}

int is_it_a_three_kind (int f[])
{
	if (((f[0] == f[1]) && (f[0] == f[2])) || ((f[0] == f[1]) && (f[0] == f[3])) || ((f[0] == f[1]) && (f[0] == f[4])) || ((f[0] == f[2]) && (f[0] == f[3])) || ((f[0] == f[2]) && (f[0] == f[4])) || ((f[0] == f[3]) && (f[0] == f[4])) || ((f[1] == f[2]) && (f[1] == f[3])) || ((f[1] == f[2]) && (f[1] == f[4])) || ((f[1] == f[3]) && (f[1] == f[4])) || ((f[2] == f[3]) && (f[2] == f[4])))
		return 1;
	else
		return 0;
}

int is_it_a_four_kind (int f[])
{
	if (((f[0] == f[1]) && (f[0] == f[2]) && (f[0] == f[3])) || ((f[0] == f[1]) && (f[0] == f[2]) && (f[0] == f[4])) || ((f[0] == f[4]) && (f[0] == f[2]) && (f[0] == f[3])) || ((f[0] == f[1]) && (f[0] == f[4]) && (f[0] == f[3])) || ((f[1] == f[2]) && (f[1] == f[3]) && (f[1] == f[4])))
		return 1;
	else
		return 0;
}

int is_it_a_flush (int s[])
{
	if (s[0] == s[1] && s[0] == s[2] && s[0] == s[3] && s[0] == s[4])
		return 1;
	else
		return 0;
}

int is_it_a_straight (int f[])
{
	int result = 0;
	
	if (((f[0] == 0 || f[1] == 0 || f[2] == 0 || f[3] == 0 || f[4] == 0) &&	(f[0] == 1 || f[1] == 1 || f[2] == 1 || f[3] == 1 || f[4] == 1) && (f[0] == 2 || f[1] == 2 || f[2] == 2 || f[3] == 2 || f[4] == 2) && (f[0] == 3 || f[1] == 3 || f[2] == 3 || f[3] == 3 || f[4] == 3) && (f[0] == 4 || f[1] == 4 || f[2] == 4 || f[3] == 4 || f[4] == 4)) ||
		((f[0] == 1 || f[1] == 1 || f[2] == 1 || f[3] == 1 || f[4] == 1) &&	(f[0] == 2 || f[1] == 2 || f[2] == 2 || f[3] == 2 || f[4] == 2) && (f[0] == 3 || f[1] == 3 || f[2] == 3 || f[3] == 3 || f[4] == 3) && (f[0] == 4 || f[1] == 4 || f[2] == 4 || f[3] == 4 || f[4] == 4) && (f[0] == 5 || f[1] == 5 || f[2] == 5 || f[3] == 5 || f[4] == 5)) ||
		((f[0] == 2 || f[1] == 2 || f[2] == 2 || f[3] == 2 || f[4] == 2) && (f[0] == 3 || f[1] == 3 || f[2] == 3 || f[3] == 3 || f[4] == 3) && (f[0] == 4 || f[1] == 4 || f[2] == 4 || f[3] == 4 || f[4] == 4) && (f[0] == 5 || f[1] == 5 || f[2] == 5 || f[3] == 5 || f[4] == 5) && (f[0] == 6 || f[1] == 6 || f[2] == 6 || f[3] == 6 || f[4] == 6)) ||
		((f[0] == 3 || f[1] == 3 || f[2] == 3 || f[3] == 3 || f[4] == 3) && (f[0] == 4 || f[1] == 4 || f[2] == 4 || f[3] == 4 || f[4] == 4) && (f[0] == 5 || f[1] == 5 || f[2] == 5 || f[3] == 5 || f[4] == 5) && (f[0] == 6 || f[1] == 6 || f[2] == 6 || f[3] == 6 || f[4] == 6) && (f[0] == 7 || f[1] == 7 || f[2] == 7 || f[3] == 7 || f[4] == 7)) ||
		((f[0] == 4 || f[1] == 4 || f[2] == 4 || f[3] == 4 || f[4] == 4) && (f[0] == 5 || f[1] == 5 || f[2] == 5 || f[3] == 5 || f[4] == 5) && (f[0] == 6 || f[1] == 6 || f[2] == 6 || f[3] == 6 || f[4] == 6) && (f[0] == 7 || f[1] == 7 || f[2] == 7 || f[3] == 7 || f[4] == 7) && (f[0] == 8 || f[1] == 8 || f[2] == 8 || f[3] == 8 || f[4] == 8)) ||
		((f[0] == 5 || f[1] == 5 || f[2] == 5 || f[3] == 5 || f[4] == 5) && (f[0] == 6 || f[1] == 6 || f[2] == 6 || f[3] == 6 || f[4] == 6) && (f[0] == 7 || f[1] == 7 || f[2] == 7 || f[3] == 7 || f[4] == 7) && (f[0] == 8 || f[1] == 8 || f[2] == 8 || f[3] == 8 || f[4] == 8) && (f[0] == 9 || f[1] == 9 || f[2] == 9 || f[3] == 9 || f[4] == 9)) ||
		((f[0] == 6 || f[1] == 6 || f[2] == 6 || f[3] == 6 || f[4] == 6) && (f[0] == 7 || f[1] == 7 || f[2] == 7 || f[3] == 7 || f[4] == 7) && (f[0] == 8 || f[1] == 8 || f[2] == 8 || f[3] == 8 || f[4] == 8) && (f[0] == 9 || f[1] == 9 || f[2] == 9 || f[3] == 9 || f[4] == 9) && (f[0] == 10 || f[1] == 10 || f[2] == 10 || f[3] == 10 || f[4] == 10)) ||
		((f[0] == 7 || f[1] == 7 || f[2] == 7 || f[3] == 7 || f[4] == 7) && (f[0] == 8 || f[1] == 8 || f[2] == 8 || f[3] == 8 || f[4] == 8) && (f[0] == 9 || f[1] == 9 || f[2] == 9 || f[3] == 9 || f[4] == 9) && (f[0] == 10 || f[1] == 10 || f[2] == 10 || f[3] == 10 || f[4] == 10) && (f[0] == 11 || f[1] == 11 || f[2] == 11 || f[3] == 11 || f[4] == 11)) ||
		((f[0] == 8 || f[1] == 8 || f[2] == 8 || f[3] == 8 || f[4] == 8) && (f[0] == 9 || f[1] == 9 || f[2] == 9 || f[3] == 9 || f[4] == 9) && (f[0] == 10 || f[1] == 10 || f[2] == 10 || f[3] == 10 || f[4] == 10) && (f[0] == 11 || f[1] == 11 || f[2] == 11 || f[3] == 11 || f[4] == 11) && (f[0] == 12 || f[1] == 12 || f[2] == 12 || f[3] == 12 || f[4] == 12)))
		result = 1;
	return result;
}

int determine_hand (int f[], int s[])
{
	int result = 0;

	if (is_it_a_flush (s) == 1 && is_it_a_straight (f) == 1)
		result = 8;
	else if (is_it_a_four_kind (f) == 1)
		result = 7;
	else if (is_it_two_pair (f) == 1 && is_it_a_three_kind (f) == 1)
		result = 6;
	else if (is_it_a_flush (s) == 1)
		result = 5;
	else if (is_it_a_straight (f) == 1)
		result = 4;
	else if (is_it_a_three_kind (f) == 1)
		result = 3;
	else if (is_it_two_pair (f) == 1)
		result = 2;
	else if (is_it_a_pair (f) == 1)
		result = 1;
	else
		result = 0;

	return result;
}

void analyze_hand (int f[], int s[], int hand)
{
	if (hand >= 4)
		printf("");
		
	else if (hand == 3)
	{
		if (f[0] != f[1] && f[0] != f[2] && f[0] != f[3] && f[0] != f[4])
			f[0] = -1;
		if (f[1] != f[0] && f[1] != f[2] && f[1] != f[3] && f[1] != f[4])
			f[1] = -1;
		if (f[2] != f[1] && f[2] != f[0] && f[2] != f[3] && f[2] != f[4])
			f[2] = -1;
		if (f[3] != f[1] && f[3] != f[2] && f[3] != f[0] && f[3] != f[4])
			f[3] = -1;
		if (f[4] != f[1] && f[4] != f[2] && f[4] != f[3] && f[4] != f[0])
			f[4] = -1;
	}
	else if (hand == 2)
	{
		if (f[0] != f[1] && f[0] != f[2] && f[0] != f[3] && f[0] != f[4])
			f[0] = -1;
		if (f[1] != f[0] && f[1] != f[2] && f[1] != f[3] && f[1] != f[4])
			f[1] = -1;
		if (f[2] != f[1] && f[2] != f[0] && f[2] != f[3] && f[2] != f[4])
			f[2] = -1;
		if (f[3] != f[1] && f[3] != f[2] && f[3] != f[0] && f[3] != f[4])
			f[3] = -1;
		if (f[4] != f[1] && f[4] != f[2] && f[4] != f[3] && f[4] != f[0])
			f[4] = -1;
	}

	else if (hand == 1)
	{
		if (f[0] != f[1] && f[0] != f[2] && f[0] != f[3] && f[0] != f[4])
			f[0] = -1;
		if (f[1] != f[0] && f[1] != f[2] && f[1] != f[3] && f[1] != f[4])
			f[1] = -1;
		if (f[2] != f[1] && f[2] != f[0] && f[2] != f[3] && f[2] != f[4])
			f[2] = -1;
		if (f[3] != f[1] && f[3] != f[2] && f[3] != f[0] && f[3] != f[4])
			f[3] = -1;
		if (f[4] != f[1] && f[4] != f[2] && f[4] != f[3] && f[4] != f[0])
			f[4] = -1;
	}

	else if (hand == 0)
	{
		if (f[0] > f[1] && f[0] > f[2] && f[0] > f[3] && f[0] > f[4])
		{
			//f[1] = -1;
			f[2] = -1;
			f[3] = -1;
			f[4] = -1;
		}

		else if (f[1] > f[0] && f[1] > f[2] && f[1] > f[3] && f[1] > f[4])
		{
			f[0] = -1;
			//f[2] = -1;
			f[3] = -1;
			f[4] = -1;
		}

		else if (f[2] > f[1] && f[2] > f[0] && f[2] > f[3] && f[2] > f[4])
		{
			f[1] = -1;
			f[0] = -1;
			//f[3] = -1;
			f[4] = -1;
		}

		else if (f[3] > f[1] && f[3] > f[2] && f[3] > f[0] && f[3] > f[4])
		{
			f[1] = -1;
			f[2] = -1;
			f[0] = -1;
			//f[4] = -1;
		}

		else
		{
			f[1] = -1;
			f[2] = -1;
			f[3] = -1;
			//f[0] = -1;
		}
	}	
}

void deal_extra_cards (int p1_f[], int p1_s[], int p2_f[], int p2_s[], int extra_f[], int extra_s[])
{
	int i = 0;

	for (i = 0; i <= 5; i++)
	{
		if (p1_f[0] == -1)
		{
			p1_f[0] = extra_f[i];
			p1_s[0] = extra_s[i];
		}
		else if (p1_f[1] == -1)
		{
			p1_f[1] = extra_f[i];
			p1_s[1] = extra_s[i];
		}
		else if (p1_f[2] == -1)
		{
			p1_f[2] = extra_f[i];
			p1_s[2] = extra_s[i];
		}
		else if (p1_f[3] == -1)
		{
			p1_f[3] = extra_f[i];
			p1_s[3] = extra_s[i];
		}
		else if (p1_f[4] == -1)
		{
			p1_f[4] = extra_f[i];
			p1_s[4] = extra_s[i];
		}

		else if (p2_f[0] == -1)
		{
			p2_f[0] = extra_f[i];
			p2_s[0] = extra_s[i];
		}
		else if (p2_f[1] == -1)
		{
			p2_f[1] = extra_f[i];
			p2_s[1] = extra_s[i];
		}
		else if (p2_f[2] == -1)
		{
			p2_f[2] = extra_f[i];
			p2_s[2] = extra_s[i];
		}
		else if (p2_f[3] == -1)
		{
			p2_f[3] = extra_f[i];
			p2_s[3] = extra_s[i];
		}
		else if (p2_f[4] == -1)
		{
			p2_f[4] = extra_f[i];
			p2_s[4] = extra_s[i];
		}
	}
}