 #include <stdio.h>

 int main()
 {
    float lighyear = 5.878E12;
    float jupiter = 483400000;
    float distance;

    distance = jupiter / lighyear;
    printf("Jupiter is %f light years from the sun.\n",distance);
    return(0);
 }