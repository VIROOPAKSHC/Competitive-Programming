#include<bits/stdc++.h>
using namespace std;

void bit(){
// Codeforces - Bit++ Problem
  int n;
  cin >> n;
  vector<string> vect;
  for(int i=0;i<n;i++){
    string temp;
    cin>>temp;
    vect.push_back(temp);
  }

  int x=0;
  for(int i=0;i<n;i++){
    if(vect[i][1]=='+'){
      x+=1;
    }
    else{
      x-=1;
    }
  }
  cout<<x<<endl;
}

int main(){
    bit();
    return 0;
}