// Author - Chekuri Viroopaksh
// Day 26 - July 12, 2024
// Leetcode

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int total = 0;
        string high = x>y?"ab":"ba";
        string low = x>y?"ba":"ab";
        string final = removesubstring(s,high);
        total += max(x,y) * (int(s.size()-final.size())/2);
        string final2 = removesubstring(final,low);
        total += min(x,y) * (int(final.size()-final2.size())/2);
        return total;
    }
    string removesubstring(string s, string a){
        stack<char> st;
        for(auto i:s){
            if(i==a[1] && !st.empty() && st.top()==a[0]){
                    st.pop();
            }
            else{
                st.push(i);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int numSpecialEquivGroups(vector<string>& words) {
        int n = words.size();
        unordered_set<string>s;
        for(int i=0;i<n;i++){
            string even = "";
            string odd = "";
            string s1 = words[i];
            for(int i=0;i<s1.size();i++){
                if(i%2 == 0){
                    even += s1[i];
                }
                else{
                    odd += s1[i];
                }
            }
            sort(even.begin(),even.end());
            sort(odd.begin(),odd.end());
            string ans1 = even+odd;
            s.insert(ans1);
        }
        return s.size();
    }
};

int main(){
    return 0;
}