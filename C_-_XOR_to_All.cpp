#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int zero[31][3000006];
int one[31][3000005];
int a[3000005];
int main(){
    int n,q,l,r,x;
    cin >> n;
    ll sum = 0;
    for(int i=0;i<n;i++) cin >> a[i], sum+= a[i];
    
    for(int i=0;i<31;i++){
        int co=0,cz=0;
        for(int j=0;j<n;j++){
            if((a[j] & (1 << i))>0) co++;
            else cz++;
            zero[i][j]=cz;
            one[i][j]=co;
        }
    }
    
    for(int t=0;t<n;t++){
            l = 1, r = n;
            x = a[t];
            l--;r--;
            ll ans=0;
            ll lol = 0;
            for(int i=0;i<31;i++){
                if((x & (1 << i))>0){
                    if(l>0) ans+=(1ll*(zero[i][r]-zero[i][l-1])*(1<<i));
                    else ans+=(1ll*(zero[i][r])*(1<<i));
                }
                else{
                    if(l>0) ans+=(1ll*(one[i][r]-one[i][l-1])*(1<<i));
                    else ans+=(1ll*(one[i][r])*(1<<i));
                }
            }
            sum = max(sum, ans);
        }
    cout << sum;
}