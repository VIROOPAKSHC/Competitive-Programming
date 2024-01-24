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


int main(){
    return 0;
}