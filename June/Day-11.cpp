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
};
int main(){

    return 0;
}