//
//  main.c
//  13-RomanToInteger
//
//  Created by HuangLibo on 2017/8/5.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 Given a roman numeral, convert it to an integer.
 
 Input is guaranteed to be within the range from 1 to 3999.
 */

/*
 http://www.rapidtables.com/math/symbols/roman_numerals.htm
 
 I 1
 V 5
 X 10
 L 50
 C 100
 D 500 
 M 1000
 
 
 9:  IX
 30: XXX
 35: XXXV
 39: XXXIX
 40: XL
 90: XC
 99: XCIX
 900: CM
 999: CMXCIX
 3000: MMM
 3999: MMMCMXCIX
 
 3999 = 1000 + 1000 + 1000 + (-100) + 1000 + (-10) + 100 + (-1) + 10
 
 I II III IV V VI VII VIII XI X

 */

#include <stdio.h>
#include <string.h>

int romanToInt(char* s);
int charToInt(char c);

int main(int argc, const char * argv[]) {
    
    printf("%d\n", romanToInt("I"));
    printf("%d\n", romanToInt("II"));
    printf("%d\n", romanToInt("III"));
    printf("%d\n", romanToInt("IV"));
    printf("%d\n", romanToInt("V"));
    printf("%d\n", romanToInt("VI"));
    printf("%d\n", romanToInt("VII"));
    printf("%d\n", romanToInt("VIII"));
    printf("%d\n", romanToInt("IX"));
    printf("%d\n", romanToInt("X"));
    printf("%d\n", romanToInt("MMMCMXCIX"));
    printf("%d\n", romanToInt("MMMCMXCIX"));
    
    return 0;
}

int romanToInt(char* s) {
    
    int result = 0;
    
    int current;
    int next;
    int sign = 1;
    for (int i = 0; i < strlen(s); ++i) {
        current = charToInt(s[i]);
        next = charToInt(s[i+1]);
        if (next == '\0') {
            result += current;
            continue;
        }
        sign = current < next ? -1 : 1;
        result += sign * current;
    }
    
    return result;
}

int charToInt(char c) {
    switch (c) {
        case 'I':
            return 1;
            break;
        case 'V':
            return 5;
            break;
        case 'X':
            return 10;
            break;
        case 'L':
            return 50;
            break;
        case 'C':
            return 100;
            break;
        case 'D':
            return 500;
            break;
        case 'M':
            return 1000;
            break;
            
        default:
            break;
    }
    return 0;
}
