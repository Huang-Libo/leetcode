//
//  main.c
//  14-LongestCommonPrefix
//
//  Created by HuangLibo on 2017/8/5.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 14. Longest Common Prefix

 Write a function to find the longest common prefix string amongst an array of strings.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* longestCommonPrefix(char** strs, int strsSize);

int main(int argc, const char * argv[]) {
    
    char ** strs = (char **)malloc(sizeof(char **) * 3);
    strs[0] = "aa";
    strs[1] = "aaaaaaaa";
    strs[2] = "aaaa";
    printf("result = %s\n", longestCommonPrefix(strs, 3));
    
    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    
    char * commonPrefix = malloc(sizeof(char *) * 1000);
    
    if (strsSize == 0) {
        commonPrefix[0] = '\0';
        return commonPrefix;
    }
    
    int j;
    int position = 0;
    char * str0 = strs[0];
    while (*str0 != '\0') {
        for (j = 1; j < strsSize; ++j) {
            if (*str0 != strs[j][position]) {
                break;
            }
            
        }
        
        if (j != strsSize) {
            break;
        }
        commonPrefix[position++] = *str0;
        str0++;
    }
    
    // 字符串末尾一定要加上这个, 虽然 Xcode 不报错, 但是 提交到 LeetCode 时
    // 会提示某些 TestCase 没通过. 可能是 clang 和 gcc 不太一样吧.
    commonPrefix[position] = '\0';
    return commonPrefix;
}
