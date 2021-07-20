#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((long)time(NULL));
    long i,n,first,end,mid,k,c,temp=0;
    long arr[25],count[500];
    for(i=0;i<=n;i++)
    {
        arr[i]=i+1;           //generate an array of 1-25 elements 
    }
    for(i=0;i<500;i++)
    {
        c=0;
        k=1+(rand()%50);   //k be the random element to be searched 500 times
        first=0;
        end=n-1;
        mid=(first+end)/2;
        while(first<=end)   //binary search algorithm
        {
            if(arr[mid]==k)
            {
                c++;
                break;
            }
            else if(k<arr[mid])
            {
                c++;
                end=mid-1;
            }
            else{
                c++;
                first=mid+1;
            }
            mid=(first+end)/2;
        }
        count[i]=c;
        for(i=0;i<500;i++)     //sort the count array in decreasing order
        {
            if(count[i]>count[i+1])
            {
                temp=count[i];
                count[i]=count[i+1]; 
                count[i+1]=temp;           
            }
        }
        printf("%ld",count[0]); //print for the maximum no. of count (for worst case)
    }
    return 0;
}
