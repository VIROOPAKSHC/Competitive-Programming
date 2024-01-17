#include<bits/stdc++.h>
#include<string>
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

// typedef long long int ll; 
void chewbacca(){
    string n;
    cin>>n;
    string new_string="";
    for(int i=0;i<n.size();i++){
        int a=(n[i]-'0');
        if(a>=5){
            if((i==0)){
                if(a<9){new_string+=to_string(9-a);}
                else{new_string+=n[i];}
            }
            else{
                new_string+=to_string(9-a);
            }
        }
        else{
            new_string+=n[i];
        }
    }
    cout<<new_string<<endl;
}


int main(){
    
    return 0;
}