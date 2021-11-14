#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 1000;
    for(int i = 1; i<=n; i++){
        int exp = i*i + i + 41;
        bool isPrime = true;
        for(int j = 2; j*j<=exp; j++){
            if(exp % j == 0){
                isPrime = false;
            }
        }
        if(!isPrime){
            cout << i << " ";
        }
    }
    return 0;
}