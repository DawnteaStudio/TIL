#include <stdio.h>

int main(void)
{
    int a = 10, b = 20;

    if (a < 0) //8행과 11행의 중괄호가 지워지면 컴파일러는 else를 가장 가까운 if와 연결짓기 때문에               //
    {          // 아무것도 출력되지 않는다! Dangling else Problem
        if (b > 0)
            printf("ok");
    }
    else
        printf("ok");
    return 0;
}