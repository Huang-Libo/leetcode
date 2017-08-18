//
//  main.c
//  69-Sqrt(x)
//
//  Created by HuangLibo on 2017/8/17.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 69. Sqrt(x)
 
 Implement int sqrt(int x).
 
 Compute and return the square root of x.
 */

#include <stdio.h>

int mySqrt(int x) {
    if (x < 1) {
        return 0;
    } else if (x < 2) {
        return 1;
    }
    
    int low = 0;
    int high = x;
    int half;
    int y;
    
    do {
        half = (low + high) / 2;
        y = x / half;
        
        if (y < half) {
            high = half;
        } else if (y > half) {
            low = half;
        } else {
            return y;
        }
    } while (high - low > 1 || high - low < -1);
    
    return low;
}

int main(int argc, const char * argv[]) {
    
    int result = mySqrt(65);
    printf("%d\n", result);
    
    return 0;
}


/* 有网友使用了位操作
int mySqrt(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    
    int a = 1;
    int b = 46340;
    
    int t = (a + b) >> 1;
    while(1)
    {
        if (x > t * t)
            a = t;
        else
            b = t;
        
        if (b - a <= 1)
            return (b * b <= x) ? b : a;
        
        t = (a + b) >> 1;
    }
}
*/
