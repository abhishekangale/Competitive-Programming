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
   #define nline '\n'
   #define Try ios_base::sync_with_stdio(0);
   #define Until_You_Die cin.tie(0);
   #define YES cout << "YES\n";
   #define NO cout << "NO\n";
   #define gl(s) getline(cin,s);
   #define pf push_front
   #define mp make_pair
   #define vi vector<int>
   #define tc ll t; cin >> t; while(t--)
   const ll M = 1e9+7;

   void primeFactors(ll n, vector<ll> &v){
     for(ll i=2;i<=sqrt(n);i++) while(n%i==0){ v.eb(i); n/=i; } if(n>1) v.eb(n); 
   }
    
   void solution(){

      tc{
          ll n,a,b,sum=0,isOdd=0,isEven=0; cin >> n >> a >> b;
          vector<ll> v;
          primeFactors(n,v);

          for(auto i:v){
              if(i&1) isOdd++;
              else isEven++;
          }
        
        if(a>=0 && b>=0){
            for(auto i:v){ if(i&1) sum+=b; else sum+=a; }
            cout << sum << nline;
        }
        eif(a<0 && b<0){
           if(n&1) cout << b << nline;
           else cout << a << nline;
        }
        eif(a>=0 && b<0){
           if(isOdd){if(!isEven) cout << isEven*a + b << nline; else cout << isEven*a << '\n';}
           else cout << isEven*a << nline;
        }
        eif(a<0 && b>=0){
            if(isEven){ cout << isOdd*b + a << nline; }
            else cout << isOdd*b << nline;
        }

      }
   }
      
   int main(){
  
     Try Until_You_Die
     solution();   
     return 0;
     
   }