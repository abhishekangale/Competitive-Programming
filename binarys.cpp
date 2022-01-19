#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(void)
{
    srand((ll)time(NULL));
    ll i, n = 25, l, r, mid, k, c;
    ll array[25], count[500];
    for (i = 0; i < n; i++)
    {
        array[i] = 1 + (rand() % 50);
        //cout<<array[i]<<" ";
    }
    //cout<<endl;
    sort(array, array + n);
    for (i = 0; i < 500; i++)
    {
        c = 0;
        k = 1 + (rand() % 50);
        l = 0;
        r = n - 1;
        mid = (l + r) / 2;
        while (l <= r)
        {
            if (array[mid] == k)
            {
                c++;
                break;
            }
            else if (k < array[mid])
            {
                c++;
                r = mid - 1;
            }
            else
            {
                c++;
                l = mid + 1;
            }
            mid = (l + r) / 2;
        }
        count[i] = c;
    }
    sort(count, count + 500, greater<ll>()); // reversing ie arranging from high to low
     cout << "Worst time for searching an element from an array of 25 elements" << count[0] << endl;
}
