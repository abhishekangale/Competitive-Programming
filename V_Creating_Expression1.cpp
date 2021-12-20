#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define nl '\n'
#define tc ll t;cin>>t;while(t--)

bool found = 0;

void find(int i, vector<int> &v, int sum, int k){
    cerr << sum << '\n';
    if(i == v.size()){
        if(sum == k) found = 1;
        return;
    }
    
    sum+=v[i];
    find(i+1, v, sum, k);
    sum-=v[i];
    find(i+1, v, sum, k);

}

void solution(){
  
  int n, k; cin >> n >> k;
  vector<int> v(n);
  for(auto &i: v) cin >> i;
  int sum = v[0];
  find(1, v, sum, k);
    if(found) cout << "YES";
    else cout << "NO";
}
   
int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
solution();   
return 0;
}