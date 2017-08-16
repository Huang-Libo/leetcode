//
//  main.c
//  83-RemoveDuplicatesfromSortedList
//
//  Created by HuangLibo on 2017/8/16.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 83. Remove Duplicates from Sorted List

 Given a sorted linked list, delete all duplicates such that each element appear only once.
 
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode * next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode * next;
 * };
 */
struct ListNode * deleteDuplicates(struct ListNode * head) {
    
    if (head == NULL) {
        return NULL;
    }
    
    struct ListNode * list = head;
    
    // 跳过头指针. (LeetCode 的 TestCase 估计是没有一个不含 val 的 head 指针. 不需要跳)
//    head++;
    
    // 对剩下的节点做循环
    while (head->next) {
        if (head->next->val != head->val) {
            head = head->next;
        } else {
            head->next = head->next->next;
        }
    }
    
    return list;
}

int main(int argc, const char * argv[]) {
    
    struct ListNode * list = (struct ListNode *)malloc(sizeof(struct ListNode) * 10);
    struct ListNode * node = list;
    
    
    // head
    node->next = node + 1;
    node = node->next;
    
    node->val = 1;
    node->next = node + 1;
    node = node->next;
    
    node->val = 2;
    node->next = node + 1;
    node = node->next;
    
    node->val = 2;
    node->next = node + 1;
    node = node->next;
    
    node->val = 2;
    node->next = node + 1;
    node = node->next;
    
    node->val = 4;
    node->next = NULL;
    
    deleteDuplicates(list);
    
    free(list);
    
    return 0;
}
