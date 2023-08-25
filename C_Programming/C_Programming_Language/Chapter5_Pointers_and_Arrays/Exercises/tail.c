#include <stdio.h>
#include <stdlib.h>

int default_lines;
static char array[20][20] = 
{
    "Sauron",
    "Galadriel",
    "Gandalf",
    "Saruman",
    "Elrond",
    "Witch-King",
    "Aragorn",
    "Arwen",
    "Legolas",
    "Gimli",
    "Frodo",
    "Sam",
    "Boromir",
    "Theoden",
    "Faramir",
    "Gollum",
    "Bilbo Baggins",
    "Peregrin Took",
    "Meriadoc Brandybuck",
    "Haldir",
};
int main(int argc, char *argv[])
{
    if(argc == 1)
        default_lines = 10;
    else
        default_lines = atoi(argv[1]);

    for(int i = 19; i >= 20 - default_lines; i--)
        printf("%s\n", array[i]);

}