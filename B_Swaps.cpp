#include<bits/stdc++.h>
using namespace std;
int main(){
  int tt=1;
  // cin >> tt;
    while(tt--){
    int n;
    cin >> n;
    int arr[n];
    for(auto& i:arr) cin>>i;
    int adj=0;
    int ans=0;
    int s=0;
    for(int i=0;i<n-1;i++){
        s+=arr[i]-arr[i+1];
        if(s<0){
            ans+=-s;
            s=0;
            }
    }
    if(ans<arr[0])
        ans=arr[0];
    cout<<ans;
  }
}