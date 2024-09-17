#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkPalindrome(char *s, int left, int right, int *start, int *end)
{
    int flag = 0;
    while (left >= 0 && s[right] != '\0' && s[left] == s[right])
    {
        flag = 1;
        *start = left;
        *end = right;
        left--;
        right++;
    }
    return flag;
}

char *longestPalindrome(char *s)
{
    int len = strlen(s);
    if (len == 1)
    {
        return s;
    }
    int maxLength = 0;
    int maxLeft = 0, maxRight = 0;
    for (int i = 0; i < len - 1; i++)
    {
        // check odd str(center is one character)
        int start = i, end = i;
        if (checkPalindrome(s, i, i, &start, &end))
        {
            if (maxLength < end - start + 1)
            {
                maxLength = end - start + 1;
                maxLeft = start;
                maxRight = end;
            }
        }
        // check even str(center is between two characters)
        start = i, end = i + 1;
        if (checkPalindrome(s, i, i + 1, &start, &end))
        {
            if (maxLength < end - start + 1)
            {
                maxLength = end - start + 1;
                maxLeft = start;
                maxRight = end;
            }
        }
    }
    char *result = (char *)malloc(sizeof(char) * (maxLength + 1));
    result[maxLength] = '\0';
    memcpy(result, s + maxLeft, maxLength);
    return result;
}

int main()
{
    char *result = longestPalindrome("abcbdd");
    printf("%s\n", result);
}