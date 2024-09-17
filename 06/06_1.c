#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char val;
    struct node *next;
} LinkNode, *PLinkNode;

char *convert(char *s, int numRows)
{
    PLinkNode *headers = (PLinkNode *)malloc(sizeof(PLinkNode) * numRows);
    PLinkNode *curs = (PLinkNode *)malloc(sizeof(PLinkNode) * numRows);
    for (int i = 0; i < numRows; i++)
    {
        headers[i] = curs[i] = (PLinkNode)malloc(sizeof(LinkNode));
        curs[i]->val = '\0';
        curs[i]->next = NULL;
    }
    int index = 0;
    int flag = 1; // 1 forward, -1 backward
    int course = 0;
    while (s[index] != '\0')
    {
        curs[course]->val = s[index];
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
        curs[course]->next = (PLinkNode)malloc(sizeof(LinkNode));
        curs[course] = curs[course]->next;
        curs[course]->val = '\0';
        curs[course]->next = NULL;
        course += flag;
        index++;
    }
    char *convert = (char *)malloc(sizeof(char) * (index + 1));
    convert[index] = 0;
    index = 0;
    for (int i = 0; i < numRows; i++)
    {
        while (headers[i]->next != NULL)
        {
            PLinkNode cur = headers[i];
            convert[index++] = cur->val;
            headers[i] = headers[i]->next;
            free(cur);
        }
    }
    return convert;
}

int main()
{
    puts(convert("AB", 1));
}