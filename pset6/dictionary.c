// dictionary.c CC50 Pset6 Implements the functionality of a dictionary.

#include "dictionary.h"

no *hashtable[SIZE] = {NULL};
unsigned int words = 0;

// Load dict into memory. Returns true if successful if not false.

bool
load(const char *dict)
{
    FILE *fp = fopen(dict, "r");
    if (fp == NULL)
        return false;

    char word[LENGTH+1];
    unsigned int index;

    while (fscanf(fp,"%s\n",word) != EOF)
    {
        words++;
        no *new = (no*)malloc(sizeof(no));
        strcpy(new->word, word);
        index = hash(word);
        if (hashtable[index] == NULL)
        {
            hashtable[index] = new;
            new->prox = NULL;
        }
        else
        {
            noew->prox = hashtable[index];
            hashtable[index] = new;
        }
    }
    return true;
}

// Returns true if the word is in the dictionary if not false.

bool
check(const char *word)
{
    int len = strlen(word);
    char word[LENGTH+1];
    for (int i = 0; i < len; i++)
        word[i] = tolower(word[i]);
    word[len] = '\0';

    unsigned int index = hash(word);
    if (hashtable[index] == NULL)
        return false;

    no *cursor = hashtable[index];
    while (cursor != NULL)
    {
        if (strcmp(word, cursor->word) == 0)
            return true;
        cursor = cursor->prox;
    }
    return false;
}

// Returns the number of words in the loaded dictionary.

unsigned int
size(void)
{
    return words;
}

// Unload dictionary from memory. Returns true if successful if not false.

bool
unload(void)
{
    unsigned int index = 0;
    while (index < SIZE)
    {
        if (hashtable[index] == NULL)
            index++;
        else
        {
            while (hashtable[index] != NULL)
            {
                no *cursor = hashtable[index];
                hashtable[index] = cursor->prox;
                free(cursor);
            }
            index++;
        }
    }
    return true;
}

// Hash function, transforms word into number.

unsigned int
hash(const char *word)
{
    unsigned int hash = 0, n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i])) // Alphabet case
            n = word[i]-'a'+1;
        else // Comma case
            n = 27;
        hash = ((hash << 3) + n) % SIZE;
    }
    return hash;
}
