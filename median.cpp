/*make sure you change variables names and add unwanted stuff to avoid plagiarism*/
/* To find number of subarrays in given permutation whose median is x*/

#include <bits/stdc++.h>
using namespace std;
int totalsegments(int n, int p[], int m)
{
    map<int,int> mp;
    mp[0]=1;
    bool has=false;
    long long sum=0;
    long long ans=0;
    for (int i=0;i<n;i++) {
        if (p[i]<m)
            sum--;
        else if (p[i]>m)
            sum++;
        if (p[i]==m)
            has=true;
        if (has)
            ans+=mp[sum]+mp[sum-1];
        else
            mp[sum]++;
    }
    return ans;
} 
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int x;
    cin>>x;
    cout<<totalsegments(n,a,x);
    return 0;
}
