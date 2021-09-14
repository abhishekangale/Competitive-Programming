#include<bits/stdc++.h>
 using namespace std;
 
 #define ll long long int
 #define fl float
 #define dl double long
 #define F first
 #define S second
 #define pb push_back
 #define eb emplace_back
 #define fo(x,start,end) for(int x=start;x<end;++x)
 #define eif else if
 #define all(v) v.begin(), v.end()

 void solution(){
     int t;
     cin >> t;

     while(t--){
         int n;
         cin >> n;
         int a[n];
         int freq[101]={0};
        
        for(int i=0;i<n;i++){ cin >> a[i]; freq[a[i]]++; }
     
         for(int i=0;i<101;i++){
             if(freq[i]>0){ cout << i << ' '; freq[i]--; }
         }

         for(int i=0;i<101;i++){
           for(int j=0;j<freq[i];j++){
             cout << i <<" ";
           }
        }

         cout << '\n';

     }
 }
 
 int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);
 
   solution();   
 
   return 0;

 }