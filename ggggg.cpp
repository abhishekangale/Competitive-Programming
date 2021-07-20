#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
signed main()
{
    SPEED;   
    int n,i,j;
    cin>>n;
    string s;
    cin>>s;
    int dp[26][n+1];
    for(i=0;i<26;++i)
    {
        for(j=1;j<=n;++j)
        {
            dp[i][j]=j;
        }
    }
    for(i=1;i<=n;++i)
    {
        int count[26]={0};
        for(j=0;j<i;++j)
        {
            count[s[j]-'a']++;
            dp[s[j]-'a'][i-count[s[j]-'a']]=max(dp[s[j]-'a'][i-count[s[j]-'a']],i); 
        }
        for(j=i;j<n;++j)
        {
            count[s[j-i]-'a']--;
            count[s[j]-'a']++;
            dp[s[j]-'a'][i-count[s[j]-'a']]=max(dp[s[j]-'a'][i-count[s[j]-'a']],i); 
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int m;
        char c;
        cin>>m>>c;
        cout<<dp[c-'a'][m]<<endl;
    }
}