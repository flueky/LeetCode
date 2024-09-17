#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIST_LENG 50

typedef struct node
{
    char *values;
    int index;
    int maxLen;
} ListNode, *PListNode;

int insert_list(PListNode node, char val)
{
    if (node->index == node->maxLen - 1)
    {
        char *newArr = (char *)malloc(sizeof(char) * (node->maxLen + LIST_LENG));
        memcpy(newArr, node->values, node->maxLen);
        char *temp = node->values;
        node->values = newArr;
        node->maxLen = node->maxLen + LIST_LENG;
        free(temp);
    }
    node->values[node->index] = val;
    node->index++;
    return 1;
}

char *convert(char *s, int numRows)
{
    PListNode *all = (PListNode *)malloc(sizeof(PListNode) * numRows);
    for (int i = 0; i < numRows; i++)
    {
        all[i] = (PListNode)malloc(sizeof(ListNode));
        all[i]->values = (char *)malloc(sizeof(char) * LIST_LENG);
        all[i]->index = 0;
        all[i]->maxLen = LIST_LENG;
    }
    int index = 0;
    int flag = 1; // 1 forward, -1 backward
    int course = 0;
    while (s[index] != '\0')
    {
        if (numRows == 1)
        {
            flag = 0;
        }
        else if (course == numRows - 1)
        {
            flag = -1;
        }
        else if (course == 0)
        {
            flag = 1;
        }
        insert_list(all[course], s[index]);
        course += flag;
        index++;
    }
    char *convert = (char *)malloc(sizeof(char) * (index + 1));
    convert[index] = 0;
    index = 0;
    int len = 0;
    for (int i = 0; i < numRows; i++)
    {
        memcpy(convert + len, all[i]->values, all[i]->index);
        len += all[i]->index;
    }
    return convert;
}

int main()
{
    puts(convert("PAYPALISHIRING", 3));
}