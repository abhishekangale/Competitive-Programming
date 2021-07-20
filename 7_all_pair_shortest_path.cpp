#include<bits/stdc++.h>
using namespace std;

#define INF 9999 

int dist[4][4];

int cost[4][4] = //given cost matrix
    {
        { 0,7,INF,8},
        { 10,0,6,15},
        { INF,INF,0,12},
        { 9,INF,INF,0}
    };
int next_m[4][4];
int V=4;
void printPath(int i,int j)   //to print path from i to j
{
    if (j==next_m[i][j])  //no intermediate vertices
     cout<<i<<" "<<j;
    else{
     cout<<i<<" ";
     printPath(next_m[i][j],j);
    }    
}
int main()
{
    int i,j,k;
    
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            dist[i][j]=cost[i][j];  //Initialize the solution matrix same as input graph matrix.
            next_m[i][j]=j;         //Initialize the next matrix to j (no intermediate verteies).
        }
    }

    for(k=0;k<V;k++)
    {
       for(i=0;i<V;i++)  // Pick all vertices as source one by one
       {
         for(j=0;j<V;j++) // Pick all vertices as destination for the above picked source
          {
              if(dist[i][k] + dist[k][j] < dist[i][j]) //if k is on the shortest path from i to j then update the value of dist[][] and next[][]
              { 
               dist[i][j]=dist[i][k] + dist[k][j]; 
               next_m[i][j]=next_m[i][k];
              }
          }
       }
    }
    cout<<"Matrix showing the shortest distances between every pair of vertices \n";
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<"INF"<<" ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"The predecessor matrix is:\n";
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            cout<<next_m[i][j]<<" ";
            if(j==V-1)
              cout<<"\n";
        }
        
    }
    int a,b;
    cout<<"enter the values of start and end for path to obtain:\n";
    cin>>a>>b;
    printPath(a,b);
return 0;
}
