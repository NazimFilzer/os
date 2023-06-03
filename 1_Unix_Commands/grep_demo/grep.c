#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./grep <search_string> <filename>\n");
        exit(1);
    }

    char *searchString = argv[1];
    char *filename = argv[2];
    char line[MAX_LINE_LENGTH];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file: %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        if (strstr(line, searchString) != NULL) {
            printf("%s", line);
        }
    }
    fclose(file);
    return 0;
}
