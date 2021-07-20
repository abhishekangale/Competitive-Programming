#include<bits/stdc++.h>
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
using namespace std;

int main(){
    fast
    string s;
    cin>>s;
    ll c=0;
    for(ll i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i])
        c++;
    }
    if(c==0&&s.size()==1){
        cout<<"YES\n";
        return 0;
    }
    if(c==1){
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    
}