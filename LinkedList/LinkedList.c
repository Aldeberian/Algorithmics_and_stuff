#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "../Utils.h"

LList emptyLList() {
    return NULL;
}

ReturnCode isLListEmpty(LList list) {
    return (list == NULL ? YES : NO);
}

/**
 * Add a value as the first node of the linked list
 * @param list
 * @param val
 * @return ReturnCode
 */
ReturnCode addStart(LList * list, float val) {
    Node * temp = (Node*) malloc(sizeof(Node));

    if(temp == NULL) return MEMORY_PROBLEM;

    temp->val = val;
    temp->next = *list;
    *list = temp;

    return OK;
}

/**
 * Add a value as the last node of the linked list
 * @param list
 * @param val
 * @return Return Code
 */
ReturnCode addEnd(LList * list, float val) {
    Node * newNode = (Node*) malloc(sizeof(Node));

    if(newNode == NULL) return MEMORY_PROBLEM;

    newNode->next = NULL;
    newNode->val = val;

    if(*list == NULL) {
        *list = newNode;
        return OK;
    }

    struct Node * temp = *list;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    return OK;
}

/**
 * Add a value in order in the linked list
 * @param list
 * @param val
 * @return Return Code
 */
ReturnCode addSorted(LList * list, float val) {
    Node * newNode = (Node*) malloc(sizeof(Node));

    if(newNode == NULL) return MEMORY_PROBLEM;

    newNode->next = NULL;
    newNode->val = val;

    if(isLListEmpty(*list) == YES) {
        *list = newNode;
        return OK;
    }

    //If the first value of the list is bigger than the value
    if((*list)->val > val) {
        newNode->next = *list;
        *list = newNode;
        return OK;
    }

    struct Node * temp = *list;
    while(temp->next != NULL && temp->next->val <= val) {
        temp = temp->next;
    }

    if(temp->next == NULL) {
        temp->next = newNode;
    }
    else {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return OK;
}


/**
 * Removes the first element of a linked list
 * @param list
 * @return Return Code
 */
ReturnCode removeFirst(LList * list) {
    if(*list == NULL) {
        return EMPTY_ELEMENT;
    }

    struct Node * temp = *list;
    *list = (*list)->next;
    free(temp);

    return OK;
}

/**
 * Remove the last element of a linked list
 * @param list
 * @return Return Code
 */
ReturnCode removeLast(LList * list) {
    if(*list == NULL) {
        return EMPTY_ELEMENT;
    }

    struct Node * temp = *list;
    struct Node* prev = NULL;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    free(temp);
    prev->next = NULL;

    return OK;
}

ReturnCode eraseLList(LList * list) {
    while((*list) != NULL) {
        struct Node * temp = *list;
        *list = (*list)->next;
        free(temp);
    }

    return OK;
}

/**
 * Returns if a given val is in a list
 * @param list
 * @param val
 * @return Return Code
 */
ReturnCode isInList(LList * list, float val) {

    struct Node * temp = *list;
    while(temp != NULL) {
        if(temp->val == val) {
            return YES;
        }
        temp = temp->next;
    }

    return NO;
}

/**
 * Removes the first occurrence of a value in the linked list
 * @param list
 * @param val
 * @return Return Code
 */
ReturnCode removeFirstVal(LList * list, float val) {
    if(*list == NULL) {
        return EMPTY_ELEMENT;
    }

    struct Node * temp = *list;
    struct Node * prev = *list;
    while(temp->next != NULL) {
        if(temp->val == val) {
            prev->next = temp->next;
            free(temp);
            return OK;
        }
        prev = temp;
        temp = temp->next;
    }

    return VAL_NOT_FOUND;
}

/**
 * Removes every occurrences of a value in the linked list
 * @param list
 * @return Return Code
 */
ReturnCode removeVal(LList * list, float val) {
    Bool found = False;

    if(*list == NULL) {
        return EMPTY_ELEMENT;
    }

    struct Node * temp = *list;
    struct Node * prev = NULL;

    while(temp != NULL) {
        if(temp->val == val) {
            found = True;

            if(prev == NULL) {
                *list = temp->next;
                free(temp);
                temp = *list;
            }
            else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        }
        else {
            prev = temp;
            temp = temp->next;
        }
    }

    if(found == True) {
        return OK;
    }

    return VAL_NOT_FOUND;
}

/**
 * Remove the Nth val in the linked list
 * @param list
 * @param rank
 * @return Return Code
 */
ReturnCode removeNthVal(LList * list, int rank) {
    int current = 1;

    struct Node * temp = *list;
    struct Node * prev = NULL;
    while(temp != NULL && current != rank) {
        current++;
        prev = temp;
        temp = temp->next;
    }

    if(current == rank) {
        prev->next = temp->next;
        free(temp);
        return OK;
    }
    else {
        return VAL_NOT_FOUND;
    }
}

/**
 * Print the content of the linked list
 * @param list
 */
void printLList(LList list) {
    while(list != NULL) {
        printf("%0.1f -> ", list->val);
        list = list->next;
    }

    printf("NULL\n");
}