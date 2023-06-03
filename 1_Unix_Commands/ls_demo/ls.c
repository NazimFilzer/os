#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    struct dirent *dir;
    DIR *directory = opendir(".");
    
    if (directory == NULL) {
        printf("Unable to open the current directory.\n");
        exit(1);
    }
    
    while ((dir = readdir(directory)) != NULL) {
        printf("%s\n", dir->d_name);
    }
    
    closedir(directory);
    return 0;
}
