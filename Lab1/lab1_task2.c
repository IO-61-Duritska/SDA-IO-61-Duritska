#include <stdio.h>

int main() {
    double x;
    double y;

    printf("Enter x: ");
    scanf("%lf", &x);

    
    if (x >= 0 && x < 7) {
        y = -6.0 * x * x + 8.0;
        printf("y = %lf\n", y);
    } else if (x <= -10 || x >= 11) {
        y = -(x * x * x) / 7.0 + 10.0;
        printf("y = %lf\n", y);
    } else {
        printf("Function is not defined for this x.\n");
    }

    return 0;
}