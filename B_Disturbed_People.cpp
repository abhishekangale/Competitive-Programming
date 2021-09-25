#include "bits/stdc++.h"
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define     iOS              ios_base::sync_with_stdio(false); cin.tie(NULL); cout << fixed << setprecision(15);
#define     MOD              1000000007
#define     MOD1             998244353
#define     INF              1e18
#define     ln               "\n"
#define     eb               emplace_back
#define     pb               push_back
#define     ppb              pop_back
#define     mp               make_pair
#define     ff               first
#define     ss               second
#define     PI               3.141592653589793238462
#define     set_bits         __builtin_popcountll
#define     sz(x)            ((int)(x).size())
#define     all(x)           (x).begin(), (x).end() //Forward traversal
#define     rall(x)          (x).rbegin(), (x).rend() //reverse traversal
#define     mem(a, b)        memset(a, (b), sizeof(a))
#define     tr(c,i)          for(__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define     present(c,x)     ((c).find(x) != (c).end())

typedef long long ll; typedef unsigned long long ull; typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

/*---------------------------------------------------------------------------------------------------------------------------*/
// Use math snippet here
/*--------------------------------------------------------------------------------------------------------------------------*/
  vector<ll>v;
void solve(vector<ll>&index) {
    int i, j, k, n, m;
    int count=0;
    for(i=0;i<(int)index.size();i++){
        if( v[index[i]-1]!=0&& v[index[i]+1]!=0){
        v[index[i]-1]=0;
         v[index[i]+1]=0;
         count++;
        }


    }
    cout<<count;
}

int main() {
    int t = 0; cin >> t;
  
     vector<ll>index;
    for(int tt = 0; tt < t; tt++) {
        ll x;
        cin>>x;
        v.pb(x);
        if((x==0)&&(tt!=t-1)&&(t!=0))index.push_back(tt);
       
    }
     solve(index);
   // solve();
}

