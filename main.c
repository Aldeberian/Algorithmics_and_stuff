#include <stdio.h>

#include "LinkedList/LinkedList.h"
#include "Utils.h"

int main() {
    LList nouv = emptyLList();

    printf("Est ce que la liste est vide ?");
    printReturnCode(isLListEmpty(nouv));

    printf("Est ce que la liste est vide ?");
    printReturnCode(isLListEmpty(nouv));

    printLList(nouv);

    addSorted(&nouv, 1);
    addSorted(&nouv, 5);
    addSorted(&nouv, 27);
    addSorted(&nouv, 11);
    addSorted(&nouv, 2);
    addSorted(&nouv, 0);
    addSorted(&nouv, 31);
    addSorted(&nouv, -5);
    addSorted(&nouv, 11);
    addEnd(&nouv, 11);
    addStart(&nouv, 11);
    addEnd(&nouv, 11);

    printLList(nouv);

    removeNthVal(&nouv, 3);
    removeNthVal(&nouv, 3);

    printLList(nouv);

    return 0;
}
