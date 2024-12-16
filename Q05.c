#include <stdio.h>
#include <conio.h>

void main()
{
    int n, i, first = 0, second = 1, next;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series up to %d terms: \n", n);

    // Print the Fibonacci series
    for (i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            printf("%d ", first);
        }
        else if (i == 2)
        {
            printf("%d ", second);
        }
        else
        {
            next = first + second;
            printf("%d ", next);
            first = second;
            second = next;
        }
    }

    getch();
}
