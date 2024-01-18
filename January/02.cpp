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

int main(){
    roundNumbers();
    return 0;
}