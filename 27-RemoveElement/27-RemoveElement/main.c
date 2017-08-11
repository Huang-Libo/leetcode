//
//  main.c
//  27-RemoveElement
//
//  Created by HuangLibo on 2017/8/11.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 27-RemoveElement
 
 Given an array and a value, remove all instances of that value in place and return the new length.
 
 Do not allocate extra space for another array, you must do this in place with constant memory.
 
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 
 Example:
 Given input array nums = [3,2,2,3], val = 3
 
 Your function should return length = 2, with the first two elements of nums being 2.
 */

#include <stdio.h>
#include <stdlib.h>

int removeElement(int * nums, int numsSize, int val);

int main(int argc, const char * argv[]) {
    
    int * numbs = (int *)malloc(sizeof(int) * 100);
    numbs[0] = -1;
    numbs[1] = 1;
    numbs[2] = 1;
    numbs[3] = 3;
    int result = removeElement(numbs, 4, -1);
    printf("result = %d\n", result);
    
    for (int i = 0; i < result; ++i) {
        printf("%d\n", numbs[i]);
    }
    
    return 0;
}

int removeElement(int * nums, int numsSize, int val) {
    
    if (numsSize == 0) {
        return 0;
    }
    
    int newSize = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != val) {
            nums[newSize] = nums[i];
            newSize++;
        }
    }
    
    return newSize;
}
