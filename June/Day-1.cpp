// Author: Chekuri Viroopaksh
// Day 1 - 12th of June
// Striver's A2Z DSA Sheet

// Some STL Containers and Algorithms

#include<bits/stdc++.h>
using namespace std;

void CountDigits(int N){
    // Given an integer count the number of digits in the number
    int c = log10(N);
    c = c+1;
    cout<<"Number of digits in "<<N<<" is "<<c<<endl;
    // O(1) computation
}

class Solution {
public:
    int reverse(int x) {
        // Leetcode - Reverse Integer - Medium problem
        int neg = 0;
        if(x<0){
            neg = 1;
            if((x+1)*(-1) == 2147483647){
                return 0;
            }
            x = x * (-1);
        }
        int neww = 0;
        while(x){
            neww = neww*10 + (x%10);
            x = x/10;
            if((neww >= 214748364) && (x>=7)){
                return 0;
            }
            if((neww >= 214748365) && (x)){
                return 0;
            }
        }
        
        if(neg){
            
            neww = -1*neww;
        }
        return neww;
    }

    bool isPalindrome(int x) {
        // Leetcode - IsPalindrome Problem
        if(x<0){
            return false;
        }
        vector<int> v;
        while(x){
            v.push_back(x%10);
            x=x/10;
        }
        int n=v.size();
        for(int i=0;i<n;i++){
            if(v[i] != v[n-i-1]){
                return false;
            }
        }
        return true;
    }

    bool isPalindrome_Stylish(int x) {
        std::string strX = std::to_string(x);
        return strX == std::string(strX.rbegin(), strX.rend());
    }

    int findGcd(int a, int b) {
        // Continue loop as long as both
        // a and b are greater than 0
        while(a > 0 && b > 0) {
            // If a is greater than b,
            // subtract b from a and update a
            if(a > b) {
                // Update a to the remainder
                // of a divided by b
                a = a % b;
            }
            // If b is greater than or equal
            // to a, subtract a from b and update b
            else {
                // Update b to the remainder
                // of b divided by a
                b = b % a; 
            }
        }
        // Check if a becomes 0,
        // if so, return b as the GCD
        if(a == 0) {
            return b;
        }
        // If a is not 0,
        // return a as the GCD
        return a;
    }
    bool isArmstrong(int N){
        int sum=0;
        int NN = N;
        vector<int> v;
        while(NN){
            v.push_back(NN%10);
            NN = NN/10;
        }
        int n=v.size();
        for(int i:v){
            sum += pow(i,n);
        }
        return sum==N;
    }
};

int main(){
    unordered_set<string> names;
    names.insert("Viroopaksh");
    names.insert("Rajaan");
    names.insert("Anbu");
    cout<<"Printing the elements of unordered set : ";
    for(auto a:names){
        cout<<a<<" ";
    }
    cout<<endl;
    cout<<names.count("Rajaan")<<" indicating element is present"<<endl; // Returns 1 if element is present else 0
    cout<<names.count("Viroo")<<" indicating the element is not present"<<endl;

    if(names.find("Viroopaksh")!=names.end()){
        cout<<"Viroopaksh is present"<<endl;
    }

    names.clear();

    
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(-3);
    s.insert(0);
    cout<<"Printing the elements : ";
    for(auto a:s){
        cout<<a<<" ";
    }
    cout<<endl;

    // Similar functions as unordered_set.

    cout<<"First element using cbegin : "<<*s.cbegin()<<endl;
    cout<<"Ending element using cbegin : "<<*(s.cend())<<endl; // Theoretical element after the last element of the set.

    cout<<"Ending element using rbegin : "<<*s.rbegin()<<endl;
    cout<<"First element using rend : "<<*s.rend()<<endl;
    
    CountDigits(4502);

    cout<<endl;

    Solution* solution = new Solution;
    cout<<"Is it an armstrong number : "<<solution->isArmstrong(371)<<endl;

    return 0;
}