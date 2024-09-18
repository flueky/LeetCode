#include <iostream>
#include <limits>

using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        if (x >= numeric_limits<int>::max() || x <= numeric_limits<int>::min())
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

        if (result >= numeric_limits<int>::max() || result <= numeric_limits<int>::min())
            return 0;
        return (int)result;
    }
};

int main()
{
    cout << Solution().reverse(-2147483648);
    return 0;
}