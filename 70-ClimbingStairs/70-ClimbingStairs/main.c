//
//  main.c
//  70-ClimbingStairs
//
//  Created by HuangLibo on 2017/8/18.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 70. Climbing Stairs

 You are climbing a stair case. It takes n steps to reach to the top.
 
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 
 Note: Given n will be a positive integer.
 */

#include <stdio.h>

int climbStairs(int n) {
    
    int a, b, c;
    a = 1;
    b = 2;
    c = 0;
    
    if (n == 1) {
        return a;
    } else if (n == 2) {
        return b;
    }
    
    for (int i = 3; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    
    return c;
}

int main(int argc, const char * argv[]) {
    
    int n = 64;
    int result = climbStairs(n);
    printf("%d\n", result);
    
    return 0;
}
