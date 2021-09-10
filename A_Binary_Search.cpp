#include<bits/stdc++.h>
 using namespace std;
 
 #define ll long long int
 #define fl float
 #define dl double long
 #define F first
 #define S second
 #define pb push_back
 #define eb emplace_back
 #define lo(x,start,end) for(int x=start;x<end;++x)
 #define eif else if

 // Not Solved
 
 int main(){
   int n,q;
   ll a,b;
   cin >> n >> q;

   vector<pair<ll,ll>> v(n);

   lo(i,0,n) cin >> v[i].F >> v[i].S;

   while(q--){
        string str;
        cin >> str;
        cin >> a >> b;
        pair<ll,ll> pl = {a,b};
        if(str=="lower"){
            // cin >> a >> b;
            auto lb = (lower_bound(v.begin(),v.end(),pl));
            lb--;
            if(lb!=v.end()){
                cout << (lb-v.begin()) <<'\n';
            }
            else {
                cout << -1 <<'\n';
            }
        }
        // {a,b,c} -> {},{a},{b},{c},{}
        eif(str=="upper"){
        //  cin >> a >> b;
            auto ub = (upper_bound(v.begin(),v.end(),pl));
            if(ub!=v.end()){
                cout << (ub-v.begin()) <<'\n';
            }
            else {
                cout << -1 <<'\n';
            }
        }
        eif(str=="find"){
            // cin >> a >> b;
            if(binary_search(v.begin(),v.end(),pl)){
                cout<<"found\n";
            } else {cout<<"not found\n";}
        }

   }

 }