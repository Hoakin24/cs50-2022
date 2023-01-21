// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 17602;

// Hash table
node *table[N];

// Number of Words
int numberOfWords = 0;

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dFile = fopen(dictionary, "r");

    if (dFile == NULL)
    {
        return false;
    }

    char buffer[LENGTH + 1];

    while (fscanf(dFile, "%s", buffer) != EOF)
    {
        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            unload();
            return false;
        }

        strcpy(n->word, buffer);
        n->next = NULL;

        int assignedNumber = hash(n->word);

        node *o = table[assignedNumber];

        if (o == NULL)
        {
            table[assignedNumber] = n;
            numberOfWords++;
        }
        else
        {
            n->next = table[assignedNumber];
            table[assignedNumber] = n;
            numberOfWords++;
        }
    }

    fclose(dFile);
    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int assignment = 0;

    if (strlen(word) <= 1)
    {
        assignment = ((677 * (toupper(word[0]) - 65)) + 1);
        return assignment;
    }
    else if (isalpha(word[1]) == 0)
    {
        assignment = (677 * (toupper(word[0]) - 65));
        return assignment;
    }
    else if (strlen(word) <= 2 || isalpha(word[2]) == 0)
    {
        assignment = ((677 * (toupper(word[0]) - 65)) + (27 * (toupper(word[1]) - 65))) + 1;
        return assignment;
    }
    else
    {
        assignment = ((677 * (toupper(word[0]) - 65)) + (27 * (toupper(word[1]) - 65)) + (toupper(word[2]) - 65)) + 1;
        return assignment;
    }
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return numberOfWords;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int len = strlen(word);
    char copy[LENGTH + 1];

    for (int j = 0; j < len; j++)
    {
        copy[j] = toupper(word[j]);
    }

    copy[len] = '\0';

    int value = hash(copy);

    node *m = table[value];

    while (m != NULL)
    {
        if (strcasecmp(m->word, copy) == 0)
        {
            return true;
        }
        else
        {
            m = m->next;
        }
    }

    free(m);
    return false;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *first = table[i];
        node *cursor = first;
        node *tmp = first;

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }

    return true;
}
