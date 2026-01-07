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

void beautifulMatrix(){
  int a,b;
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      int temp;
      cin>>temp;
      if(temp==1){
        a=i;
        b=j;
      }
    }
  }
  cout<<abs(2-a)+abs(2-b)<<endl;
}

void softDrinking(){
  int n, k, l, c, d, p, nl, np;
  cin>>n>>k>>l>>c>>d>>p>>nl>>np;
  cout<<min((k*l)/nl,min(c*d,p/np))/n<<endl;
}

void friendsMeet(){
  int a,b,c;
  cin>>a>>b>>c;
  int middle=a+b+c-(min(a,min(b,c))+max(a,max(b,c)));
  cout<<abs(a-middle)+abs(b-middle)+abs(c-middle)<<endl;
  
}

int main(){
    friendsMeet();
    return 0;
}