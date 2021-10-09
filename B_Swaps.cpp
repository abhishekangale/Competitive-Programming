#include<bits/stdc++.h>
using namespace std;
int main(){
  int tt;
  cin >> tt;
  while(tt--){
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for(auto &i : a)cin >> i;
    for(auto &i : b)cin >> i;
    int ans = INT_MAX;
    for(int i=0; i<n; i++){
      int oper = i;
      int j;
      for(j=0; j<n; j++){
        if(b[j] > a[i]) break;
      }
      oper = oper + j;
      ans = min (ans , oper);
    }
    cout << ans << '\n';
  }
}