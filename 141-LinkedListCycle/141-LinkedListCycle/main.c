//
//  main.c
//  141-LinkedListCycle
//
//  Created by HuangLibo on 2017/8/20.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 141. Linked List Cycle

 Given a linked list, determine if it has a cycle in it.
 
 Follow up:
 Can you solve it without using extra space?
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode * next;
};

bool hasCycle(struct ListNode * head) {
    
    if (head == NULL) return false;
    
    struct ListNode * slow, * fast;
    slow = head;
    fast = head;
    
    while (slow && fast && fast->next ) {
        fast = fast->next;
        slow = slow->next;
        
        if (fast == slow) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    struct ListNode * head, * current, * newNode;
    current = (struct ListNode *)malloc(sizeof(struct ListNode));
    current->next = NULL;
    head = current;
    
    for (int i = 0; i < 3; ++i) {
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        current->next = newNode;
        current = current->next;
    }
//    current->next = head;
    
    bool result = hasCycle(head);
    printf("%d\n", result);
    
//    struct ListNode * tmp;
//    while (head != NULL) {
//        tmp = head;
//        head = head->next;
//        free(tmp);
//    }
    
    return 0;
}
