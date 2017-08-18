//
//  main.c
//  66-PlusOne
//
//  Created by HuangLibo on 2017/8/18.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 66. Plus One

 Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 
 You may assume the integer do not contain any leading zero, except the number 0 itself.
 
 The digits are stored such that the most significant digit is at the head of the list.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int * plusOne(int * digits, int digitsSize, int * returnSize) {
    int * result = (int *)malloc(sizeof(int) * (digitsSize + 1));
    *returnSize = digitsSize;
    
    if (digits[digitsSize-1] < 9) {
        digits[digitsSize-1] += 1;
        *returnSize = digitsSize;
        return digits;
    }
    
    result[digitsSize] = 0;
    // 进位
    int carry = 1;
    int tmp = 0;
    
    for (int i = digitsSize - 2; i >= 0; --i) {
        tmp = digits[i] + carry;
        result[i+1] = tmp % 10;
        carry = (tmp == 10) ? 1 : 0;
        tmp = 0;
    }
    
    if (carry == 1) {
        result[0] = 1;
        *returnSize = digitsSize + 1;
        return result;
    } else {
        result = result + 1;
        return result;
    }
}

int main(int argc, const char * argv[]) {
    
    int * digits = (int *)malloc(sizeof(int) * 10);
    digits[0] = 9;
    digits[1] = 9;
    digits[2] = 9;
    
    int * size = (int *)malloc(sizeof(int));
    int digitsSize = 3;
    int * result = plusOne(digits, digitsSize, size);
    
    for (int i = 0; i < *size; ++i) {
        printf("%d\n", result[i]);
    }
    
    
    free(digits);
    free(size);
    if (digitsSize == *size) {
        free(--result);
    } else {
        free(result);
    }
    
    return 0;
}
