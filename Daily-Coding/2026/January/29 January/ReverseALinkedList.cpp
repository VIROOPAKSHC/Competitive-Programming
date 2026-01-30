/*
Tag: Easy, LinkedList, Recursion
Problem Statement: https://leetcode.com/problems/reverse-linked-list
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


ListNode* reverseList(ListNode* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }

    ListNode* reversed = reverseList(head->next);
    head->next->next = head;
    head->next=NULL;
    return reversed;
}