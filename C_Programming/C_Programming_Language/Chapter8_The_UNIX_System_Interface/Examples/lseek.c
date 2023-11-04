#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/* get : read n bytes from position pos */
int get(int fd, long pos, char *buf, int n)
{
    if(lseek(fd, pos, 0) >= 0)      /* get the pos*/
        return read(fd, buf, n);
    else
        return -1;
}
int main()
{
    int fd = open("test.txt", O_RDONLY, 0);
    char buf[8];
    get(fd, 0, &buf, 1);
    printf("First byte : %x", buf[0]);

    return 0;
}