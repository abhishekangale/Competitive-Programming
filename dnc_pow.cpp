#include<bits/stdc++.h>
using namespace std;
// function to compute divide and conquer algorithm in O(log(n)) time
long power(int a, int b)
    {
        if(b==0)
            return 1;
        // putting a check to avoid unnecessary recursive calls
        if(a == 0)
            return 0;
        if(b%2 == 0) // b is even
            return power(a*a, b/2);
        else // b is odd
            return a * power(a*a, b/2);
}

int main(){
    int x,y;
    cin >> x >> y;
    // taking input for base and exponent
    cout << power(x,y);
    return 0;
}