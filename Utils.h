#ifndef ALGORITHMS___DATA_STRUCTURE_UTILS_H
#define ALGORITHMS___DATA_STRUCTURE_UTILS_H

typedef enum { False, True } Bool;

typedef enum {
    YES,
    NO,
    OK,
    MEMORY_PROBLEM,
    EMPTY_ELEMENT,
    VAL_NOT_FOUND
} ReturnCode;

void printReturnCode(ReturnCode code);

#endif //ALGORITHMS___DATA_STRUCTURE_UTILS_H
