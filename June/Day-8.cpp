// Author - Chekuri Viroopaksh
// Day 8 - 19th June, 2024
// Striver's A2Z DSA Sheet
#include<bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int> vect){
    int n=vect.size();
    vector<int> ans;
    int curr_max=vect[n-1];
    ans.push_back(curr_max);
    for(int i=n-2;i>=0;i--){
        if(curr_max<vect[i]){
            curr_max = vect[i];
            ans.push_back(curr_max);
        }
    }
    return ans;
}

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        
        set<int> s;
        for(int i:nums){
            s.insert({i});
        }
        int prev=-1;
        int c=0,max_count=0;
        int prev_op=-1;
        int first_iter=1;
        for(int i:s){
            if(prev==-1 && first_iter==1){
                prev=i;
                c=1;
                prev_op=-1;
                first_iter=0;
                continue;
            }
            if(((i==prev+1) && (prev_op==1 || prev_op==-1))){
                prev=i;
                prev_op=1;
                c++;
            }
            else if((i==prev-1) && (prev_op==0 || prev_op==-1)){
                prev=i;
                prev_op=0;
                c++;
            }
            else{
                prev=i;
                max_count=max(max_count,c);
                prev_op=-1;
                c=1;
            }
            
        }
        max_count=max(max_count,c);
        return max_count;
    }
};

int main(){
    vector<int> a1 = findLeaders({4,7,1,0});
    vector<int> a2=findLeaders({10,22,12,3,0,6});
    for(int i:a1) cout<<i<<" ";
    cout<<endl;
    for(int i:a2) cout<<i<<" ";
    cout<<endl;
}
