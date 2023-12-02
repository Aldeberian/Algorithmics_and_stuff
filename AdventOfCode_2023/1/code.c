#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "code.h"

ReturnCode one() {
    FILE *file = fopen("..\\AdventOfCode_2023\\1\\data.txt", "r");

    if (file == NULL) {
        perror("Error while opening the file");
        return 1;
    }

    char * line = malloc(500 * sizeof(char)) ;

    int total = 0;

    while (fgets(line, 500 * sizeof(char), file) != NULL) {
        char number[3];

        int i = 0;
        int j = strlen(line) - 1;

        while(!isdigit(line[i]) && i<j) {
            i++;
        }
        while(!isdigit(line[j]) && j>0) {
            j--;
        }

        number[0] = line[i];
        number[1] = line[j];
        number[2] = '\0';

        total += atoi(number);
    }

    printf("Total :%d\n", total);

    free(line);
    fclose(file);
}