//
//  main.c
//  21-MergeTwoSortedLists
//
//  Created by HuangLibo on 2017/8/9.
//  Copyright © 2017年 Huang Libo. All rights reserved.
//

/*
 21. Merge Two Sorted Lists
 
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

struct ListNode * mergeTwoLists(struct ListNode* l1, struct ListNode* l2);

struct ListNode {
    int val;
    struct ListNode *next;
};

int main(int argc, const char * argv[]) {
    
    struct ListNode * node0 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node0 = NULL;
//    struct ListNode node0;
//    node0.val = 1;
//    
//    struct ListNode node1;
//    node1.val = 3;
//    
//    struct ListNode node2;
//    node2.val = 5;
//    
//    node0.next = &node1;
//    node1.next = &node2;
//    node2.next = NULL;
    
    struct ListNode node10;
    node10.val = -5;
    
    struct ListNode node11;
    node11.val = 1;
    
//    struct ListNode node12;
//    node12.val = 6;
    
    node10.next = &node11;
    node11.next = NULL;
//    node12.next = NULL;
    
    struct ListNode * newListNode = mergeTwoLists(node0, &node10);
    
//    free(listNode1);
//    free(listNode2);
//    free(newListNode);
    
    return 0;
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * newList = (struct ListNode *)malloc(sizeof(struct ListNode));
    newList->next = NULL;
    struct ListNode * head = newList;
    head = newList;
    
    if (l1 == NULL && l2 == NULL) {
        head = NULL;
        return head;
    } else if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    }
    
    struct ListNode * currentNode;
    while (l1 != NULL || l2 != NULL) {
        if (l1 == NULL) {
            currentNode = l2;
        } else if (l2 == NULL) {
            currentNode = l1;
        } else if (l1->val < l2->val) {
            currentNode = l1;
        } else {
            currentNode = l2;
        }
        
        if (currentNode == l1) {
            newList->val = l1->val;
            l1 = l1->next;
        } else {
            newList->val = l2->val;
            l2 = l2->next;
        }
        
        if ((l1 != NULL || l2 != NULL)) {
            struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
            newList->next = newNode;
            newList = newList->next;
            newList->next = NULL;
        }
    }
    
    return head;
}

/* 普通的方式
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL && l2 == NULL)
        return NULL;
    
    struct ListNode* head=NULL, * list=NULL;
    list = malloc(sizeof(struct ListNode));
    list -> next = NULL;
    head = list;
    int a, b;
    while(1){
        a = (l1 == NULL) ? INT_MAX: l1->val;
        b = (l2 == NULL) ? INT_MAX: l2->val;
        if(a < b){
            list->val = l1->val;
            l1 = l1 -> next;
        }
        else{
            list->val = l2->val;
            l2 = l2 -> next;
        }
        if((l1 != NULL) || (l2!=NULL)){
            list -> next = malloc(sizeof(struct ListNode));
            list = list -> next;
            list -> next = NULL;
        }
        else
            break;
    }
    return head;
}
*/

/* 递归的方式解决
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *result;
    if(l1==NULL && l2==NULL) {
        return NULL;
    }
    if(l1==NULL) {
        return l2;
    }
    if(l2==NULL) {
        return l1;
    }
    
    if(l1->val < l2->val) {
        result = l1;
        result->next = mergeTwoLists(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeTwoLists(l1, l2->next);
    }
    return result;
}
*/
