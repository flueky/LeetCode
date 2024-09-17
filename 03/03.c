#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int find_target(char *s, int start, int end, char target)
{
    for (int i = start; i < end; i++)
    {
        if (s[i] == target)
            return i;
    }
    return -1;
}

int lengthOfLongestSubstring(char *s)
{
    int len = strlen(s);
    int max_length = 0;
    int left = 0, right = 0;
    for (; right < len; right++)
    {
        int flag = find_target(s, left, right, s[right]);
        if (flag >= 0)
        {
            left = flag + 1;
        }
        max_length = max(max_length, right - left + 1);
    }
    return max_length;
}

int main()
{
    int max_length = lengthOfLongestSubstring("abcabcbb");
    printf("%d\n", max_length);
}