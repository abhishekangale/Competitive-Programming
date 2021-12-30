#include<bits/stdc++.h>
using namespace std;


int main(){

    // for(int i=0; i<(int)a.size(); i++){
    //     cout << a[i] << " ";
    // }

    // data = {name, roll no}
    // pair<datatype1, datatype2> A;



    // stack
    

    // stores datatype, pop(), push(), top()


    deque<int> name;
    name.push_back(1);
    name.push_back(2);
    name.push_front(3);

    

    name.clear();
    // while(!name.empty()){
    //     name.pop();
    // }
    while(!name.empty()){
        cout << name.back() << " ";
        name.pop_back();
    }
    // clear -> O(size of container)

    return 0;
}
