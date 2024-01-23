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

class Deque
{
public:
    // Initialize your data structure.
    vector<int> vect;
    int size;
    Deque(int n)
    {
        // Write your code here.
        size=n;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if(isFull()){
            return false;
        }
        
        if(!isEmpty()){
            vect.push_back(vect[vect.size()-1]);
        
            for(int i=vect.size()-2;i>=0;i--){
                vect[i+1]=vect[i];
            }
            vect[0]=x;
        }
        else{
            vect.push_back(x);
        }        
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if(isFull()){
            return false;
        }
        // Write your code here.
        vect.push_back(x);
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(isEmpty()){
            return -1;
        }
        int temp=getFront();

        for(int i=0;i<vect.size()-1;i++){
            vect[i]=vect[i+1];
        }
        vect.pop_back();
        return temp;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {

        if(isEmpty()){
            return -1;
        }
        // Write your code here.
        int temp=getRear();
        vect.pop_back();
        return temp;

    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        // Write your code here.
        return vect[0];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()){
            return -1;
        }
        // Write your code here.
        return vect[vect.size()-1];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(vect.size()==0){
            return true;
        }
        return false;
        // Write your code here.
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if(size == vect.size()){
            return true;
        }
        return false;
        // Write your code here.
    }
};


void toh(int n, int src, int aux, int dest, vector<vector<int>> &ans)
{
   if(n==0)
   {
       return ;
   }
   toh(n-1, src, dest, aux,ans);
   ans.push_back({src, dest});
   toh(n-1, aux, src, dest,ans);
}
vector<vector<int>> towerOfHanoi(int n)
{
   vector<vector<int>> ans;
   toh(n, 1, 2, 3, ans);
   return ans;
}

int main(){

    return 0;
}
