#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main(){

    // STL 1 : Vectors, Stacks, Queues, lower_bound, upper_bound, etc.

    // STL 2 : 

    // int A[3] = {1, 3 ,2};


    // next_permutation(A, A+3);

    // next_perm = 2, 1 ,3

    // prev_perm = 1, 2, 3

    // do{
    //     for(int i=0; i<3; i++){
    //         cout << A[i] << " ";
    //     }
    //     cout << '\n';
    // }
    // while(next_permutation(A, A+3));
    
    // n!

    // multiset<int> A;

    // // // sorted manner : 2 3 -> 1 2 3
    // A.insert(1);
    // A.insert(2);
    // A.insert(3);

    // A.insert(3);

    // auto it = A.lower_bound(3);
    
    // if you erase by value in multisets : all occurences of that value are erased

    // if you erase by iterators in multisets : only the element at that iter will erased 

    // map<int, int> A;

    // A.insert({5, 6});
    // A.insert({1, 3});
    
    // // order is decided on the keys
    // auto p = A.begin();

    // cout << (*p).first << " " << (*p).second << '\n';
    
    // int n = 1e6;
    // a[i] = 1e9;
    
    // total : 1e6 -> max value = 1e9
    // x -> y

    // a -> b

    // y = b

    // 1e9 -> x < 1e7

    // 0,1,2,3

    // q = {1, 3, 2}

    // q = {1, 2, 3}

    //  -1, -2, -3

    //  -3, -2, -1
    
    //  set<int> A = {1, 2, 3, 4}

    // A[3] -> 

    oset A;

    A.insert(1);
    A.insert(2);
    A.insert(3);
    A.insert(4);

    auto x = A.order_of_key(10);

    multimap<int,int> A;
    oset A;
    cout << x << '\n';
  
   


    return 0;
}