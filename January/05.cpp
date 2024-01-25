#include<bits/stdc++.h>
using namespace std;

void petr(){
    int n;cin>>n;
    vector<int> vect;
    for(int i=0;i<7;i++){
        int temp;cin>>temp;
        vect.push_back(temp);
    }
    int i=0;
    while(n){
        if(n<=vect[i]){
            cout<<i+1<<endl;
            return;
        }
        n-=vect[i];
        i=(i+1)%7;
    }
    cout<<i+1<<endl;
    return;

}

void kstring(){
    int k;cin>>k;
    string s;cin>>s;
    map<char,int> mp;
    set<char> st;
    for(auto a:s){
        mp[a]+=1;
        st.insert(a);
    }
    string part="";
    for(set<char, greater<char> >::iterator itr=st.begin();itr!=st.end();itr++){
        if(mp[*itr]%k==0){
            int temp=mp[*itr]/k;
            for(int i=0;i<temp;i++){
                part+=(*itr);
            }
        }
        else{
            part="";
            break;
        }
    }
    if(part==""){
        cout<<-1<<endl;
    }
    else{
        string ans="";
        for(int i=0;i<k;i++){
            ans+=part;
        }
        cout<<ans<<endl;
    }
}

int main(){
    
    return 0;
}