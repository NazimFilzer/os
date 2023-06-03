# Introduction to grep command in UNIX

The `grep` command in UNIX is used to search for lines in files that match a given pattern or search string. It is a powerful tool for text searching and pattern matching. This C program demonstrates the functionality of the `grep` command by searching for a specific string within a file and printing the matching lines.

## Algorithm of the Program

1. Check the number of command-line arguments. If the number of arguments is not 3 (search string and filename), display a usage message and exit.
2. Retrieve the search string and filename from the command-line arguments.
3. Open the file using `fopen()` function with the mode "r" to open it in read-only mode.
4. If the file cannot be opened, display an error message and exit.
5. Use a loop to read each line from the file using `fgets()` function.
6. Check if the search string is present in the current line using `strstr()` function.
7. If a match is found, print the line using `printf()` function.
8. Close the file using `fclose()` function.
9. Exit the program.

## Explanation of the Program

The program begins by including necessary header files:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
```

- `stdio.h` is included for standard input/output operations.
- `stdlib.h` is included for the `exit()` function to handle error conditions.
- `string.h` is included for string manipulation functions.

Next, the main function is defined:

```c
int main(int argc, char *argv[]) {
    // Code goes here
    return 0;
}
```

Inside the main function:

1. The program checks the number of command-line arguments. If the number of arguments is not 3 (search string and filename), a usage message is displayed, and the program exits:

   ```c
   if (argc != 3) {
       printf("Usage: ./grep <search_string> <filename>\n");
       exit(1);
   }
   ```

2. The search string and filename are retrieved from the command-line arguments:

   ```c
   char *searchString = argv[1];
   char *filename = argv[2];
   ```

3. The file is opened using `fopen()` with the mode "r" to open it in read-only mode. If the file cannot be opened, an error message is displayed, and the program exits:

   ```c
   FILE *file = fopen(filename, "r");
   if (file == NULL) {
       printf("Unable to open the file: %s\n", filename);
       exit(1);
   }
   ```

4. The program enters a loop to read each line from the file:

   ```c
   while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
       // Code goes here
   }
   ```

   The `fgets()` function reads each line from the file and stores it in the `line` array.

5. Inside the loop, the program checks if the search string is present in the current line using `strstr()`:

   ```c
   if (strstr(line, searchString) != NULL) {
       printf("%s", line);
   }
   ```

   The `strstr()` function searches for the occurrence of the search string within the line. If a match is found, the line is printed using `printf()`.

6. After the loop, the file is closed using `fclose(file)`:

   ```c
   fclose(file);
   ```

   The `fclose()` function closes the file, freeing the resources associated with it.

7. Finally, the program returns 0 to indicate successful execution:

   ```c
   return 0;
   ```

### Syntax and Details of Functions Used

- `fgets(char *line, int maxLineLength, FILE *file)`:
   - Reads a line from the file into the `line` character array.
   - `line`: The character array to store the line.
   - `maxLineLength`: The maximum length of the line to read.
   - `file`: The file pointer to read from.
   - Returns `NULL` if there is an error or if the end of file is reached.

- `strstr(const char *haystack, const char *needle)`:
   - Searches for the occurrence of the `needle` string within the `haystack` string.
   - `haystack`: The string to search within.
   - `needle`: The string to search for.
   - Returns a pointer to the first occurrence of `needle` within `haystack`, or `NULL` if no match is found.

- `printf(const char *format, ...)`:
   - Prints formatted output to the console.
   - `format`: The format string specifying the output format.
   - `...`: Additional arguments to be formatted and printed.

- `exit(int status)`:
   - Exits the program with the specified status code.
   - `status`: The status code to return.

Feel free to modify and use this program to suit your needs!

```