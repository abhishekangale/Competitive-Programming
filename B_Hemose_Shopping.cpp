 #pragma GCC optimize("Ofast")
// #include<bits/stdc++.h>
// using namespace std;
// using ll=long long int;using fl=float;using dl=double long;
// #define F first
// #define S second
// #define pb push_back
// #define eb emplace_back
// #define fo(x,start,end) for(ll x=start;x<end;++x)
// #define rfo(x,start,end) for(ll x=start;x>=end;x--)
// #define eif else if
// #define all(v) v.begin(), v.end()
// #define nl '\n'
// #define Try ios_base::sync_with_stdio(0);
// #define Until_You_Die cin.tie(0); cout.tie(0);
// #define YES cout << "YES\n";
// #define NO cout << "NO\n";
// #define gl(s) getline(cin,s);
// #define pf push_front
// #define mp make_pair
// #define ins insert
// #define tc ll t; cin >> t; while(t--)
// const ll M = 1e9+7;

// void solution(){
//   tc{
 
//       ll n,k,N,,countkabeta=0; cin >> n >> k; N=n; vector<ll> v(n); fo(i,0,n) cin >> v[i]; 
//       if(n==1){ YES continue; }
//     if(k>=n){ NO continue; }

 
//     ll foo=n-k;
//     if(k<=n/2){ YES continue; }
 
//     if(is_sorted(all(v))){ YES continue; }
 
//     vector<ll> temp;

 
//     fo(i,0,foo) temp.pb(v[i]);

//     // for(auto i: temp) cout << i << ' ';
//      // cout << nl;
 
//     rfo(i,n-1,k) temp.pb(v[i]);
 
//      // for(auto i: temp) cout << i << ' ';
//      // cout << nl;

//     // n--;
//     // while(1){
//     //     temp.pb(v[n]);
//     //     count++; n--;
//     //     if(count==foo) break;
//     // }

//     // n=N;
//     // n--;
 
//     sort(all(temp));

 
//       // for(auto i: temp) cout << i << ' ';
//      // cout << nl;


//     fo(i,0,foo) v[i]=temp[i];
 
 
//      // for(auto i: v) cout << i << ' ';
//      // cout << nl;
 
//   int kk=0;
//    for(ll i=n-k;i<n;i++){
//     v[i]=temp[k+kk++];
//   }
 
//      // for(auto i: v) cout << i << ' ';
//      // cout << nl;

//     fo(i,0,v.size()-1) if(v[i]<=v[i+1]) countkabeta++;
 
//     //cout << countkabeta << nl;

//     if(countkabeta==N-1) YES
//     else NO
 
//   }
// }
   
// int main(){
//  Try Until_You_Die
//  solution();   
//  return 0;
// }






 #pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;using fl=float;using dl=double long;
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define fo(x,start,end) for(ll x=start;x<end;++x)
#define rfo(x,start,end) for(ll x=start;x>=end;x--)
#define eif else if
#define all(v) v.begin(), v.end()
#define nl '\n'
#define Try ios_base::sync_with_stdio(0);
#define Until_You_Die cin.tie(0); cout.tie(0);
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define gl(s) getline(cin,s);
#define pf push_front
#define mp make_pair
#define ins insert
#define tc ll t; cin >> t; while(t--)
const ll M = 1e9+7;
 
void solution(){
  tc{
 
    ll n,k,N; cin >> n >> k; N=n; vector<ll> v(n); fo(i,0,n) cin >> v[i]; 
    if(n==1){ YES continue; }
    if(k>=n){ NO continue; }
 
 
    //ll foo=n-k;
    if(k<n/2){ YES continue; }
 
    if(is_sorted(all(v))){ YES continue; }
 
    vector<ll> temp;

    k=n-k;
 
    for(ll i=0;i<k;i++) temp.pb(v[i]);
 
    for(ll i=n-1;i>n-k-1;i--) temp.pb(v[i]);
 
    sort(all(temp));
 
    fo(i,0,k) v[i]=temp[i];
 
    int kk=0;
     for(ll i=n-k;i<n;i++){
     v[i]=temp[k+kk];
     kk++;
    }

    for(auto i:v) cout << i << ' ';
    cout << nl;
 
    if(is_sorted(all(v))) YES
    else NO
 
  }
}
   
int main(){
 Try Until_You_Die
 solution();   
 return 0;
}