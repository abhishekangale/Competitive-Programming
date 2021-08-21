#include<iostream>
#include<string.h>
using namespace std;

string bit_stuffing(string S,int N){
    int counter = 0;
    string stuffed;
    for(int i=0; i<N ;i++){
        if(S[i]=='1'){
            if(counter == 0){
                counter++;
            }
            else {
                if(S[i]==S[i-1] && S[i]=='1'){
                    counter++;
                }
            }
        }
        else {
            counter = 0;
        }
        
        stuffed += S[i];
        if(counter == 5){
            stuffed += '0';
            counter = 0;
        }
    }

    return stuffed;
}


int main() {

    string S;
    cout << "Enter the input bit string:\n";
    cin >> S;
    int N = (int)S.size();
    string stuffed = bit_stuffing(S, N);
    cout << "The stuffed bit string is:\n";
    cout << stuffed << '\n';

    return 0;
}