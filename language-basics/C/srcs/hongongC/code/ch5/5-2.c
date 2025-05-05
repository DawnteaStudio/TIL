#include <stdio.h>

int main(void)
{
    int a = 10;

    if (a >= 0)
        a = 1;
    else
        a = 0;
    
    printf("a : %d\n", a);

    return 0;
}