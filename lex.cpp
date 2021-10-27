#include<bits/stdc++.h>
using namespace std;

int FindSmallest(int N, int K, vector<int> A){
     vector<int> B(N);
    map<int,int> mp;
    int x=1;
    for(int i=0; i<N; i++){
        if(mp.find(A[i])!=mp.end()) continue;
        else {
            mp[A[i]]=x;
            x++;
            B[x-1]=A[i];
        }
    }
    for(auto i:mp){
        cout << i.first << " " << i.second << '\n';
    }
    reverse(B.begin(),B.end());
    long long st=1;
    long long mod = 1000000007,mul = 100003;
    long long ans=0;
    for(int i=0; i<K; i++){
        st%=mod;
        int ad = B[i]*st;
        ad%=mod;
        ans+=ad;
        ans%=mod;
        st*=mul;
    }
    return ans;
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &i:a)cin >> i;
    cout << FindSmallest(n,k,a);
}