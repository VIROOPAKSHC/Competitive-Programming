#include<bits/stdc++.h>
using namespace std;

long long power(int R,int N,int mod){
    if(N==0) return 1;
    long long temp = power(R,N/2,mod) % mod;
    long long result;
    if (N%2==0)
        result=(temp*temp)%mod;
    else
        result = (((temp*temp)%mod)*R)%mod;
    
    return (result+mod)%mod;
}

int nthTermOfGP(int N, int A, int R) {
    // Write your code here.
    int mod = 1000000007;

    long long ans = (static_cast<long long>(A)*power(R,N-1,mod))%mod;
    return static_cast<int>(ans);
}

vector<int> printSeries(int n, int k)
{
    // Write your code here
    vector<int> ans;
    stack<int> st;
    while(n>0){
        ans.push_back(n);
        st.push(n);
        n=n-k;
    }
    ans.push_back(n);
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

void NearLucky(){
    long long int n;cin>>n;
    int count=0;
    while(n){
        if((n%10)==4 || (n%10)==7){
            count++;
        }
        n=n/10;
    }
    if((count/10)==0){
        if(count==7 || count==4){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    NearLucky();
    return 0;
}