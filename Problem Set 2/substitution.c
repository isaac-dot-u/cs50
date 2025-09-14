#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *cypher(char *text, char *key);

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char *key = argv[1];

    // Check for a valid key
    int key_len = strlen(key);
    for(int i = 0; i < key_len; i++)
    {
        int c = toupper(key[i]);
        if(c < 'A' || c > 'Z')
        {
            printf("Usage: ./substitution key\n");
            return 2;
        }
    }
    if(key_len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 2;
    }

    // If valid, prompt for message
    char *plaintext = get_string("plaintext: ");

    // Convert and print cyphertext
    char *cyphertext = cypher(plaintext, key);
    printf("cyphertext: %s\n", cyphertext);
    free(cyphertext);
    return 0;
}

char *cypher(char *text, char *key)
{
    int text_len = strlen(text);
    char *cyphertext = malloc((text_len + 1) * sizeof(char));;
    for(int i = 0; i < text_len; i++)
    {
        if(text[i] >= 'A' && text[i] <= 'Z')
        {
            cyphertext[i] = (char) (toupper(key[text[i] - 'A']));
        }
        else if(text[i] >= 'a' && text[i] <= 'z')
        {
            cyphertext[i] = (char) (tolower(key[text[i] - 'a']));
        }
        else
        {
            cyphertext[i] = text[i];
        }
    }
    cyphertext[text_len] = '\0';
    return cyphertext;
}
