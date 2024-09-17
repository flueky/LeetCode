#include <vector>
#include <map>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> temp;
        for (int i = 0; i < nums.size(); i++)
        {
            int cur = nums[i];
            int complement = target - cur;
            if(temp.count(complement)){
                return {temp[complement], i};
            }
            temp[cur] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> nums{2, 7, 11, 15};
    vector<int> result = Solution().twoSum(nums, 9);
    for(int r : result)
        cout << r << endl;
}