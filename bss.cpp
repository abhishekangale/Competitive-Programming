#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define nl '\n'

int binarySearch(vector<int> &v, int left, int right, int key){
   while(left<=right){
      int mid=left+(right-left)/2;
    //   cerr << mid << " ";
      if(v[mid]==key) return mid;
      else if(v[mid]<key) left = mid + 1;
      else right = mid - 1;
   }
  return -1;
}

int search(vector<int> &v, int k){
    
    int l = 0, r = v.size() - 1, ind=0;
    while(l <= r){
      int mid = l + ( r - l ) / 2;
    //   cerr << mid << " ";
      if(v[mid] == k) return mid;
      if(v[mid] <= v[0] and v[mid] <= v[v.size() - 1]){ ind = mid; r = mid - 1; }
      else l = mid + 1;
    }
    // cerr << ind;
    if(ind != 0){
        if(binarySearch(v, 0, ind - 1, k) != -1)
        {  
            return binarySearch(v, 0, ind - 1, k); 
        }
    }
    else if(binarySearch(v, ind, v.size() - 1, k) != -1){  return binarySearch(v, ind, v.size() - 1, k); }
    return -1;

}

void solution(){
  int n, k; cin >> n >> k;
  vector<int> v(n);
  for(auto &i: v) cin >> i;

  cout << search(v, k) << nl;
}
   
int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
solution();   
return 0;
}