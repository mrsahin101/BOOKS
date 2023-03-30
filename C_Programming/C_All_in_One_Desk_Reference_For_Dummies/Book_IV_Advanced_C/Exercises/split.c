#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t hex;
    uint8_t array[4];

    printf("Enter a four-digit hex value:");
    scanf("%x", &hex);
    
    array[0] = (hex & 0x000000FF);
    array[1] = (hex & 0x0000FF00) >> 8;
    array[2] = (hex & 0x00FF0000) >> 16;
    array[3] = (hex & 0xFF000000) >> 24;

    
    printf("0x%04X is composed of 0x%02X, 0x%02X, 0x%02X and 0x%02X\n", hex, array[3], array[2], array[1], array[0]);
    return(0);
}