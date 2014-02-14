/* This is the programming assignment 8 header file */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shuffle (int wDeck[][13]);
void deal (const int wDeck[][13], const char *wFace[], const char *wSuit[], int p1_f[], int p1_s[], int p2_f[], int p2_s[], int extra_f[], int extra_s[]);
int is_it_a_pair (int f[]);
int is_it_two_pair (int f[]);
int is_it_a_three_kind (int f[]);
int is_it_a_four_kind (int f[]);
int is_it_a_flush (int s[]);
void analyze_hand (int f[], int s[], int hand);
void deal_extra_cards (int p1_f[], int p1_s[], int p2_f[], int p2_s[], int extra_f[], int extra_s[]);

