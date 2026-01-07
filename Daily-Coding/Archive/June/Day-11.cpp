// Author - Chekuri Viroopaksh
// Day 11 - 22nd June, 2024
// Striver's A2Z DSA sheet

#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
        
    }
    ListNode* middleNode(ListNode* head) {
        if(head==NULL){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        if(head->next->next == NULL){
            return head->next;
        }
        ListNode* first = head;
        ListNode* second = head;
        while(first->next != NULL && second!=NULL){
            first = first->next;
            
            second = second->next->next;
            if(second==NULL || second->next==NULL){
                break;
            }
        }
        return first;
    }
};
int main(){

    return 0;
}