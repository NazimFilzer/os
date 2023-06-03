# Introduction to CP command in UNIX

This C program demonstrates the functionality of the `cp` command in UNIX. The `cp` command is used to copy files from a source file to a destination file. The program opens the source file for reading and the destination file for writing, then copies the contents from the source file to the destination file.

## Algorithm

The program follows the following algorithm:

1. Check if the number of command-line arguments is correct (should be 3: the program name, source file, and destination file).
2. Open the source file for reading using the `fopen` function.
3. If the source file fails to open, display an error message and exit the program.
4. Open the destination file for writing using the `fopen` function.
5. If the destination file fails to open, display an error message, close the source file, and exit the program.
6. Create a buffer array to store the data read from the source file.
7. Use a loop to read data from the source file into the buffer and write it to the destination file using the `fread` and `fwrite` functions.
8. Continue reading and writing data until the end of the source file is reached.
9. Close the source and destination files using the `fclose` function.
10. Display a success message indicating that the file has been copied successfully.

## Program Explanation

The program starts by checking the number of command-line arguments (`argc`). If the number is not 3, it displays a usage message and exits the program.

Next, it opens the source file (`argv[1]`) for reading in binary mode using the `fopen` function. If the file fails to open, it displays an error message and exits the program.

Then, it opens the destination file (`argv[2]`) for writing in binary mode using the `fopen` function. If the file fails to open, it displays an error message, closes the source file, and exits the program.

A buffer array of size 1024 is created to store the data read from the source file.

The program uses a loop to read data from the source file into the buffer using the `fread` function. It specifies the size of each element to be 1, the maximum number of elements to be the size of the buffer, and the file pointer of the source file. The `fread` function returns the number of elements successfully read.

Inside the loop, the program writes the data from the buffer to the destination file using the `fwrite` function. It specifies the size of each element to be 1, the number of elements to be the number of elements read by `fread`, the file pointer of the destination file, and the data buffer.

The loop continues reading and writing data until the end of the source file is reached.

After copying is complete, the program closes the source and destination files using the `fclose` function.

Finally, it displays a success message indicating that the file has been copied successfully.

### `fread` Function

The `fread` function is a C library function used to read data from a file. It is commonly used to read binary data from files. This function allows you to read a specified number of elements, each with a specified size, from a file stream and store them in a memory buffer.

*** Syntax ***

```c
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
```

- `ptr`: A pointer to the memory block where the data read from the file will be stored.
- `size`: The size of each element to be read, in bytes.
- `count`: The maximum number of elements to be read.
- `stream`: The file pointer associated with the file from which the data will be read.

*** Return Value ***

The `fread` function returns the total number of elements successfully read from the file.

*** Usage ***

In the program, `fread` is used inside a loop to read data from the source file into a buffer. The function reads `sizeof(buffer)` bytes (1 byte at a time) from the file pointed to by `source`, and stores the read data in the `buffer` array. The number of elements successfully read (`bytesRead`) is stored and checked to determine if the end of the file has been reached.

### `fwrite` Function

The `fwrite` function is a C library function used to write data to a file. It is commonly used to write binary data to files. This function allows you to write a specified number of elements, each with a specified size, to a file stream from a memory buffer.

*** Syntax ***

```c
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
```

- `ptr`: A pointer to the memory block containing the data to be written to the file.
- `size`: The size of each element to be written, in bytes.
- `count`: The number of elements to be written.
- `stream`: The file pointer associated with the file to which the data will be written.

*** Return Value ***

The `fwrite` function returns the total number of elements successfully written to the file.

*** Usage ***
In the program, `fwrite` is used inside the same loop that uses `fread`. It writes the data from the buffer to the destination file pointed to by `destination`. It writes `bytesRead` elements (each of size 1 byte) from the `buffer` array to the file.

## Functions used:

- `fopen`: Opens a file.
- `fclose`: Closes a file.
- `fread`: Reads data from a file.
- `fwrite`: Writes data to a file.

