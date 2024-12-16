#include <stdio.h>
#include <conio.h>

void main()
{
    int n, i, j;

    // Input the number of lines for the pattern
    printf("Enter the number of lines: ");
    scanf("%d", &n);

    // Outer loop for the rows
    for (i = 0; i < n; i++)
    {
        // Inner loop for printing stars
        for (j = 0; j < n - i; j++)
        {
            printf("* "); // Print a star followed by a space
        }
        printf("\n"); // Move to the next line after printing stars in a row
    }

    getch();
}
