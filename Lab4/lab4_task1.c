#include <stdio.h>

#define MAX 10
#define EPS 0.000001

int equal(double a, double b)
{
    if (a - b < EPS && b - a < EPS)
        return 1;
    else
        return 0;
}

int main()
{
    double A[MAX][MAX];
    double x;
    int m, n;
    int i, j;

    printf("Enter number of rows (7-10): ");
    scanf("%d", &m);

    printf("Enter number of columns (7-10): ");
    scanf("%d", &n);

    if (m < 7 || m > 10 || n < 7 || n > 10)
    {
        printf("Error: matrix size must be from 7 to 10.\n");
        return 1;
    }

    printf("Enter matrix elements in non-decreasing order in each row:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (A[i][j] < A[i][j - 1] - EPS)
            {
                printf("Error: row %d is not sorted.\n", i + 1);
                return 1;
            }
        }
    }

    printf("Enter X: ");
    scanf("%lf", &x);

    printf("\nEntered matrix:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%8.2lf", A[i][j]);
        }
        printf("\n");
    }

    printf("\nSearch results for X = %.2lf:\n", x);

    for (i = 0; i < m; i++)
    {
        int left = 0;
        int right = n - 1;
        int answer = -1;
        int steps = 0;

        while (left <= right)
        {
            int middle = (left + right) / 2;
            steps++;

            if (equal(A[i][middle], x))
            {
                answer = middle;
                right = middle - 1;
            }
            else if (A[i][middle] < x)
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }

        if (answer != -1)
        {
            printf("Row %d: found at column %d; steps = %d\n",
                   i + 1, answer + 1, steps);
        }
        else
        {
            printf("Row %d: not found; steps = %d\n",
                   i + 1, steps);
        }
    }

    return 0;
}