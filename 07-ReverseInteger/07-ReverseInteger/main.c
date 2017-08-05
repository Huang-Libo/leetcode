//
//  main.c
//  07-ReverseInteger
//
//  Created by HuangLibo on 2017/7/31.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/* 
 07
 Reverse digits of an integer.
 
 Example1: x = 123, return 321
 Example2: x = -123, return -321
 
 Note:
 The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
 */

#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

int reverse(int x);

int main(int argc, const char * argv[]) {
    
    int test = -147483412;
    int result = reverse(test);
    printf("result = %d\n", result);
    
    return 0;
}

int reverse(int x) {
    
    int sign = x > 0 ? 1 : -1;
    x = x > 0 ? x : -x;
    int y = 0;
    while (x != 0) {
        
        if (y > INT_MAX / 10 || y < INT_MIN / 10) {
            return 0;
        }
        y = y * 10 + x % 10;
        x = x / 10;
    }
    
    return sign * y;
}

/** 时间和空间复杂度都排第一的结果如下, 这个解决方法用了 long long 来存储结果
这样判断溢出就简单了很多, 看起来有点投机取巧.
 
 int reverse(int x) {
 int sign = x < 0 ? -1: 1;
	x = x < 0 ? -x : x;
 
	long long res = 0;
	while(x > 0)
 {
 int digit = x % 10;
 x /= 10;
 res *= 10;
 res += digit;
 }
 
	if (res > INT_MAX || sign * res < INT_MIN)
 return 0;
 
	return (int32_t)( sign * res );
 }
 */
