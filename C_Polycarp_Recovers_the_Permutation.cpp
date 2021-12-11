#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
void solve(int a[],int n)
{
    int i=0,j=n-1;
    deque<int>dq;
    while(i<j)
    {
        if(a[i]>a[j])
        {
            dq.push_back(a[j]);
            j--;
        }
        else
        {
            dq.push_front(a[i]);
            i++;
        }
    }
    for (auto it = dq.begin(); it != dq.end(); ++it)
        cout << *it << " ";
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,maxe=INT_MIN; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            maxe=max(maxe,a[i]);
        }
        if(maxe==a[0] || maxe==a[n-1])
        {
            solve(a,n);
            cout <<maxe<<'\n';
        }
        else
        {
            cout<<"-1"<<'\n';
        }
    }
return 0;
}