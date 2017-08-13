//
//  main.c
//  53-MaximumSubarray
//
//  Created by HuangLibo on 2017/8/13.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 53. Maximum Subarray

 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 
 For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 
 
 More practice:
 If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* nums, int numsSize) {
    
    // 局部最优解
    int local = nums[0];
    // 全局最优解
    int global = nums[0];
    
    for (int i = 1; i < numsSize; ++i) {
        local = (local + nums[i] > nums[i]) ? (local + nums[i]) : nums[i];
        global = local > global ? local : global;
    }
    
    return global;
}

int main(int argc, const char * argv[]) {
    
    int * nums = (int *)malloc(sizeof(int) * 10);
    nums[0] = -2;
    nums[1] = 1;
    nums[2] = -3;
    nums[3] = 4;
    nums[4] = -1;
    nums[5] = 2;
    nums[6] = 1;
    nums[7] = -5;
    nums[8] = 6;
    
    int resutl = maxSubArray(nums, 9);
    printf("resutl = %d\n", resutl);
    
    free(nums);
    
    return 0;
}
