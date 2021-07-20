#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define m 1000000007
  
// Function to return the GCD of given numbers
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
  
// Recursive function to return (x ^ n) % m
ll modexp(ll x, ll n)
{
    if (n == 0) {
        return 1;
    }
    else if (n % 2 == 0) {
        return modexp((x * x) % m, n / 2);
    }
    else {
        return (x * modexp((x * x) % m, (n - 1) / 2) % m);
    }
}
  
// Function to return the fraction modulo mod
ll getFractionModulo(ll a, ll b)
{
    ll c = gcd(a, b);
  
    a = a / c;
    b = b / c;
  
    // (b ^ m-2) % m
    ll d = modexp(b, m - 2);
  
    // Final answer
    ll ans = ((a % m) * (d % m)) % m;
  
    return ans;
}
  
// Driver code
int main()
{
    
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
        if(abs(getFractionModulo(i,j)-616319451)<=1000) cout<<i<<" "<<j<<'\n';
        }
    }
    cout<<getFractionModulo(715,576)<<'\n';
    return 0;
}