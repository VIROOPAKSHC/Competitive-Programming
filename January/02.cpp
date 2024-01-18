#include<bits/stdc++.h>
using namespace std;

typedef long long int ll; 

vector<ll> roundNumbershelp(int number){
    vector<ll> vect;
    ll multiplier=1;
    while(number){
        if(number%10){vect.push_back((number%10)*multiplier);}
        multiplier*=10;
        number=number/10;
    }
    return vect;

}
void roundNumbers(){
    int n;cin>>n;
    vector<vector<ll>> vect;
    for(int i=0;i<n;i++){
        ll a;cin>>a;
        vect.push_back(roundNumbershelp(a));
    }
    
    for(auto v:vect){
        cout<<v.size()<<endl;
        for(int i=v.size()-1;i>=0;i--){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }

}

void foxAndSnake(){
    int n,m;cin>>n>>m;
    bool prev=true;
    for(int i=0;i<n;i++){
        if(i%2!=0){
            if(!prev){
                cout<<"#";
            }
            else{
                cout<<".";
            }
            for(int j=1;j<m-1;j++){
                cout<<".";
            }
            if(prev){
                cout<<"#";
                
            }
            else{
                cout<<".";
            }
            prev=!prev;
        }
        else{
            for(int j=0;j<m;j++){
                cout<<"#";
            }
        }
        cout<<endl;
    }
}

void anton(){
    ll n;cin>>n;
    ll faces=0;
    map<string,int> mp;
    mp["Tetrahedron"]=4;
    mp["Cube"]=6;
    mp["Octahedron"]=8;
    mp["Dodecahedron"]=12;
    mp["Icosahedron"]=20;
    for(ll i=0;i<n;i++){
        string temp;cin>>temp;
        faces+=mp[temp];
    }
    cout<<faces<<endl;
}

int main(){
    anton();
    return 0;
}