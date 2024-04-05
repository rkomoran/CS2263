#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

Node * Node_construct(char * tag)
{
    Node * n = malloc(sizeof(Node));
    if (n == NULL)
    {
        printf("Malloc fail\n");
        return NULL;
    }

    n -> tag = malloc(sizeof(char) * (strlen(tag) + 1));
    if ((n -> tag) == NULL)
    {
        free (n);
        return NULL;
    }

    n -> next = NULL;
    strcpy(n -> tag, tag);
    
    return n;
}

Node * List_add(Node * head, Node * n)
{
    /* list is currently empty, add to head*/
    if (head == NULL)
    {
        /* return pointer of current Node */
        return n;
    }

    Node * current = head;
    /* need to use -> here to reference original object being
       passed in to function */
    while (current -> next != NULL)
    {
        current = current -> next;
    }

    /* found empty spot */
    current -> next = n;

    /* return original list */
    return head;
}

int List_search(Node * head, Node * n)
{
    Node * current = head;
    while (current != NULL)
    {
        /* check if strings are same */
        if (strcmp(current -> tag, n -> tag) == 0)
        {
            /* return false */
            return 0;
        }

        /* keep searching */
        current = current -> next;
    }

    /* found no duplicates, return true */
    return 1;
}

void List_print(Node * head)
{
    Node * current = head;
    while (current != NULL)
    {
        printf("%s\n", current -> tag);
        current = current -> next;
    }
}

void List_deconstruct(Node * head)
{
    Node * current = head;
    while (current != NULL)
    {
        /* have to use temp here, cannot free current first */
        Node * temp = current -> next;
        /* must free tag first */
        free(current -> tag);

        /* then the Node itself */
        free(current);

        current = temp;
    }

    printf("\nSuccessfully freed memory\n");
}