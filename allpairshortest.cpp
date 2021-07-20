#include<bits/stdc++.h>
using namespace std;
#define n 7 //defining number of nodes
#define INF 999 // defining infinity

//defining cost matrix for the graph
int costMat[n][n] = {
   {0, 3, 6, INF, INF, INF, INF},
   {3, 0, 2, 1, INF, INF, INF},
   {6, 2, 0, 1, 4, 2, INF},
   {INF, 1, 1, 0, 2, INF, 4},
   {INF, INF, 4, 2, 0, 2, 1},
   {INF, INF, 2, INF, 2, 0, 1},
   {INF, INF, INF, 4, 1, 1, 0}
}; 

// function to calculate all pairs shortest path using dynamic programming
void dynamicprog(){
   int cost[n][n]; //defind to store shortest distance from any node to any node
   for(int i = 0; i<n; i++)
      for(int j = 0; j<n; j++)
         cost[i][j] = costMat[i][j]; //copy costMatrix to new matrix
         for(int k = 0; k<n; k++){
            for(int i = 0; i<n; i++)
               for(int j = 0; j<n; j++)
                  if(cost[i][k]+cost[k][j] < cost[i][j])
                     cost[i][j] = cost[i][k]+cost[k][j];
   }
   cout << "The matrix:" << endl;
   for(int i = 0; i<n; i++){
      for(int j = 0; j<n; j++)
         cout << setw(3) << cost[i][j];
      cout << endl;
   }
}
int main(){
   dynamicprog();
}