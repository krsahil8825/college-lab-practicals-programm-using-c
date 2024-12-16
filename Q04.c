#include <stdio.h>
#include <conio.h>
void main()
{
	int n, rev = 0, rem = 0, dummy;
	printf("Enter an integer: ");
	scanf("%d", &n);
	dummy = n;
	while (n != 0)
	{
		rem = n % 10;
		n = n / 10;
		rev = rev * 10 + rem;
	}
	if (dummy == rev)
	{
		printf("%d is an Palindrome number.\n", dummy);
	}
	else
	{
		printf("%d is not an Palindrome number.\n", dummy);
	}
	getch();
}