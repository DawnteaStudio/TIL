#include <stdio.h>

int main(void)
{
    int age = 25, chest = 95;
    char size;

    if (age < 20)
    {
        if (chest >= 95)
            size = 'L';
        else if (chest >= 85)
            size = 'M';
        else
            size = 'S';
    }
    else
    {
        if (chest >= 100)
            size = 'L';
        else if (chest >= 90)
            size = 'M';
        else
            size = 'S';
    }
    printf("사이즈는 %c입니다.\n", size);
    return 0;
}