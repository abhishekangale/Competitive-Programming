#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((long)time(NULL));
    long i,n,k,c,s,avg,n1,j;
    long count[500],arr[25];
    n=25;
    for(i=0;i<n;i++)
    {
        arr[i]=i+1;         //generate an array of 1-25 elements 
    }
    for(i=0;i<500;i++)
    {
        k=1+(rand()%25);    //k be the random element to be searched 50 times
        c=0;
        for(j=0;j<n;j++)
        {
            if(arr[j]==k)
            {
                c++;         // count the no. of comparsion
                break;
            }
            c++;
        }
        count[i]=c;
    }
    s=0;
    for(i=0;i<500;i++)
    {
        s+=count[i]; //total count
    }
    avg=s/500;        //calculate average count 
    printf("%ld",avg);
    return 0;
}
