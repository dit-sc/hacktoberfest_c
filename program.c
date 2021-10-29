#include<stdio.h>

int addValue(int *one, int *two);

int main(void)
{
    int left = 2, right = 3, result = 0;
    result = addValue(&left, &right);
    printf("result = %d, left = %d, right = %d\n", result, left, right);
    return 0;
}

int addValue(int *one, int *two)
{
    *one += 1;;
    *one *= *two;
    (*two)++;
    *two *= 2;
    return *two + *one;
}
