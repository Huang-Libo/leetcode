//
//  main.c
//  01-twoSum
//
//  Created by HuangLibo on 2017/7/31.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target);


int main(int argc, const char * argv[]) {
    int* testArr = (int*)malloc(sizeof(int)*4);
    testArr[0]  = 2;
    testArr[1]  = 7;
    testArr[2]  = 11;
    testArr[3]  = 15;
//    int testArr[] = {2, 7, 11, 15};
    int target = 9;
    
    twoSum(testArr, 4, target);
    //
    //    for (int i = 0; i < 2; ++i) {
    //        printf("%d", result[i]);
    //    }
    
    free(testArr);
    
    return 0;
}


int* twoSum(int* nums, int numsSize, int target) {
    // static int result[] = {0, 0};
    int* result = (int*)malloc(sizeof(int)*2);
    for (int i = 0; i < numsSize - 1; ++i) {
        int firstNum = nums[i];
        for (int j = i + 1; j < numsSize; ++j) {
            int secondNum = nums[j];
            //            printf("firstNum = %d, secondNum = %d, sum = %d\n", firstNum, secondNum, sum);
            if (firstNum + secondNum == target) {
                //                int result[] = {i, j};
                result[0] = i;
                result[1] = j;
                printf("%d, %d\n", i, j);
                return result;
            }
        }
    }
    
    return NULL;
}
