#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

float tofahr(int celsius);

float tocelsius(int fahr);

float tofahr(int celsius)
{
    return (9.0/5.0) * celsius + 32;
}

float tocelsius(int fahr)
{
    return (5.0/9.0) * (fahr-32);
}

int main()
{
    for (int fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, tocelsius(fahr));

    return 0;
}

