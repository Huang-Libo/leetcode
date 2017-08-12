//
//  main.c
//  02-AddTwoNumbers
//
//  Created by HuangLibo on 2017/8/12.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 2. Add Two Numbers

 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 
 两个整数以逆序分别存在链表里, 求这两个数字相加的和, 并用相同的方式存在链表里面. (数字不会以0开头)
 
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * addTwoNumbers(struct ListNode * l1, struct ListNode * l2) {
    
    // 头指针
    struct ListNode * head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode * resultListNode = head;
    
    // 记录是否有进位
    int tmp = 0;
    
    int currentDigit;
    int l1Digit;
    int l2Digit;
    
    // 加上 tmp != 0 以考虑到最高位的进位问题
    while (l1 != NULL || l2 != NULL || tmp != 0) {
        currentDigit = 0;
        
        l1Digit = (l1 == NULL) ? 0 : l1->val;
        l2Digit = (l2 == NULL) ? 0 : l2->val;
        currentDigit = l1Digit + l2Digit + tmp;
        
        // 创建当前的 Node
        struct ListNode * currentNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        currentNode->val = currentDigit % 10;
        currentNode->next = NULL;
        
        resultListNode->next = currentNode;
        resultListNode = resultListNode->next;
        
        // 记录是否有进位.
        tmp = (currentDigit >= 10) ? 1 : 0;
        
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    
    // 输出也不包含头指针
    return head->next;
}

int main(int argc, const char * argv[]) {
    
    // 按照 LeetCode 的规则, 输入的链表不包含头指针
    struct ListNode * l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l1->next->next->next = NULL;
    l1->val = 2;
    l1->next->val = 4;
    l1->next->next->val = 3;
    
    struct ListNode * l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2->next->next->next = NULL;
    l2->val = 5;
    l2->next->val = 6;
    l2->next->next->val = 4;
    
    addTwoNumbers(l1, l2);
    
    struct ListNode * current;
    while ((current = l1) != NULL) {
        l1 = l1->next;
        free(current);
    }
    while ((current = l2) != NULL) {
        l2 = l2->next;
        free(current);
    }
    
    return 0;
}
