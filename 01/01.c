#include <stdio.h>
#include <stdlib.h>

/**
 * 126ms 17.7%
 * 8.51MB 55.75%
 */
int *twoSum1(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *result = malloc(sizeof(int) * *returnSize);
    int i = 0;
    for (i = 0; i < numsSize - 1; i++)
    {
        int j = i + 1;
        for (; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
            }
        }
    }
    return result;
}

typedef struct node
{
    int index;
    int result; // save the result = target - nums
} Node;
/**
 * 75ms 88.14%
 * 8.94MB 8.47%
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *result = malloc(sizeof(int) * *returnSize);
    int i = 0;
    Node *temp = malloc(sizeof(Node) * numsSize);
    for (i = 0; i < numsSize; i++)
    {
        int cur = nums[i];
        int complement = target - cur;
        int j = 0;
        int flag = 0; // find the checked result
        for (; j < i; j++)
        {
            if (complement == temp[j].result)
            {
                flag = 1;
                result[0] = temp[j].index;
                break;
            }
        }
        if (flag == 1)
        {
            result[1] = i;
            break;
        }
        temp[i].result = cur;
        temp[i].index = i;
    }
    return result;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int returnSize = 0;
    int *result = twoSum(nums, 4, 18, &returnSize);
    int index = 0;
    for (index = 0; index < returnSize; index++)
    {
        printf("%d ", result[index]);
    }
    printf("\n");
}