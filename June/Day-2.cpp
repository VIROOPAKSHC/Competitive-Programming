// Author: Chekuri Viroopaksh
// Day-2 : 13th of June
// Striver's A2Z DSA sheet

#include<bits/stdc++.h>
using namespace std;

bool isPrime(int N){
    for(int i=2;i<(N/2)+1;i++){
        if(N%i==0){
            return false;
        }
    }
    return true;
}

bool isPrime_Stylish(int N){
    for(int i=2;i<int(sqrt(N))+1;i++){
        if(N%i==0){
            return false;
        }
    }
    return true;
}

void recursivePrint(int N){
    if(N==0){
        return;
    }
    cout<<"VIROOPAKSH"<<endl;
    recursivePrint(--N);
}

void Print1toN(int N){
    if(N==0){
        cout<<endl;
        return;
    }
    Print1toN(--N);
    cout<<N+1<<" ";
}

int Sum1toN(int N){
    if(N==1){
        return 1;
    }
    return N+Sum1toN(N-1);
}

int main(){

    cout<<Sum1toN(14)<<endl;
    return 0;
}