#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    string checkPalindrome(string& s, int left, int right)
    {
        int flag = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            flag = 1;
            left--;
            right++;
        }
        if (flag)
        {
            return s.substr(left + 1, right - left - 1);
        }
        else
        {
            return "";
        }
    }
    string longestPalindrome(string s)
    {
        if (s.length() == 1)
            return s;
        string maxStr;
        for (int i = 0; i < s.length() - 1; i++)
        {
            string oddStr = checkPalindrome(s, i, i);
            if (oddStr.length() > maxStr.length())
            {
                maxStr = oddStr;
            }
            string evenStr = checkPalindrome(s, i, i + 1);
            if (evenStr.length() > maxStr.length())
            {
                maxStr = evenStr;
            }
        }

        return maxStr;
    }
};

int main()
{
    cout << Solution().longestPalindrome("abcbdd") << endl;
}