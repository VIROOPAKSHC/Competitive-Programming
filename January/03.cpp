#include<bits/stdc++.h>
using namespace std;

class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

Node* reverseLinkedList(Node *head)
{
    // Write your code here
    if(head==NULL || head->next == NULL){
        return head;
    }
    Node* newhead=reverseLinkedList(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newhead;
}

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<int> st;
    int curr_count=0;
    for(auto x:s){
        if(x=='('){
            st.push(curr_count);
        }
        else if(x=='+' || x=='-' || x=='*' || x=='/'){
            if(st.empty()){
                continue;
            }
            curr_count=st.top();
            
            st.pop();
            curr_count+=1;
            st.push(curr_count);
            curr_count=0;
        }
        else if(x==')'){
            int a=st.top();
            st.pop();
            if(a==0){
                return true;
            }
        }
    }
    return false;
    
}

bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> st;
    for(auto a:s){
        if(a=='(' || a=='{' || a=='['){
            st.push(a);
        }
        else if(a==')'){
            if(st.empty()){
                return false;
            }
            if(st.top()!='('){
                return false;
            }
            st.pop();
        }
        else if(a==']'){
            if(st.empty()){
                return false;
            }
            if (st.top() != '[') {
                return false;
            }
            st.pop();
        } else if (a == '}') {
            if(st.empty()){
                return false;
            }
            if(st.top()!='{'){
                return false;
            }
            st.pop();
        }
    }
    return true;
}

int main(){

    return 0;
}
