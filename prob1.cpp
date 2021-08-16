#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,a,b;
    cin>>n>>a>>b;

    long long x=a,y=b;
    long long ans=0,ans1=0;
    while(a!=b){
        if(a>b) a/=2;
        else b/=2;
        ans++;
    }
    while(x!=y){
        if(x>=n || y>=n){
            ans1=LLONG_MAX;
            break;
        }
        if(x<y) x*=2;
        else y*=2;
        ans1++;
    }
    if(ans1==LLONG_MAX){
        cout<<2*ans-1;
    }
    else {
        cout<<min(2*ans-1,2*ans1-1);
    }

}