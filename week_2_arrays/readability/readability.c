#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int countLetters(string text);
int countWords(string text);
int countSentences(string text);

int main(void)
{
    // prompt user for text
    string textInput = get_string("Text: ");

    // assign the number of letters, words, and sentences to variables
    float letters = countLetters(textInput);
    float words = countWords(textInput);
    float sentences = countSentences(textInput);

    // calculate for L
    float L = (letters / words) * 100.0;

    // calculate for S
    float S = (sentences / words) * 100;

    // calculate for Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);
    int i = index;

    // print grade level of the text
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", i);
    }

}

// count letters
int countLetters(string text)
{
    int letterCount = 0;
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    for (int i = 0; i < strlen(text); i++)
    {
        for (int j = 0; j < 52; j++)
        {
            if (alphabet[j] == text[i])
            {
                letterCount++;
            }
        }
    }

    return letterCount;
}

// count words
int countWords(string text)
{
    int wordCount = 0;

    if (text[0] == '\0')
    {
        wordCount = 0;
    }
    else
    {
        wordCount++;
        for (int i = 0; i < strlen(text); i++)
        {
            if (text[i] == ' ' && text[i + 1] != ' ')
            {
                wordCount++;
            }
        }
    }

    return wordCount;
}

// count sentences
int countSentences(string text)
{
    int sentenceCount = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentenceCount++;
        }
    }

    return sentenceCount;
}