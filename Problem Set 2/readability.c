#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

// Prototype
int calc_grade(char *text);

int main(void)
{
    // Get text to analyse
    char *text_to_analyse = get_string("Text: ");

    // Calculate reading score
    int grade = calc_grade(text_to_analyse);

    // Print grade level
    if(grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int calc_grade(char *text)
{
    // Set up sums
    int letters = 0;
    int words = 1;
    int sentences = 0;

    // Loop through each character and update sums
    for(int i = 0; i < strlen(text); i++)
    {
        char c = toupper(text[i]);
        // printf("Value of '%c' is %i\n", c, c);
        if(c >= 'A' && c <= 'Z')
        {
            letters++;
        }
        else if(c == ' ')
        {
            words++;
        }
        else if(c == '.' || c == '?' || c == '!')
        {
            sentences++;
        }
    }
    // Calculate averages
    float letters_per_100_words = letters * 100 / (float) words;
    float sentences_per_100_words = sentences * 100 / (float) words;

    // Compute and return Coleman-Liau index
    float cl_index = 0.0588 * letters_per_100_words - 0.296 * sentences_per_100_words - 15.8;
    int grade = round(cl_index);

    return grade;
}
