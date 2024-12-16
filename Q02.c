#include <stdio.h>
#include <conio.h>

void main()
{
    int num, i, prime = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 1)
    {
        prime = 0; // 0 and 1 are not prime numbers
    }
    else
    {
        for (i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
            {
                prime = 0; // If divisible by any number, it's not prime
                break;
            }
        }
    }

    if (prime)
    {
        printf("%d is a prime number.\n", num);
    }
    else
    {
        printf("%d is not a prime number.\n", num);
    }

    getch();
}
