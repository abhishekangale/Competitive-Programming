# include <bits/stdc++.h>

using namespace std;

int main(){
    int testCases , n ;
    cin >> testCases ;
    while(testCases--){
        cin >> n ;
        int a[n] , b[n] , c[n] , p[n]; 
        for(int i = 0 ; i<n ; i++){
            cin >> a[i] ;
        } 
        for(int i = 0 ; i<n ; i++){
            cin >> b[i] ;
        }
        for(int i = 0 ; i<n ; i++){
            cin >> c[i] ;
        } 
        p[0] = a[0] ;
        cout << p[0] << " " ;
        for(int i = 1 ; i<n-1 ; i++){
            if(a[i] == p[i-1]){
                p[i] = b[i] ;
                cout << p[i] << " " ;
            }
            else {
                p[i] = a[i] ;
                cout << p[i] << " " ;
            }
           
        }
         if((a[n-1] != p[0]) && (p[n-2]!=a[n-1])){
                p[n-1] = a[n-1];
                cout << p[n-1] << " ";
            }
         else if((b[n-1] != p[0]) && (p[n-2]!=b[n-1])){
                p[n-1] = b[n-1];
                cout << p[n-1] << " ";
            }
         else if((c[n-1] != p[0]) && (p[n-2]!=c[n-1])){
                p[n-1] = c[n-1];
                cout << p[n-1] << " ";
            }
        cout << "\n" ;

    }
    return 0;
}