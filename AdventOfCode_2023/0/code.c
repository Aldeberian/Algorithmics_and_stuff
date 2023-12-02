#include <stdio.h>
#include <stdlib.h>

#include "code.h"

ReturnCode one() {
    FILE *file = fopen("..\\AdventOfCode_2023\\1\\data.txt", "r");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    char line[256];

    int i = 1;
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%d : %s\n", i, line);
        i++;
    }

    fclose(file);
}