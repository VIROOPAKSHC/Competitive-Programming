// Author - Chekuri Viroopaksh
// Day 15 - 28, June, 2024
// Striver's A2Z DSA sheet

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void bitManipulation(int num, int i) {
        // your code here
        int s = 0;
        int n1 = num;
        vector<int> ans;
        vector<int> v;
        i--;
        while(i!=0){
            v.push_back(n1%2);
            n1=n1/2;
            i--;
        }
        ans.push_back(n1%2);
        int n2 = n1;
        int k = v.size()-1;
        if(n1%2==0){
            n1 = n1+1;
            while(k>=0){
                n1=n1*2+v[k];
                n2=n2*2+v[k];
                k--;
            }
            ans.push_back(n1);
            ans.push_back(n2);
        }
        else{
            n1 = n1-1;
            while(k>=0){
                n1=n1*2+v[k];
                n2=n2*2+v[k];
                k--;
            }
            ans.push_back(n2);
            ans.push_back(n1);
        }
        cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2];
    }
};

int main(){
vector<int> v;
    return 0;
}