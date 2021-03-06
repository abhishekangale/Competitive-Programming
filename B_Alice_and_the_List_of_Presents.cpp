#include"bits/stdc++.h"
#include<random>
using namespace std;
typedef long long int ll;
typedef long double ld;

//MACROS
#define ff first
#define ss second
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define readInputFile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define pb push_back
#define eb emplace_back
#define pf push_front
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define mem(a, b) memset(a, (b), sizeof(a))
#define po pop_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define print2d(mat,n,m){for(int i=0;i<(int)(n);i++){for(int j=0;j<(m);j++){cout<<mat[i][j]<<" ";}cout<< endl;}}
#define endl "\n"

typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<pll> vpll;
typedef pair<int, int> pi;
typedef vector<pi> vpii;
typedef map<int,int> mi;
typedef map<ll,ll> mll;
typedef set<ll> sll;

//DEBUG
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second);
cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""),
                          __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
template <typename T>
void print(vector <T> v) {
    for (T i : v) cout << i << " ";
    cout << '\n';
}
 
template <typename T>
void print(vector <vector <T>>& v) {
    for (vector <T>& vv : v) {
        for (T& i : vv)
            cout << i << " ";
        cout << '\n';
    }
}
template <typename T>
void read(vector <T>& v) {for (T& i : v) cin >> i;}
 
template <typename T>
void read(T&& t) {cin >> t;}
 
template <typename T, typename... Args>
void read(T&& t, Args&&... args)
{
    cin >> t;
    read(forward<Args>(args)...);
}
 
template <typename T>
void print(T&& t) {cout << t << '\n';}
 
template <typename T, typename... Args>
void print(T&& t, Args&&... args)
{
    cout << t << " ";
    print(forward<Args>(args)...);
}

// FUNCTIONS FOR UTITLITIES

bool isprime(ll n){
    if(n<=1){return false;}
    if(n<=3){return true;}
    if(n%2==0||n%3==0){return false;}
    for(ll i=5;i*i<=n;i+=6){
        if(n%i==0||n%(i+2)==0){return false;}
    }
    return true;
}


// const ld pie = 3.14159265358979323846;
 //const ll mod = 998244353;


bool check_palin(ll n){
	ll h = n;
	ll rev =0;
	while(n){
		rev = (rev*10)+ n%10;
		n/=10;
	}
	return (h==rev);
}



int lcm(int a, int b)
{
	return (a * b) / __gcd(a, b);
}

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll n, ll mod){
    return binpow(n,mod-2,mod);
}
ll comb(ll n, ll r, ll p, vector<ll>& fac) {
    if (r == 0 or n == r)
        return 1;
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

ll fact(ll n){
	ll res =1;
	for(ll i=1;i<=n;i++){
		res *=  i;
	}
	return res;
}


ll C(ll n,ll r){
	ll res =1;
	for(ll i=0;i<r;i++){
		res = res * (n-i) / (i+1);
	}
	return res;
}


// n<=10 -- O(N!) O(N^7) O(N^6)
// n<20 -- O(2^N) o(N^5)
// n<=80 -- O(N^4)
// n<=400 -- O(N^3)
// n<=7500 -- O(N^2)
// n<=10^4 -- O(Nsqrt(N))
// n<=10^5 -- O(NlogN)
// n<=10^6 -- O(N)
// n<=10^18 -- O(logN) O(1)


ll sodstring (string s){
	ll sum =0;
	for(ll i =0;i<s.size();i++){
		sum += (s[i] -'0');
	}
	return sum;
}


ll sod (ll n){
	ll sum =0;
	while(n){
		ll rem = n%10;
		sum += rem;
		n/=10;
	}
	return sum;
}


ll toint(string s){
	ll num =0;
	for(ll i=0;i<s.size();i++){
		num = num* 10 + s[i] -'0';
	}
	return num;
}


sll divisors(ll n){
	sll s;
	for(ll i=1; i*i<=n;i++){
		if(n%i==0){
			s.insert(i);
			s.insert(n/i);
		}
	}
	return s;
}


// vll ans; 
void seive(){
	vector<int> is_prime(100000+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= 100000; i++) {
	    if (is_prime[i]) {
	        for (int j = i * i; j <= 100000; j += i)
	            is_prime[j] = false;
	    }
	}
	// for(int i=2;i<=100000;i++){
	// 	if(is_prime[i])
	// 		ans.pb(i);
	// }
}

map<ll,ll> primeFactors(ll n)  
{  
	map<ll,ll> m;
    while (n % 2 == 0)  
    {  
        m[2]++;
        n = n/2;  
    }  
    for (ll i = 3; i <= sqrt(n); i = i + 2)  
    {  
        while (n % i == 0)  
        {  
            m[i]++; 
            n = n/i;  
        }  
    }    
    if (n > 2)  
        m[n]++;  
    return m;
}
ll mod = 1e9 +7;


void solve(){
	ll n,m;
	cin>>n>>m;
	ll ans =0;
	ans = binpow(2,m,mod)-1;
	ans = binpow(ans,n,mod);
	print(ans);
}

int32_t  main(){
	FAST;
	ll t;
	// cin>>t;
	t =1;
	// seive();
	while(t--){
		solve();
	}
}