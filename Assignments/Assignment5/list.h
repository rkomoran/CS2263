#ifndef LIST_H
#define LIST_H

typedef struct listnode {
    /* this is a pointer to the next node of class Node
       it is referencing itself */
    struct listnode * next;
    char * tag;
} Node;

Node * Node_construct(char *tag);
/* create a new object with attributes: pointer to another node and a
   string representing a tag */

Node * List_add(Node *head, Node *n);
/* insert new tag and return a pointer to the updated list */

int List_search(Node *head, Node *n);
/* check for duplicates of n*/

void List_print(Node *head);
/* print */

void List_deconstruct(Node * head);
/* frees allocated memory used */

#endif
