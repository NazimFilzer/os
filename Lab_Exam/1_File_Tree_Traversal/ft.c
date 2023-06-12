#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void traverseDirectory(const char *dirPath) {
    DIR *dir;
    struct dirent *entry;

    // Open the directory
    dir = opendir(dirPath);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    // Traverse each entry in the directory
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        // Get the full path of the entry
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dirPath, entry->d_name);

        // Check if the entry is a directory
        struct stat statbuf;
        if (stat(path, &statbuf) == 0 && S_ISDIR(statbuf.st_mode)) {
            // Fork a child process to continue traversing the subdirectory
            pid_t pid = fork();

            if (pid < 0) {
                perror("fork");
                return;
            } else if (pid == 0) {
                // Child process
                printf("PID: %d - Subdirectory: %s\n", getpid(), entry->d_name);
                traverseDirectory(path);
                return;
            } else {
                // Parent process
                wait(NULL);
            }
        } else {
            // It's a file, do something with it (e.g., print the file path)
            printf("File: %s\n", path);
        }
    }

    // Close the directory
    closedir(dir);
}

int main() {
    const char *startDir = "/path/to/directory";

    printf("PID: %d - Starting directory: %s\n", getpid(), startDir);
    traverseDirectory(startDir);

    return 0;
}

