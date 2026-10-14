#include <stdio.h>

int main(void)
{
    double x, y;

    printf("Enter x: ");
    scanf("%lf", &x);

    if (x >= 0 && x < 7)
    {
        y = -6 * x * x + 8;
        printf("y = %.2f\n", y);
    }
    else if (x <= -10 || x >= 11)
    {
        y = -(x * x * x) / 7.0 + 10;
        printf("y = %.2f\n", y);
    }
    else
    {
        printf("Function is not defined for this x.\n");
    }

    return 0;
}
