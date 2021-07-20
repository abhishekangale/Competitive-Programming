#include <stdio.h>
// Divide and conquer approach to find the minimum and maximum number in an array
int min,max;
void MinAndMax(int a[],int i, int j )
{
 int mid,max1,min1;
 if(i==j)           // if the array contains only one element
 {
  max = min = a[i];
 }
 else if(i == j-1)      // if the array contains only two elements
  {
   if(a[i] <a[j])
   {
    max = a[j];
    min = a[i];
   }
   else
   {
    max = a[i];
    min = a[j];
   }
  }
  else
  {
   mid = (i+j)/2;   
   MinAndMax(a,i, mid); // recur for the left subarray
   max1 = max; 
   min1 = min;
   MinAndMax(a,mid+1, j); // recur for the right subarray
   if(max <max1)
    max = max1;
   if(min > min1)
    min = min1;
  }
 
}



int main()
{
    int n;
    printf("enter the number of elements in an array:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
     max=arr[0];
     min=arr[0];
    MinAndMax(arr, 0, n - 1);
    printf("The minimum array element is %d\n" ,min);
    printf("The maximum array element is %d", max);
 
    return 0;
}
