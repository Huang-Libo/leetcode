//
//  main.c
//  88-MergeSortedArray
//
//  Created by HuangLibo on 2017/8/17.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 88. Merge Sorted Array

 Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 
 Note:
 You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int * nums1, int m, int * nums2, int n) {
    
    if (n == 0) return;
    
    int * result = (int *)malloc(sizeof(int) * (m + n));
    
    int p = 0;
    int q = 0;
    
    for (int i = 0; i < m + n; ++i) {
        if (p < m && q < n) {
            if (nums1[p] < nums2[q]) {
                result[i] = nums1[p];
                p++;
            } else {
                result[i] = nums2[q];
                q++;
            }
        } else if (p < m) {
            result[i] = nums1[p];
            p++;
        } else if (q < n) {
            result[i] = nums2[q];
            q++;
        }
    }
    
    for (int j = 0; j < m + n; ++j) {
        nums1[j] = result[j];
    }
}

int main(int argc, const char * argv[]) {
    
    int * nums1 = (int *)malloc(sizeof(int) * 10);
    int * nums2 = (int *)malloc(sizeof(int) * 10);
    
    nums1[0] = 1;
    nums1[1] = 2;
    nums1[2] = 4;
    nums1[3] = 5;
    nums1[4] = 7;
    nums1[5] = 16;
    
    nums2[0] = 5;
    nums2[1] = 134;
    
    merge(nums1, 6, nums2, 2);
    
    free(nums1);
    free(nums2);
    
    return 0;
}

/* 网友的这个方法更好, 从后往前处理, 把得到的数字放到高位.
void merge(int* nums1, int m, int* nums2, int n) {
    int i, j, k ;
    i = m - 1; j = n - 1; k = m + n -1;
    while(i >= 0 || j>=0){
        if(j < 0|| (i >= 0 && nums1[i] > nums2[j])){
            nums1[k--] = nums1[i--];
        }else{
            nums1[k--] = nums2[j--];
        }
    }
    return ;
    
}
*/
