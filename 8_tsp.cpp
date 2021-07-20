#include<bits/stdc++.h>
#define INF 9999
using namespace std;
int M[4][4]={{0,1,2,3},   
             {2,0,3,4},
             {3,4,0,5},
             {4,5,6,0}};
int q[4];
int cost=0;
int n=4;
int status[4];
void func(int a[4][4]);
int main()
{
    cout<<"Given cost matrix:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<M[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i=0;i<n;i++)
    {
        status[i]=0;
    }
    q[0]=0;
    func(M);
    return 0;
}
void func(int M[4][4])
{
    int next=1;
    int i, j, min;
    status[0]=1;
    i=0;
    while(i<n)
    {
        min=INF;
        for(j=0;j<n;j++)
        {
           if(M[i][j]!=INF && M[i][j]!=0 && status[j]==0)
           {
               if(M[i][j]<min)   //if distance found is shorter than current distance
               {
                   min=M[i][j];
                   q[next]=j;
               }
           }
        }
        if(min==INF)
        {
            cost=cost+M[i][0];
            break;
        }
        else
        {
            cost=cost+min;
            status[q[next]]=1;
            i=q[next];
            next=next+1;
        }
    }
    cout<<"Shortest Path: "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<q[i]<<"-->";
    }
    cout<<0;
    cout<<"\n";
    cout<<"Minimum Cost:"<<cost;
}
