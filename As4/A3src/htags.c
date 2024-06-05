#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "htags.h"

/*
* read the character stream into the character array and 
*   fill in the number of characters read.
* Standard return of 1/0
*/
int readString(char* html, int htmlMax)
{
    int iErr = 1;
    int iNChar = 0;
    //read, while not eof store the char, read again
    while (iErr == 1 && iNChar < htmlMax-1){
        iErr = scanf("%c", &html[iNChar]);
        iNChar++;
    }
    //terminate the string
    if(iErr == EOF){
        html[iNChar] = (char)NULL;
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}

/*
* search the string from a given address until the first alpha 
*   character after‘<’ is found (no space is allowed in html), returning its address
* 
*   Three cases:
*   (i) start tag for <tagname></tagname> pair
*   (ii) end tag for <tagname></tagname> pair (ignore)
*   (ii) start tag for <tagname/> 
*   (iii) start tag for <!tagname> (ignore)
*/
char* findTagStart(char* html)
{
    // Look for a "<" followed by an alpha character
    char* start;
    // An alpha means it an opening tag (so not "/" or "!")
    /* If we run into:
     *   (i) an alpha char; 
     *   (ii) the end of the string; 
     *   (iii) no more "<" strings
     * then we're done
     */
    // Loop so long as we have a valid pointer
    start = strstr(html, "<");
    while( start != (char*)NULL){
        start++;
        if(*start == (char)NULL) return (char*)NULL;
        if(isalpha(*start)) return start;
        start = strstr(start, "<");
    }
    // Ran out of string
    return start;
}


/*
* search the string from an address until the first whitespace 
*   character is found, returning the last alpha-character address.
*
*/
char* findTagEnd(char* html)
{
    char* end = html;
    while (*end != (char)NULL ){
        if(!isalpha(*end) ) return end-1;
        end++;
    }
    return end-1;
}


/*
* adds the tag to the list and updates
*/
void addTag(char* start, char* end, char* tags[][2], int tagMax, int* nTags, int* tagCount){
    int i;
    int tagLen;
    int different;
    //Check the existing list
    i=0;
    while(i<*nTags && i < tagMax){
        tagLen = tags[i][1]-tags[i][0]+1;
        if(end-start+1 == tagLen){ // same length? maybe they match
            different = strncmp(start, tags[i][0], end-start+1);
            if(!different){ // match
                tagCount[i]++;
                return;
            } 
        }
        i++; 
    }

    // no match, must be new
    if(i<tagMax-1){
        tags[i][0] = start;
        tags[i][1] = end;
        tagCount[i]++;
        (*nTags)++;
    }

    return;
}

/*
* prints out the tag names found and the number of ocurrences.
*/
void reportTags(char* tags[][2], int nTags, int* tagCount){
    int i;
    for(i=0; i<nTags; i++){
        putnchar(tags[i][0], (tags[i][1]-tags[i][0]+1) );
        printf("\t%d\n", tagCount[i]);
    }
    return;
}

/*
* prints out at most n characters of a string.
*/
int putnchar(char* start, int nchar){
    int i = 0;
    while(i< nchar && start[i] != (char)NULL){
        putchar(start[i]);
        i++;
    }
    return i;
}

/*
 * initialize values in an integer array
 */
void initInt(int* arr, int nArr, int value){
    int i;
    for(i=0; i<nArr; i++){
        arr[i] = value;
    }
}