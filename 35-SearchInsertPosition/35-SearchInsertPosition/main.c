//
//  main.c
//  35-SearchInsertPosition
//
//  Created by HuangLibo on 2017/8/11.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 35. Search Insert Position

 Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 
 You may assume no duplicates in the array.
 
 Here are few examples.
 [1,3,5,6], 5 → 2
 [1,3,5,6], 2 → 1
 [1,3,5,6], 7 → 4
 [1,3,5,6], 0 → 0
 */

#include <stdio.h>
#include <stdlib.h>

int searchInsert(int * nums, int numsSize, int target);

int main(int argc, const char * argv[]) {
    
    int * nums = (int *)malloc(sizeof(int) * 10);
    nums[0] = 1;
    nums[1] = 3;
    nums[2] = 4;
    nums[3] = 7;
    
    int result = searchInsert(nums, 4, 11);
    printf("result = %d\n", result);
    
    return 0;
}

int searchInsert(int * nums, int numsSize, int target) {
    
    if (numsSize == 0) {
        return 0;
    }
    
    int position = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (target > nums[i]) {
            position++;
        } else {
            break;
        }
    }
    
    return position;
}

/* 有网友用了二分法. 速度更快
int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
*/
