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

![fopen Modifiers](https://github.com/mrsahin101/BOOKS/blob/main/C_Programming/C_All_in_One_Desk_Reference_For_Dummies/Book_V_Disk_DriveC/Images/fopen_Access_Modifiers.PNG)

- Everything we write/read to file is formatted. According to format we do our operations.

- **fscanf()** syntax : fscanf(handle, "&s", &var);

- Newline('\n') serves as break for fscanf function. So when we wanna write array of values we gotta use newline character in order to make it easy to read it back with fscanf function.

- **fwrite()** syntax : c = fwrite(&buffer, size, items, handle);
- **fread()** syntax : c = fread(&buffer, size, items, handle);