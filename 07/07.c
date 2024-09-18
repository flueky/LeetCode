#include <stdio.h>

int reverse(int x)
{
    if (x > 0x7fffffff || x < ~0x7fffffff + 1)
        return 0;
    int negtative = x < 0 ? -1 : 1;
    if (negtative < 0)
        x = ~x + 1;
    long long result = 0;
    while (x > 0)
    {
        result = result * 10 + x % 10;
        x /= 10;
    }
    if (negtative < 0)
        result = ~result + 1;

    if (result > 0x7fffffff || result < ~0x7fffffff + 1)
        return 0;
    return (int)result;
}

int main()
{
    printf("%d\n", reverse(-2147483648));
}