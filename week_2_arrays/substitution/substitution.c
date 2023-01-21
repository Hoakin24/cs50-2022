#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string rotate(string text, string key);

int main(int argc, string argv[])
{
    string sKey = "";
    int isNotALetter = 0;
    int letterRepeats = 0;

    // checks if there argv[1] has any key or if argv[2] has any input
    if (argv[1] == NULL || argv[2] != NULL)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
    else
    {
        sKey = argv[1];
    }

    // checks if argv[1] has any non-letter
    for (int i = 0; i < strlen(sKey); i++)
    {
        for (int j = 0; j < 52; j++)
        {
            if (isalpha(sKey[i]) == 0)
            {
                isNotALetter = 1;
            }
        }
    }


    for (int k = 0; k < strlen(sKey); k++)
    {
        for (int l = k + 1; l < strlen(sKey); l++)
        {
            if (sKey[k] == sKey[l])
            {
                letterRepeats = 1;
            }
        }
    }

    // check if argv[1] has 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }
    // checks if argv[1] has any non letter
    else if (isNotALetter == 1)
    {
        printf("Key contains a non-alphabetic character.\n");
        exit(1);
    }
    // checks if argv[1] doesn't contain one letter of each exactly
    else if (letterRepeats == 1)
    {
        printf("Key contains repeating characters.\n");
        exit(1);
    }

    // prompts user for plaintext
    string plaintext = get_string("plaintext: ");

    // rotates the text user has typed
    string cipherText = rotate(plaintext, sKey);

    // prints the ciphertext
    printf("ciphertext: %s\n", cipherText);
}

// ciphers the text
string rotate(string text, string key)
{
    char upperCase[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char lowerCase[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int index = 0;

    // replaces the upperCase and lowerCase array with the key
    for (int i = 0; i < strlen(key); i++)
    {
        if (isupper(key[i]))
        {
            upperCase[i] = key[i];
            lowerCase[i] = tolower(key[i]);
        }
        else if (islower(key[i]))
        {
            lowerCase[i] = key[i];
            upperCase[i] = toupper(key[i]);
        }
    }

    // changes the letter to the corresponding letter
    for (int j = 0; j < strlen(text); j++)
    {
        if (isupper(text[j]))
        {
            index = text[j] - 65;
            text[j] = upperCase[index];
        }
        if (islower(text[j]))
        {
            index = text[j] - 97;
            text[j] = lowerCase[index];
        }
    }
    return text;
}
