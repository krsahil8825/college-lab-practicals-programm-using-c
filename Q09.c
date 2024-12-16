#include <stdio.h>
#include <conio.h>

void main()
{
    int row, col, i, j;

    // Input number of rows and columns for the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    int matrix[row][col], transpose[col][row];

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

    // Calculate the transpose of the matrix
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            transpose[j][i] = matrix[i][j]; // Swap rows and columns
        }
    }

    // Display the transpose of the matrix
    printf("Transpose of the matrix:\n");
    for (i = 0; i < col; i++)
    {
        for (j = 0; j < row; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    getch();
}
