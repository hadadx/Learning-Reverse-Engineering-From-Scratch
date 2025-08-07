#include <stdio.h>

void merge(int *nums1, int m, int *nums2, int n);
int main(void)
{

    int nums1[] = {1};
    int m = 1;
    int nums2[] = {};
    int n = 0;
    merge(nums1, m, nums2, n);
    printf("num 1 = [");
    for (int i = 0; i < m + n; i++)
    {
        printf("%d,", nums1[i]);
    }
    printf("]\n");

    return 0;
}

/*
    if num1[i] == num2[j] && num1[i+1] !=

*/

void merge(int *nums1, int m, int *nums2, int n)
{

    for (int i = m, d = 0; i < m + n; i++)
    {
        nums1[i] = nums2[d];
        d++;
    }

  
    for (int j = 0; j < n + m; j++)
    {
        int tmp;
        for (int i = 0; i < n + m; i++)
        {
            if (nums1[j] <= nums1[i])
            {
                tmp = nums1[j];
                nums1[j] = nums1[i];
                nums1[i] = tmp;
            }
        }
    }
}