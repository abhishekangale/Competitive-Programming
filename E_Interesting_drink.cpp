#include<bits/stdc++.h>
using namespace std;

int main()
{
   int t = 0;
   cin >> t;
   vector<int> v(t);
   for (int tt = 0; tt < t; tt++)
   {
      cin >> v[tt];
      //solve();
   }
   int x;
   cin >> x;
   vector<int> v1(x);
   for (int tt = 0; tt < x; tt++)
   {
      cin >> v1[tt];
      //solve();
   }
   sort(v.begin(), v.end());

   //sort(v1.begin(),v1.end());
   for (int tt = 0; tt < x; tt++)
   {
      int low = 0;
      int high = t - 1;
      int ans = 0;
      //int count=0;
      while (low <= high)
      {
         int mid = (low + high) / 2;
         if (v[mid] <= v1[tt]){
            // high=mid-1;
            low = mid + 1;
            ans = mid + 1;
        }
         //count++;

         else
            high = mid - 1;
      }
      // cout <<high<< " ";
      cout<< ans <<'\n';
   }
}