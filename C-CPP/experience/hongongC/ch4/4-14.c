#include <stdio.h>

int main(void)
{
    int a = 10, b = 5;
    int res;

    res = a / b * 2; //같은 우선순위 왼쪽부터 연산
    printf("res = %d\n", res);
    res = ++a * 3; //단항이 빠름
    printf("res = %d\n", res);
    res = a > b && a != 5;
    printf("res = %d\n", res);
    res = a % 3 == 0; 
    printf("res = %d\n", res);
    return 0;
}