#include <stdio.h>
#include <conio.h>

void main()
{
    int row, col, i, j, sum = 0;

    // Input number of rows and columns for the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    // Check if matrix is square (rows == columns)
    if (row != col)
    {
        printf("Matrix is not square, cannot calculate principal diagonal sum.\n");
        return;
    }

    int matrix[row][col];

    // Input elements for the matrix
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate the sum of the principal diagonal
    for (i = 0; i < row; i++)
    {
        sum += matrix[i][i]; // Sum up elements where row index = column index
    }

    // Output the result
    printf("Sum of the principal diagonal: %d\n", sum);

    getch();
}
