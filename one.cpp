#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;
    int n = s.size();
    unordered_map<char,int> mp;

    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    int mx=0;
    for(auto i:mp){
        mx = max(mx,i.second);
    }
    for(auto i:mp){
        if(i.second==mx){
            cout<<i.first<<" "<<i.second<<"\n";
            break;
        }
    }

    return 0;
}