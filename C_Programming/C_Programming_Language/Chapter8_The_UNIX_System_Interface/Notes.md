# THE UNIX SYSTEM INTERFACE

- UNIX operating system provides it services through system calls.

## FILE Descriptors
- In UNIX operating system, all I/O done by reading/writing files. But before reading or writing, file must be **opened**.

- All information about an open file is maintained by system, the user program refers to file only by **file descriptor**

- When command interpreter(the "shell") runs a program, the files are open, 0 -> **standart input**, 1 -> **standart output**, 2 -> **standart error**.

- The user program can redirect I/O to and from files by using **<** and **>**

- The program **doesn't know** where its input comes from nor where its output goes, as long as it uses file 0 for input, and 1 and 2 for output.


## Low Level I/O - Read and Write
- C programs access input and output via **read** and **write** system calls.
``` C
// fd is file descriptor, buf is buffer and n is bytes to read or write.
int n_read = read(int fd, char *buf, int n);
// fd is file descriptor, buf is buffer and n is bytes to read or write.
int n_written = write(int fd, char *buf, int n);
```

## Open, Creat, Close, Unlink
- Files must be opened before read or written.
``` C
// Flags : O_RDONLY -> Read only, O_WRONLY -> Write only, O_RDWR -> Write and Read
int open(char *name, int flags, int perms);
int creat(char *name, int perms);
```

## Random Access - Lseek
- I/O is normally sequential, each read and write takes place at a position in file right after the previous one. But when necessary, file can be read or written in **arbitrary** order. **lseek** system calls provides that.

``` C
long lseek(int fd, long offset, int origin);
```
## An Implementation of Fopen and Getc
- Files in standart library are descripted by file pointers rather than file descriptors. **A file pointer** is pointer to the structure that contains several pieces information about file.
    1. Pointer to buffer
    2. a Count of the number of characters left in the buffer
    3. Pointer to next character poisition in the buffer
    4. The file descriptor
    5. Flags
    6. Read/Write mode
    7. Error status
    8. ETC, ETC
    