#include "Utils.h"
#include <stdio.h>

void printReturnCode(ReturnCode code) {
    switch(code) {
        case YES :
            printf("Yes");
            break;
        case NO :
            printf("No");
            break;
        case OK :
            printf("OK");
            break;
        case MEMORY_PROBLEM :
            printf("Problem of memory allocation");
            break;
        case EMPTY_ELEMENT :
            printf("The element you tried to interract with is empty");
            break;
        case VAL_NOT_FOUND :
            printf("Value not found");
            break;
        default :
            printf("Unrecognised return code");
    }

    printf("\n");
}
