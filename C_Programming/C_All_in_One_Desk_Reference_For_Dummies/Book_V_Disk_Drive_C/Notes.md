# NOTES

- Computers are all about I/O. There is always some sort of input or about devices involved.

- The keyboard is standart input device, nicknamed **stdin**.

- The screen is standart output device, nicknamed **stdout**.

- Third standart IO device is **stderr**, reserved for error output.

- Basically everything in computer is file. A file is collection of stuff or data.

- Because everything is file, we can open **stdin** and read input or we can out **stdout** and save text to it and it will appear on screen. 

- EOF character defined in stdio file for windows is ctrl + z

- Input redirection is done by **<** in Windows and Linux.

- output redirection is done by **>** in Windows and Linux. Also we can perform append with **>>**.

- To display file content from prompt, It can be used as **cat file.extension**. Also we can use **cat file.extension | more** to display file content in chunks.

## Command Line Arguments
- To C program, we can pass argument via command line prompt. 
    1. **argc** : number of arguments
    2. ***arvg[]** : list of arguments. if text writen in double quotes it threated as 1 argument.

- **system()** function gives you ability to run your own little command prompt. Any program in OS could be runned via command prompt, it could be runned via system function.

- When program done it returns a value to operating system. Operating system evaluates that value and if it wants to take action according to it. This is called **exit_status**. 0 shows everything went well.

- To read exit status in Unix  **echo $?** is used.

## File Managment
- **fopen** syntax -> handle = fopen(filename, mode);

- If you want to change file modes, before doing so close the file then re-open it.

- When **b** appended to opening mode it opens files in binary mode.

![fopen Modifiers](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_V_Disk_Drive_C/Images/fopen_Access_Modifiers.PNG)

- Everything we write/read to file is formatted. According to format we do our operations.

- **fscanf()** syntax : fscanf(handle, "&s", &var);

- Newline('\n') serves as break for fscanf function. So when we wanna write array of values we gotta use newline character in order to make it easy to read it back with fscanf function.

- **fwrite()** syntax : c = fwrite(&buffer, size, items, handle);
- **fread()** syntax : c = fread(&buffer, size, items, handle);

### Random File Access
- File pointer is just like tracker for us. When we  read 30 bytes it will be pointing to 31 bytes etc.

- **ftell()** functions tell where is the file pointer.
- **fseek()** functions position the file pointer at specific offset. x = fseek(handle, offset, whence);
    1. For whence : **SEEK_SET** -> start reading relative to **start** of file
    2. For whence : **SEEK_END** -> start reading relative to **end** of file
    3. For whence : **SEEK_CUR** -> start reading relative to last data was reading. basically to **cursor**.

- fseek returns 0 if succesfully read, otherwise -1.

- **rewind** function reset file pointer to position 0 at the start of file.


## Disk Management
- In Windows and Unix files are organied in folders or directories.

- The way to get info about file in C is -> **stat(filename, &stat_buf);**. If succesfully read, stat returns 0, else returns -1

- filename could be just file name or file path living somewhere else in different directory.   

- To read directory files (which is small database containing information about directory) **handle = opendir(pathname)** is used.

- **.** is shortcut for current working directory both in Windows and Unix. if **opendir** returns **NULL** directory was unable to be opened.

- After you done, **x = closedir(handle)** is used to close directory. If returns **0**, closing was succesfull.Else if returned **-1** it was unsuccesfull.

- To read files from directory ***dirent = readdir(handle)** is used

- **string = getcwd(&buffer, size)** is command for getting current working directory. 

- To change different directory **x = chdir(path);** can be used.Upon success returns 0, otherwise -1.


- **Recursion is really nothing more than a function calling itself**.

- **.** is a shortcut specifying the current directory.

- **..** is a shortcut specifying the parent directory.

- Renaming a file is : **x = rename(current,new)**. Returns 0 if success, -1 if error occurs.

- errno.h defines error codes for file acces.

- To delete file in C **x = unlink(filename)** is used. Return 0 if success, else -1.

- Moving file is same as copying but removing source file.

- Copying file is opening file and reading its content then write it to otherfile.