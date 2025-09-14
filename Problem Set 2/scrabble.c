#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Set up scoring system
const int CHAR_SCORE[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Prototypes
int calc_score(char *word);

int main(void)
{
    // Get both words
    char *word1 = get_string("Player 1: ");
    char *word2 = get_string("Player 2: ");

    // Calculate word scores
    int score1 = calc_score(word1);
    int score2 = calc_score(word2);

    // Compare and print result
    if(score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if(score1 < score2)
    {
        printf("Player 2 wins!\n");
    } 
    else
    {
        printf("Tie!\n");
    }
}

int calc_score(char *word)
{
    // Set up sum
    int word_score = 0;
    int len = strlen(word);

    // Iterate through each character and sum points
    for(int i = 0; i < len; i++)
    {
        char c = toupper(word[i]);
        int id = c - 'A';
        if(id >= 0 && id < 26)
        {
            word_score += CHAR_SCORE[id];
        }
    }
    return word_score;
}
