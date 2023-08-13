#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
//#include <unistd.h>

void traverse_dir(const char *dir_path) {
  DIR *dir = opendir(dir_path);
  if (dir == NULL) {
    perror("opendir");
    return;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    // Ignore . and ..
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }

    // Check if the entry is a directory
    if (entry->d_type == DT_DIR) {
      // Create a new process to traverse the subdirectory
      int pid = fork();
      if (pid == 0) {
        // This is the child process
        char new_path[PATH_MAX];
        snprintf(new_path, sizeof(new_path), "%s/%s", dir_path, entry->d_name);
        traverse_dir(new_path);
        return;  // Return from the child process after traversal
      }
    } else {
      // This is the parent process
      printf("PID: %d - File: %s/%s\n", getpid(), dir_path, entry->d_name);
    }
  }

  closedir(dir);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    return 1;
  }

  traverse_dir(argv[1]);
  return 0;
}
