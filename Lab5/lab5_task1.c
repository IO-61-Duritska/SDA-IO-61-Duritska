
#include <stdio.h>

#define M 7
#define N 7

void print_matrix(int a[M][N])
{
    int i, j;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void shaker_sort_column(int a[M][N], int col)
{
    int left = 0;
    int right = M - 1;
    int i;
    int temp;
    int swapped = 1;

    while (left < right && swapped == 1)
    {
        swapped = 0;

        for (i = left; i < right; i++)
        {
            if (a[i][col] > a[i + 1][col])
            {
                temp = a[i][col];
                a[i][col] = a[i + 1][col];
                a[i + 1][col] = temp;
                swapped = 1;
            }
        }

        right--;

        for (i = right; i > left; i--)
        {
            if (a[i - 1][col] > a[i][col])
            {
                temp = a[i - 1][col];
                a[i - 1][col] = a[i][col];
                a[i][col] = temp;
                swapped = 1;
            }
        }

        left++;
    }
}

void sort_matrix_columns(int a[M][N])
{
    int j;

    for (j = 0; j < N; j++)
    {
        shaker_sort_column(a, j);
    }
}

int main()
{
    int a[M][N];
    int i, j;

    printf("Enter 7 rows and 7 columns:\n");

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nInitial matrix:\n");
    print_matrix(a);

    sort_matrix_columns(a);

    printf("\nSorted matrix:\n");
    print_matrix(a);

    return 0;
}
