#include<bits/stdc++.h>
using namespace std;

int Sum(int *arr, int n,int num){
    map<int,int> mp;
    int temp = num;
    for(int i=2;i<=(int)sqrt(num);i++){
        while(temp%i==0){
            mp[i]++;
            temp/=i;
        }
    }
    if(temp!=1){
        mp[temp]++;
    }
    int ans=0;
    for(auto i:mp){
        ans+=((i.second)*arr[i.first]);
    }

    return ans;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int num;
    cin>>num;
    cout<<Sum(arr,n,num);
    return 0;
}