/*
Tag: Hash table, Easy, Linked List
Problem Statement: https://leetcode.com/problems/linked-list-cycle/
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
bool hasCycle(ListNode *head) {
    map<ListNode*, int> mp;
    ListNode* ptr=head;
    while(ptr!=NULL){
        mp[ptr]++;
        if(mp[ptr]>=2){
            return true;
        }
        ptr=ptr->next;
    }
    return false;
}