#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *create_list(int *nums, int len)
{
    struct ListNode *header = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = header;
    int i;
    for (i = 0; i < len; i++)
    {
        cur->val = nums[i];
        if (i < len - 1)
        {
            cur->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            cur = cur->next;
        }
        cur->next = NULL; // 标记最后一个结束
    }

    return header;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *h1 = l1;
    struct ListNode *h2 = l2;
    struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
    result->val = 0;
    result->next = 0;
    struct ListNode *head = result;

    while (h1 != NULL || h2 != NULL)
    {
        int a = 0, b = 0;
        if (h1 != NULL)
        {
            a = h1->val;
            h1 = h1->next;
        }
        if (h2 != NULL)
        {
            b = h2->val;
            h2 = h2->next;
        }
        if (a + b != 0)
        {
            head->val += a + b;
            head->next = NULL;
        }
        if (head->val >= 10)
        {
            struct ListNode *next = (struct ListNode *)malloc(sizeof(struct ListNode));
            next->val = head->val / 10;
            head->val = head->val % 10;
            next->next = NULL;
            head->next = next;
        }
        if (h1 != NULL || h2 != NULL)
        {
            if (head->next == NULL)
            {
                head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                head->next->val = 0;
                head->next->next = NULL;
            }
            head = head->next;
        }
    }

    return result;
}

int main()
{
    int nums1[] = {2, 4, 9};
    int nums2[] = {5, 6, 4, 9};
    struct ListNode *l1 = create_list(nums1, 3);
    struct ListNode *l2 = create_list(nums2, 4);
    struct ListNode *result = addTwoNumbers(l1, l2);
    return 0;
}