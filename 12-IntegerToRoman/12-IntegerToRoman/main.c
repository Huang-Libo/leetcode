//
//  main.c
//  12-IntegerToRoman
//
//  Created by HuangLibo on 2017/8/7.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 12-IntegerToRoman
 
 Given an integer, convert it to a roman numeral.
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
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* intToRoman(int num);
char* romanFromDigit(int digit, int index);

int main(int argc, const char * argv[]) {
    
    char * result = intToRoman(3003);
    printf("result = %s\n", result);
    
    return 0;
}

char* intToRoman(int num) {
    char * roman = malloc(sizeof(char *) * 15);
    
    // 计算num的数量级
    int index = 1;
    for (int tmp = num; tmp >= 10; tmp /= 10) {
        index *= 10;
    }
//    printf("index = %d\n", index);
    int j;
    int currentDigit;
    char * currentRoman = malloc(sizeof(char *) * 5);
    for (j = 0; index > 0; ++j) {
        currentDigit = num / index % 10;
//        sprintf(currentRoman, "%d", currentDigit);
        currentRoman = romanFromDigit(currentDigit, index);
        strcat(roman, currentRoman);
        index /= 10;
    }
        
    return roman;
}

char* romanFromDigit(int digit, int index) {
    char * currentRoman = malloc(sizeof(char *) * 5);
    
    switch (digit) {
        case 0:
            currentRoman[0] = '\0';
            break;
        case 1:
            if (index == 1) {
                currentRoman = "I";
            } else if (index == 10) {
                currentRoman = "X";
            } else if (index == 100) {
                currentRoman = "C";
            } else if (index == 1000) {
                currentRoman = "M";
            }
            break;
        case 2:
            if (index == 1) {
                currentRoman = "II";
            } else if (index == 10) {
                currentRoman = "XX";
            } else if (index == 100) {
                currentRoman = "CC";
            } else if (index == 1000) {
                currentRoman = "MM";
            }
            break;
        case 3:
            if (index == 1) {
                currentRoman = "III";
            } else if (index == 10) {
                currentRoman = "XXX";
            } else if (index == 100) {
                currentRoman = "CCC";
            } else if (index == 1000) {
                currentRoman = "MMM";
            }
            break;
        case 4:
            if (index == 1) {
                currentRoman = "IV";
            } else if (index == 10) {
                currentRoman = "XL";
            } else if (index == 100) {
                currentRoman = "CD";
            }
            break;
        case 5:
            if (index == 1) {
                currentRoman = "V";
            } else if (index == 10) {
                currentRoman = "L";
            } else if (index == 100) {
                currentRoman = "D";
            }
            break;
        case 6:
            if (index == 1) {
                currentRoman = "VI";
            } else if (index == 10) {
                currentRoman = "LX";
            } else if (index == 100) {
                currentRoman = "DC";
            }
            break;
        case 7:
            if (index == 1) {
                currentRoman = "VII";
            } else if (index == 10) {
                currentRoman = "LXX";
            } else if (index == 100) {
                currentRoman = "DCC";
            }
            break;
        case 8:
            if (index == 1) {
                currentRoman = "VIII";
            } else if (index == 10) {
                currentRoman = "LXXX";
            } else if (index == 100) {
                currentRoman = "DCCC";
            }
            break;
        case 9:
            if (index == 1) {
                currentRoman = "IX";
            } else if (index == 10) {
                currentRoman = "XC";
            } else if (index == 100) {
                currentRoman = "CM";
            }
            break;
            
        default:
            break;
    }
    
    return currentRoman;
}

/* 时间和空间都比较省, 并且思路较清晰的一种解法:
char* intToRoman(int num) {
    char *ans;
    ans = (char*)malloc(30*sizeof(char));
    ans[0]='\0';
    int temp;
    int i;
    int k=0;
    if(num >= 1000){
        temp = num/1000;
        num = num%1000;
        for(i=0;i<temp;i++){
            ans[k++] = 'M';
        }
    }
    if(num >= 100){
        temp = num/100;
        num = num%100;
        if(temp<4){
            for(i=0;i<temp;i++){
                ans[k++] = 'C';
            }
        }
        else if(temp == 4){
            ans[k++] = 'C';
            ans[k++] = 'D';
        }
        else if(temp>=5&&temp<=8){
            temp=temp-5;
            ans[k++] = 'D';
            while(temp>0){
                ans[k++] = 'C';
                temp--;
            }
        }
        else{
            ans[k++] = 'C';
            ans[k++] = 'M';
        }
    }
    if(num >= 10){
        temp = num/10;
        num = num%10;
        if(temp<4){
            for(i=0;i<temp;i++){
                ans[k++] = 'X';
            }
        }
        else if(temp == 4){
            ans[k++] = 'X';
            ans[k++] = 'L';
        }
        else if(temp>=5&&temp<=8){
            temp=temp-5;
            ans[k++] = 'L';
            while(temp>0){
                ans[k++] = 'X';
                temp--;
            }
        }
        else{
            ans[k++] = 'X';
            ans[k++] = 'C';
        }
    }
    if(num >= 1){
        temp = num;
        if(temp<4){
            for(i=0;i<temp;i++){
                ans[k++] = 'I';
            }
        }
        else if(temp == 4){
            ans[k++] = 'I';
            ans[k++] = 'V';
        }
        else if(temp>=5&&temp<=8){
            temp=temp-5;
            ans[k++] = 'V';
            while(temp>0){
                ans[k++] = 'I';
                temp--;
            }
        }
        else{
            ans[k++] = 'I';
            ans[k++] = 'X';
        }
    }
    ans[k]='\0';
    return ans;
}
*/
