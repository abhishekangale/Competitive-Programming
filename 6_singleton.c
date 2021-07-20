#include<stdio.h>

 int singleton( int a[],int i,int j,int n)
 {
     if(n==1)           // Base cases
      return a[i];
     else
    {
        int k,l;
         k=(i+j)/2;
         l= 2*(k/2);
        if(a[l]!=a[l+1])  // If element next to l is not same as l, then output element lies on left side, else on right side
        {
            return singleton(a,i,l,(l-i)+1);
        }
        else
        {
           return singleton(a,l+2,j,j-(l+2)+1);
        }
    }
 }
 int main()
 {
     int n,ans;
    printf("enter the number of elements in an array:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the sorted array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    ans = singleton(arr,0,n-1,n);
    printf("The singleton element in the array is:%d\n",ans);
    return 0;
 }
