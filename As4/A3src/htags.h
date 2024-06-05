#ifndef HTAGS_H
#define HTAGS_H

/*
* read the character stream into the character array and return it
*/
int readString(char* html, int htmlMax);

/*
* search the string from a given address until the first alpha 
*   character after‘<’ is found, returning its address
*/
char* findTagStart(char* html);

/*
* search the string from an address until the first non-alpha 
*   character is found, returning the last alpha-character address.
*/
char* findTagEnd(char* html);

/*
* adds the tag to the list and updates
*/
void addTag(char* start, char* end, char* tags[][2], int tagMax, int* nTags, int* tagCount);

/*
* prints out the tag names found and the number of ocurrences.
*/
void reportTags(char* tags[][2], int nTags, int* tagCount);

/*
* prints out at most n characters of a string.
*/
int putnchar(char* start, int nchar);

/*
 * initialize values in an integer array
 */
void initInt(int* arr, int nArr, int value);

#endif