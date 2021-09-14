#include<bits/stdc++.h>
using namespace std;
#define ll long long

signed main(){
    ll testcases;
    cin >> testcases;
    while (testcases--){
        ll X, Y;
        cin >> X >> Y;
        ll no_of_pairs = (ll)sqrt(X*X - 4*Y);  // pairs of b,c such that 2*a+b+c = X && a*(a+b+c)=Y
        if( no_of_pairs != sqrt(X*X - 4*Y) ){ // check if b+c is an integer
            cout << 0 << '\n';
        }
        else {
            if ( (X - no_of_pairs) % 2 != 0 ){ //if 2*a can be equal to X - (b+c) i.e X - (sqrt(X*X - 4*Y))
                cout << 0 << '\n';
            }
            else {
                cout << no_of_pairs - 1 << '\n';
            }
        }
    }
    return 0;
}