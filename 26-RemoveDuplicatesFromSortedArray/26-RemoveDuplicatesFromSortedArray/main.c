//
//  main.c
//  26-RemoveDuplicatesFromSortedArray
//
//  Created by HuangLibo on 2017/8/10.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 26. Remove Duplicates from Sorted Array
 
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 
 Do not allocate extra space for another array, you must do this in place with constant memory.
 
 For example,
 Given input array nums = [1,1,2],
 
 Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 */

#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int * nums, int numsSize);

int main(int argc, const char * argv[]) {
    
    int * numbs = (int *)malloc(sizeof(int) * 100);
    numbs[0] = -1;
    numbs[1] = 1;
    numbs[2] = 1;
    numbs[3] = 1;
    int result = removeDuplicates(numbs, 4);
    printf("result = %d\n", result);
    
    for (int i = 0; i < result; ++i) {
        printf("%d\n", numbs[i]);
    }
    
    return 0;
}

int removeDuplicates(int * nums, int numsSize) {
    
    if (numsSize <= 1) {
        return numsSize;
    }
    
    int currentElement = nums[0];
    int newSize = 1;
    for (int i = 1; i < numsSize; ++i) {
        if (currentElement != nums[i]) {
            nums[newSize] = nums[i];
            newSize++;
            currentElement = nums[i];
        }
    }
    
    return newSize;
}
