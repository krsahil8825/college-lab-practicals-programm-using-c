#include <stdio.h>
#include <conio.h>

void main() {
    int n, i, j, fact;
    float sum = 0.0;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        fact = 1;
        for (j = 1; j <= i; j++) {
            fact *= j;
        }
        sum += (float)i / fact;
    }

    printf("The sum of the series is: %.6f\n", sum);

    getch();
}
