
#include <stdio.h>

int main()
{
    int n;
    int i;

    double x = 1.0 / 3.0;
    double S = 0;
    double a;

    int operations = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("n must be natural number!");
        return 0;
    }

    a = x * x;
    operations++;

    for (i = 1; i <= n; i++)
    {
        S = S + a;
        operations++;

        if (i < n)
        {
            a = a * (4 * x * x) / ((2 * i + 2) * (2 * i + 1));
            operations += 8;
        }
    }

    printf("Result: %.6f\n", S);
    printf("Operations: %d\n", operations);

    return 0;
}
