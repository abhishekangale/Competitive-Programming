#include "bits/stdc++.h"
using namespace std;
#define int long long
signed main() 
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n,k;
        cin >> n >> k;
    
        int arr[n];
    
        int sum = 0;
        
        for(int i = 0;i<n;i++)
        {
            cin >> arr[i];
            sum = sum + arr[i];
        }
    
        if(k == 0)
        {
            cout << sum << endl;
            continue;
        }
        
        
            int count = 0;
            
            for(int i = 0;i<n;i++)
            {
                if(arr[i]>0)
                {
                    count++;
                }
            }
            
            if(count==n)
            {
               sum = sum + (n * 2 * k); 
               cout << sum << endl;
            }
            else
            {
                
                for(int i = 1;i<=n;i++)
                {
                    if(k == 0)
                    {
                        break;
                    }
                    else if(count>=n)
                    {
                        count = n;
                        break;
                    }
                    else
                    {
                         sum = sum + (count * 2); 
                        count = count + (count * 2);
                         k--;
                    }
                   
                }
                
                if(k == 0)
                {
                    cout << sum << endl;
                }
                
                else
                {
                    sum = sum + (count * 2 * k); 
                    cout << sum << endl;
                }
        }
    }
	return 0;
}