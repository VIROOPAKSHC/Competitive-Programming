/*
Tag: Linked List, Easy
Problem Statement: https://leetcode.com/problems/remove-linked-list-elements/
*/

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode *curr = head, *prev = NULL; 
    while(curr != NULL){
        // when head element needs to be deleted
        if(curr->val == val && curr == head){
            head = head->next; 
            prev = curr; 
        }
        // when non head element is to be deleted. 
        // prev need not be updated here
        else if (curr->val == val){
            prev->next = curr->next; 
        }
        // If no element is to be deleted
        else{
            prev = curr; 
        }
        // move the curr pointer
        curr = curr->next; 
    }
    return head;
}