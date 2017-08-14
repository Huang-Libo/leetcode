//
//  main.c
//  58-LengthOfLastWord
//
//  Created by HuangLibo on 2017/8/14.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 58. Length of Last Word
 
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 
 If the last word does not exist, return 0.
 
 Note: A word is defined as a character sequence consists of non-space characters only.
 
 For example,
 Given s = "Hello World",
 return 5.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int lengthOfLastWord(char * s) {
    
    int length = (int)strlen(s);
    
    if (length == 0) {
        return 0;
    }
    
    int result = 0;
    // 从后面开始遍历
    for (int i = length - 1; i >= 0 ; --i) {
        // 如果结尾部分有space, 则跳过
        if (s[i] == ' ' && result == 0) {
            continue;
        }
        if (s[i] != ' ') {
            result++;
        } else {
            break;
        }
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    char * s = malloc(100);
    strcpy(s, " abc abc abc zxcabc ");
    int result = lengthOfLastWord(s);
    printf("result = %d\n", result);
    
    return 0;
}
