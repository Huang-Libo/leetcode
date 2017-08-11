//
//  main.c
//  28-Implement-strStr()
//
//  Created by HuangLibo on 2017/8/11.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 28. Implement strStr()

 Implement strStr().
 
 Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char * haystack, char * needle);

int main(int argc, const char * argv[]) {
    
    char * haystack = (char *)malloc(sizeof(char) * 100);
    char * needle = (char *)malloc(sizeof(char) * 10);
    
    strcpy(haystack, "AGCTAACTGAACTCGCGAT");
    strcpy(needle, "GAA");
    
    int result = strStr(haystack, needle);
    printf("result = %d\n", result);
    
    free(haystack);
    free(needle);
    
    return 0;
}

// 跑完七十多个 TestCase 费时 700ms
int strStr(char * haystack, char * needle) {
    
    size_t haystackLength = strlen(haystack);
    size_t needleLength = strlen(needle);
    
    // 这包含了 haystackLength 为 0 但 needleLength 大于 0 的情况
    if (needleLength > haystackLength) {
        return -1;
    }
    
    if (haystackLength == 0 || needleLength == 0) {
        return 0;
    }
    
    for (int i = 0; i < haystackLength; ++i) {
        int j;
        for (j = 0; j < needleLength; ++j) {
            if (needle[j] != haystack[i + j]) {
                break;
            }
        }
        if (j == needleLength) {
            return i;
        }
    }
    
    return -1;
}

/* 有的网友用 hash 来解决的. 在适当的情况下才使用 strncmp 函数
 总共只需要 9ms, 还是很快的.
 
#define PRIME 31

int compute_hash (char *str, int idx, int len, int h)
{
    int i = 0, hash = 0;
    
    
    if (idx) {
        hash = ( (h - str[idx-1]) / PRIME ) + (str[idx+len-1] * pow(PRIME, len-1));
    } else {
        while (i < len) {
            hash = hash + (str[i] * pow(PRIME, i));
            i++;
        }
    }
    
    return (hash);
}

int strStr (char *txt, char *pat)
{
    int i = 0, ret = -1;
    int thash = 0, phash = 0;
    int tlen = strlen(txt), plen = strlen(pat);
    
    if (!txt || !pat) {
        return (-1);
    }
    
    phash = compute_hash(pat, 0, plen, phash);
    thash = compute_hash(txt, 0, plen, thash);
    
    while (i < tlen-plen+1) {
        if (thash == phash) {
            if (strncmp(txt+i, pat, plen) == 0) {
                ret = i;
                break;
            }   
        }   
        
        i++;
        thash = compute_hash(txt, i, plen, thash);
    }
    
    return (ret);
}
*/

/* 有人直接用了库函数 strncmp, 所用空间是普通解法的十倍
int strStr(char* haystack, char* needle) {
    int len1 = strlen(haystack), len2 = strlen(needle), i = 0;
    for(i = 0; i <= len1 - len2; i++)
    {
        if(strncmp(haystack+i, needle, len2) == 0) return i;
    }
    return -1;
}
*/
