#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    // Open the source file for reading
    FILE *source = fopen(argv[1], "rb");
    if (source == NULL) {
        printf("Failed to open source file.\n");
        return 1;
    }

    // Open the destination file for writing
    FILE *destination = fopen(argv[2], "wb");
    if (destination == NULL) {
        printf("Failed to open destination file.\n");
        fclose(source);
        return 1;
    }

    // Copy contents from source to destination
    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }

    // Close the files
    fclose(source);
    fclose(destination);

    printf("File copied successfully.\n");

    return 0;
}
