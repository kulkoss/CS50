#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char rotate(string s, int key);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    string s = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0, j = strlen(s); i < j; i++)
        {
            // Make sure every character in argv[1] is a digit
            if (s[i] > 57 || s[i] < 48)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);
    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    printf("%c\n", rotate(plaintext, key)); //zwraca char z funkcji rotate
}


char rotate(string s, int key)
{
    for (int i = 0, j = strlen(s); i < j; i++)
    {
        if (isupper(s[i]))
        {
            s[i] = (((s[i] - 65) + key) % 26) + 65;
            printf("%c", s[i]);
        }
        else if (islower(s[i]))
        {
            s[i] = (((s[i] - 97) + key) % 26) + 97;
            printf("%c", s[i]);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    return 1;
}
