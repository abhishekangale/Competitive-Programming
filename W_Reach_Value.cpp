#include<bits/stdc++.h>
#define pb push_back
#define ve vector 
using namespace std;
#define FI0  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
 const int  N= 1e5+5;
 bool f = 0;
  void byrecusrion(long long n)
  {
    if(n==1)
    {
        f = 1;
        return;
    }
    if(n==0) return;


    if(n%20==0)
    {
       byrecusrion(n/20); 
    }
    if(n%10==0)
    {
        byrecusrion(n/10);
    }
  }
 



int main(){
 

 
 FI0 
 
 
//  #ifndef ONLINE_JUDGE

//     // For getting input from input.txt file
//     freopen("inputf.in", "r", stdin);

//     // Printing the Output to output.txt file
//     freopen("outputf.in", "w", stdout);
//     #endif

    int t;
    cin>>t;
    while(t--)
      { 
        long long n;
        cin>>n;
         byrecusrion(n);
         if(f) cout <<"YES\n";
         else cout << "NO\n";
            f=0;
      }

}