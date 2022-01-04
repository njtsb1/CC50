// dictionary.h CC50 Pset6 Declare the functionality of a dictionary.

#ifndef DICTIONARY_H
#define DICTIONARY_H
#define SIZE 160000 // Hashtable size
#define LENGTH 45 // Maximum length of one word (pneumonoultramicroscopicsilicovolcanoconiosis)
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// List structure

typedef struct no
{
    char word[LENGTH+1];
    struct no *prox;
}no;

// Function prototypes.

bool load(const char *dict);
bool check(const char *word);
unsigned int size(void);
bool unload(void);
unsigned int hash(const char *word);

#endif // DICTIONARY_H
