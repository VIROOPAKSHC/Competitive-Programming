/*
Tag:Array, 2 Pointers

*/

#include <bits/stdc++.h>
using namespace std;
int longestMountain(vector<int>& arr) {
    if(arr.size()<3){
        return 0;
    }
    int length=1;
    int peak=-1;
    int i=0;
    int maxLen = 0;
    while(i<arr.size()){
        length=1;
        while(i<arr.size()-1 && arr[i]>=arr[i+1]){
            i++;
        }
        cout<<i<<" "<<length<<endl;
        while(i<arr.size()-1 && arr[i]<arr[i+1]){
            i++;
            length++;
            peak = arr[i];
        }
        if(i==arr.size()-1){
            break;
        }
        if(arr[i]==arr[i+1]){
            continue;
        }
        i++;
        while(i<arr.size() && arr[i-1]>arr[i]){
            i++;
            length++;
        }
        i--;
        if(length>=3){
            maxLen=max(maxLen,length);
            peak=-1;
        }
    }
    return maxLen;
}