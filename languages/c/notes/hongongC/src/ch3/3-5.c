#include <stdio.h>

int main(void)
{
    float ft = 1.234567890123456789; // big number anyway
    double db = 1.234567890123456789; //same

    printf("float형 변수의 값 : %.20f\n", ft);
    printf("double형 변수의 값 : %.20lf\n", db); //find diff

    return 0;
}