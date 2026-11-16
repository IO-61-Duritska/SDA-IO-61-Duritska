
#include <stdio.h>

int main()
{
    int n;
    int i, j;

    double x = 1.0 / 3.0;
    double S = 0;

    double a, b, c;
    double dodatok;

    int operations = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("n must be natural number!");
        return 0;
    }

    for (i = 1; i <= n; i++)
    {
        a = 1;
        b = 1;
        c = 1;

        for (j = 1; j <= 2 * i; j++)
        {
            c = c * j;
            b = b * x;
            operations += 2;

            if (j < 2 * i)
            {
                a = a * 2;
                operations++;
            }
        }

        dodatok = (a * b) / c;
        S = S + dodatok;

        operations += 3;
    }

    printf("Result: %.6f\n", S);
    printf("Operations: %d\n", operations);

    return 0;
}
