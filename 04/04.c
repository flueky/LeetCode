#include <stdio.h>
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int totalSize = nums1Size + nums2Size;
    int isOdd = totalSize % 2;
    int mediaIndex = totalSize / 2;
    int i = 0, j = 0;
    int index = 0;
    int num1 = 0, num2 = 0;
    while (index <= mediaIndex)
    {
        num1 = num2;
        index++;
        if (i < nums1Size && j < nums2Size)
        {
            if (nums1[i] <= nums2[j])
            {
                num2 = nums1[i];
                i++;
            }
            else
            {
                num2 = nums2[j];
                j++;
            }
            continue;
        }
        if (i < nums1Size)
        {
            num2 = nums1[i];
            i++;
        }
        if (j < nums2Size)
        {
            num2 = nums2[j];
            j++;
        }
    }
    if (isOdd)
    {
        return num2;
    }
    else
    {
        return (num1 + num2) / 2.0;
    }
}

int main()
{
    int a[] = {1, 2};
    int b[] = {3, 4};
    printf("result = %.6f\n", findMedianSortedArrays(a, 2, b, 2));
}