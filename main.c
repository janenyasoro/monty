#include <stdio.h>
#include "montymain.h"

int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <monty_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *monty_file = fopen(argv[1], "r");
    if (monty_file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    size_t result = interpret(monty_file);

    if (result == 1) {
        printf("Interpreter successfully executed the Monty code.\n");
    } else {
        printf("Interpreter encountered an error.\n");
    }

    fclose(monty_file);


    return EXIT_SUCCESS;
}
