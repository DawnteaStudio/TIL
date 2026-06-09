#include <stdio.h>

int main(void)
{
	int A[3] = {1, 2, 3};
	int B[10];

	for (int i = 0; i < sizeof(B)/sizeof(B[0]); i++)
	{
		B[i] = A[i % (sizeof(A)/sizeof(A[0]))];
		printf("%3d", B[i]);
	}
	return (0);
}