#include <stdio.h>
#include <conio.h>
void main()
{
	int n, sum = 0, rem = 0, dummy;
	printf("Enter an integer: ");
	scanf("%d", &n);
	dummy = n;
	while (n != 0)
	{
		rem = n % 10;
		n = n / 10;
		sum = sum + rem * rem * rem;
	}
	if (dummy == sum)
	{
		printf("%d is an Armstrong number.\n", dummy);
	}
	else
	{
		printf("%d is not an Armstrong number.\n", dummy);
	}
	getch();
}
