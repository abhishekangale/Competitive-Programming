#include<bits/stdc++.h>
using namespace std;

struct person{
    string name;
    long long salary;
};

bool cmp(person x, person y){
    if(x.salary == y.salary){
        return (x.name < y.name);
    }
    else {
        return (x.salary > y.salary);
    }
}

int main(){
    long long n;
    cin >> n;
    person arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i].name >> arr[i].salary;
    }
    sort(arr, arr+n, cmp);
    for(int i=0; i<n; i++){
        cout << arr[i].name << " " << arr[i].salary <<'\n';
    }
}