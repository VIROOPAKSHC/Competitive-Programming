#include<bits/stdc++.h>
#include<string>
using namespace std;

void oddone(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int a,b,c;cin>>a>>b>>c;
        if(a==b){cout<<c<<endl;}
        else if(b==c){cout<<a<<endl;}
        else{cout<<b<<endl;}
    }
}

void latinsquare(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        int pos_x=-1,pos_y=-1;
        vector<vector<char>> matrix;
        for(int a=0;a<3;a++){
            vector<char> v;
            for(int b=0;b<3;b++){
                char c;cin>>c;
                v.push_back(c);
                if(c=='?'){
                    pos_x=a;
                    pos_y=b;
                }
            }
            matrix.push_back(v);
        }
        map<char,int> mp;
        for(int a=0;a<3;a++){
            if(a!=pos_y)
            mp[matrix[pos_x][a]]=1;
        }
        string s="ABC";
        for(auto a:s){
            if(!mp[a]){
                cout<<a<<endl;
                break;
            }
        }
    }
}

typedef long long int ll;
void square(){
int t;cin>>t;
while(t--){
    int n;cin>>n;
    ll s=0;
    for(int i=0;i<n;i++){
        ll temp;cin>>temp;
        s+=temp;
    }
    if(int(sqrt(s))==sqrt(s)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
}

typedef long long int ll;
void unnatural(){
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string s;cin>>s;
        int i=0;
        vector<string> vect;
        while(i<s.size()-2){
            string temp="";
            temp=temp+(s[i]);
            temp=temp+(s[i+1]);
            
            if(s[i+2]!='a' && s[i+2]!='e'){//becomes a consonant
                if(s[i+3]!='a' && s[i+3]!='e'){
                    temp=temp+(s[i+2]);
                    i+=3;
                }
                else{
                    i+=2;
                }
            }
            vect.push_back(temp);
        }
        if(i+1==s.size()-1){
            string temp="";
            temp=temp+s[i];
            temp=temp+s[i+1];
            vect.push_back(temp);
        }
        for(int i=0;i<vect.size()-1;i++){
            cout<<vect[i]<<".";
        }
        cout<<vect[vect.size()-1]<<endl;
    }
}



int main(){
unnatural();
return 0;
}