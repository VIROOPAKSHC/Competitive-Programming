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

int main(){
    vector<int> a1 = findLeaders({4,7,1,0});
    vector<int> a2=findLeaders({10,22,12,3,0,6});
    for(int i:a1) cout<<i<<" ";
    cout<<endl;
    for(int i:a2) cout<<i<<" ";
    cout<<endl;
}
