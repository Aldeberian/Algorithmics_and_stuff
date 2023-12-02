#ifndef ALGORITHMS___DATA_STRUCTURE_LINKEDLIST_H
#define ALGORITHMS___DATA_STRUCTURE_LINKEDLIST_H

#include "../Utils.h"

typedef struct Node {
    float val;
    struct Node * next;
} Node;

typedef struct Node * LList;

LList emptyLList();
ReturnCode isLListEmpty(LList list);
ReturnCode addStart(LList * list, float val);
ReturnCode addEnd(LList * list, float val);
ReturnCode addSorted(LList * list, float val);
void printLList(LList list);
ReturnCode removeFirst(LList * list);
ReturnCode removeLast(LList * list);
ReturnCode removeFirstVal(LList * list, float val);
ReturnCode removeVal(LList * list, float val);
ReturnCode removeNthVal(LList * list, int rank);
ReturnCode eraseLList(LList * list);
ReturnCode isInList(LList * list, float val);

#endif //ALGORITHMS___DATA_STRUCTURE_LINKEDLIST_H
