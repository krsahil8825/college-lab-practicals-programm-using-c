#include <stdio.h>
#include <conio.h>

void main()
{
    int row, col, i, j, symmetric = 1;

    // Input number of rows and columns for the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    // Check if matrix is square (rows == columns) for symmetry
    if (row != col)
    {
        printf("Matrix is not square, and thus cannot be symmetric.\n");
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

    // Check if the matrix is symmetric
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                symmetric = 0; // If any element is not equal to its transpose, it's not symmetric
                break;
            }
        }
        if (symmetric == 0)
        {
            break;
        }
    }

    // Output result
    if (symmetric == 1)
    {
        printf("The matrix is symmetric.\n");
    }
    else
    {
        printf("The matrix is not symmetric.\n");
    }

    getch();
}
