
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *h1 = l1;
        ListNode *h2 = l2;

        ListNode *result = new ListNode();
        ListNode *head = result;
        while (h1 != nullptr || h2 != nullptr)
        {
            int a = 0, b = 0;
            if (h1 != nullptr)
            {
                a = h1->val;
                h1 = h1->next;
            }
            if (h2 != nullptr)
            {
                b = h2->val;
                h2 = h2->next;
            }
            if (a + b != 0)
            {
                head->val += a + b;
            }
            if (head->val >= 10)
            {
                ListNode *next = new ListNode(head->val / 10);
                head->val = head->val % 10;
                head->next = next;
            }
            if (h1 != nullptr || h2 != nullptr)
            {
                if (head->next == nullptr)
                {
                    head->next = new ListNode();
                }
            }
            head = head->next;
        }
        return result;
    }
};
ListNode *createList(int *nums, int len)
{
    ListNode *head = new ListNode();
    ListNode *cur = head;
    for (int i = 0; i < len; i++)
    {
        cur->val = nums[i];
        if (i < len - 1)
        {
            cur->next = new ListNode();
            cur = cur->next;
        }
    }
    return head;
}

int main()
{
    int nums1[] = {2, 4, 9};
    int nums2[] = {5, 6, 4, 9};
    ListNode *l1 = createList(nums1, 3);
    ListNode *l2 = createList(nums2, 4);
    ListNode *result = Solution().addTwoNumbers(l1, l2);
    return 0;
}
