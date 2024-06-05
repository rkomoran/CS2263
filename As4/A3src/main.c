#include <stdlib.h>
#include <stdio.h>
#include "htags.h"

#define MAX_HTML 100000
#define MAX_TAGS 100
/* 
 * Solution for CS263-2020S Assignment Three.
 * 
 * Rick Wightman
 * 
*/
int main(int argc, char* argv[]){

    char htmlDoc[MAX_HTML];
    int iErr;
    char* tagStart;
    char* tagEnd;
    char* tagList[MAX_TAGS][2]; //start and end pointers for each tag
    int tagCount[MAX_TAGS]; //count for each tag name
    int nTags = 0;
    /*
     * Read the html stream from stdin
    */
    iErr = readString(htmlDoc, MAX_HTML);
    if(iErr == EXIT_FAILURE){
        fprintf(stderr, "Unable to read from stdin\n");
        return EXIT_FAILURE;
    }

    initInt(tagCount, MAX_TAGS, 0); // set the tagCounts
    /*
     * Loop through the string, finding tags
    */    
    tagStart = htmlDoc;
    while(tagStart != (char*)NULL ){
        // Find the first beginning tag
        tagStart = findTagStart(tagStart);
        if(tagStart != (char*)NULL ){
            // Find the end
            tagEnd = findTagEnd(tagStart);

            //add the tag
            addTag(tagStart, tagEnd, tagList, MAX_TAGS, &nTags, tagCount);

            // update position in string
            tagStart = tagEnd;
        }

    }
    reportTags(tagList, nTags, tagCount);
    return EXIT_SUCCESS;
}