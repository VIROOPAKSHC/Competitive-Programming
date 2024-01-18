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

void arrival(){
    int n;cin>>n;
    int max_num=-1,min_num=120;
    vector<int> vect;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;max_num=max(max_num,temp);min_num=min(min_num,temp);
        vect.push_back(temp);
    }
    if((vect[0]==max_num) && (vect[n-1]==min_num)){
        cout<<0<<endl;
        return;
    }
    int first_max=n,last_min=-1;
    for(int i=0;i<n;i++){
        if(vect[i]==max_num){
            first_max=min(first_max,i);
        }
        if(vect[i]==min_num){
            last_min=max(last_min,i);
        }
    }
    if(first_max>last_min){
        cout<<first_max+(n-2-last_min)<<endl;
    }
    else{
        cout<<first_max+(n-1-last_min)<<endl;
    }
}

void EasyHard(){
    int n;cin>>n;
    bool flag=true;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        if(temp==1){
            flag=false;
        }
    }
    if(flag)cout<<"EASY"<<endl;
    else cout<<"HARD"<<endl;
}

void presents(){
    int n;
    cin>>n;
    map<int,int> mp;
    vector<int> vect;
    for(int i=1;i<n+1;i++){
        int temp;cin>>temp;
        mp[temp]=i;
    }

    for(int i=1;i<n+1;i++){
        cout<<mp[i]<<" ";
    }
    cout<<endl;
}

int main(){
    presents();
    return 0;
}