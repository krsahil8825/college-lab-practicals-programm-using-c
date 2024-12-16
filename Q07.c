#include <stdio.h>
#include <conio.h>

void main()
{
    int row1, col1, row2, col2, i, j, k;

    // Input number of rows and columns for the first matrix
    printf("Enter the number of rows for the first matrix: ");
    scanf("%d", &row1);
    printf("Enter the number of columns for the first matrix: ");
    scanf("%d", &col1);

    // Input number of rows and columns for the second matrix
    printf("Enter the number of rows for the second matrix: ");
    scanf("%d", &row2);
    printf("Enter the number of columns for the second matrix: ");
    scanf("%d", &col2);

    // Check if multiplication is possible (columns of first matrix must be equal to rows of second matrix)
    if (col1 != row2)
    {
        printf("Matrix multiplication is not possible. The number of columns of the first matrix must equal the number of rows of the second matrix.\n");
        return;
    }

    int matrix1[row1][col1], matrix2[row2][col2], result[row1][col2];

    // Input elements for the first matrix
    printf("Enter elements of the first matrix:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col1; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("Enter elements of the second matrix:\n");
    for (i = 0; i < row2; i++)
    {
        for (j = 0; j < col2; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            result[i][j] = 0; // Initialize the result matrix element
            for (k = 0; k < col1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j]; // Multiply and add
            }
        }
    }

    // Display the result matrix
    printf("Result of matrix multiplication:\n");
    for (i = 0; i < row1; i++)
    {
        for (j = 0; j < col2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    getch();
}
