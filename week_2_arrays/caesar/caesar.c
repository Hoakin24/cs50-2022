#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string rotate(string text, int key);

int main(int argc, string argv[])
{
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int hasLetter = 0;
    string sKey = "";
    int iKey = 0;

    // checks if there argv[1] has any key
    if (argv[1] == NULL)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
    else
    {
        sKey = argv[1];
    }

    // checks if argv[1] has any letters
    for (int i = 0; i < strlen(sKey); i++)
    {
        for (int j = 0; j < 52; j++)
        {
            if (alphabet[j] == sKey[i])
            {
                hasLetter = 1;
            }
        }
    }

    // tells user how to use the program if user typed an invalid input
    if (argv[2] != NULL || hasLetter == 1)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
    else
    {
        iKey = atoi(sKey);
    }

    // prompts user for plaintext
    string plaintext = get_string("plaintext: ");

    // rotates the text user has typed
    string cipherText = rotate(plaintext, iKey);

    // prints the ciphertext
    printf("ciphertext: %s\n", cipherText);
}

// ciphers the text
string rotate(string text, int key)
{
    // for every character in text, the loop continues
    for (int k = 0; k < strlen(text); k++)
    {
        if (isupper(text[k]))
        {
            text[k] -= 65;
            text[k] += key;
            text[k] %= 26;
            text[k] += 65;
        }
        else if (islower(text[k]))
        {
            text[k] -= 97;
            text[k] += key;
            text[k] %= 26;
            text[k] += 97;
        }
    }
    return text;
}