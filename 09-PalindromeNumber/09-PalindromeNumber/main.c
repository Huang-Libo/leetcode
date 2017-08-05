//
//  main.c
//  09-PalindromeNumber
//
//  Created by HuangLibo on 2017/8/5.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 9. Palindrome Number
 Determine whether an integer is a palindrome. Do this without extra space.
 
 Some hints:
 Could negative integers be palindromes? (ie, -1)
 
 If you are thinking of converting the integer to string, note the restriction of using extra space.
 
 You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
 
 There is a more generic way of solving this problem.
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPalindrome(int x);

int main(int argc, const char * argv[]) {
    
    bool result = isPalindrome(1234321);
    printf("result = %d\n", result);
    
    return 0;
}

bool isPalindrome(int x) {
    
    if (x < 0) {
        return false;
    }
    long tmp = x;
    int digitCount = 0;
    while (tmp > 0) {
        digitCount++;
        tmp /= 10;
    }
    
    if (digitCount <= 1) {
        return true;
    }
    
    int high = 0;
    int low = 0;
    int currentDigitCount = digitCount;
    int currentIndex = 1;;
    for (int i = 0; i < digitCount / 2; ++i) {
        // pow 操作应该是很耗时的
        currentIndex = (pow(10, (currentDigitCount - 1)));
        low = x % 10;
        high = x / currentIndex;
        if (low != high) {
            return false;
        }
        x = ( x - ( high * currentIndex)) / 10;
        currentDigitCount -= 2;
    }
    
    return true;
}

/* 这个思路真不错, 把取模操作用的很好. 
 (另外有人使用的是先reverse然后和原数作比较, 就完全变成了一个类似于第7题的题目.)
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    if (x < 10)
        return true;
    if (x == 10)
        return false;
    
    int n = 1000000000;
    while(x < n)
        n /= 10;
    int m = 1;
    while(m < n)
    {
        if (((x / n) % 10) != ((x / m) % 10))
            return false;
        n /= 10;
        m *= 10;
    }
    return true;
}
 */
