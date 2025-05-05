#include <stdio.h>

int main(void)
{
    short sh = 32767;
    int in = 2147483647;
    long ln = 2147483547;
    long long lln = 123451234512345; // big number anyway

    printf("short형 변수 출력 : %d\n", sh);
    printf("intt형 변수 출력 : %d\n", in);
    printf("long형 변수 출력 : %ld\n", ln);
    printf("long long형 변수 출력 : %lld\n", lln);

    return 0;
}