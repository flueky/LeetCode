#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;
class Solution
{
public:
    int find_target(const char *s, int start, int end, char target)
    {
        for (int i = start; i < end; i++)
        {
            if (s[i] == target)
                return i;
        }
        return -1;
    }
    int lengthOfLongestSubstring(string s)
    {
        int len = s.length();
        const char *c_str = s.c_str();
        int max_length = 0;
        int left = 0;
        for (int right = 0; right < len; right++)
        {
            int flag = find_target(c_str, left, right, c_str[right]);
            if (flag >= 0)
            {
                left = flag + 1;
            }
            max_length = max(max_length, right - left + 1);
        }
        return max_length;
    }
};

int main()
{
    int max_length = Solution().lengthOfLongestSubstring("abcabcbb");
    cout << max_length << endl;
}
