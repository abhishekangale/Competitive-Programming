#include<bits/stdc++.h>
using namespace std;
#define V 5 //number of nodes
void tsp(int graph[][5], vector<bool>& v, int currPos, int n, int count, int cost, int& ans){
  
    // If last node is reached and it has a link
    // to the starting node i.e the source then
    // keep the minimum value out of the total cost
    // of traversal and "ans"
    // Finally return to check for more possible values
    if (count == n && graph[currPos][0]) {
        ans = min(ans, cost + graph[currPos][0]);
        return;
    }
  
    // BACKTRACKING STEP
    // Loop to traverse the adjacency list
    // of currPos node and increasing the count
    // by 1 and cost by graph[currPos][i] value
    for (int i = 0; i < n; i++) {
        if (!v[i] && graph[currPos][i]) {
  
            // Mark as visited
            v[i] = true;
            tsp(graph, v, i, n, count + 1, cost + graph[currPos][i], ans);

            // Mark ith node as unvisited
            v[i] = false;
        }
    }
}
  
// Driver code
int main()
{
    // n is the number of nodes i.e. V
    int n = 5;
  
    int graph[][V] = {
        { 0, 10, 15, 20, 30 },
        { 10, 0, 35, 25, 20 },
        { 15, 35, 0, 30, 15 },
        { 20, 25, 30, 0, 10 },
        { 30, 20, 15, 10, 0 }
    };
    // Display the Graph
    cout << "The Graph taken for example is (Adjacenct matrix):\n ";
    for(int i=0 ;i < n ; i++){
        for(int j=0 ;j < n; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<'\n';
    }
    // Boolean array to check if a node
    // has been visited or not
    vector<bool> v(n);
    for (int i = 0; i < n; i++)
        v[i] = false;
  
    // Mark 0th node as visited
    v[0] = true;
    int ans = INT_MAX;

    // Find the minimum weight Hamiltonian Cycle
    tsp(graph, v, 0, n, 1, 0, ans);
  
    // ans is the minimum weight Hamiltonian Cycle
    cout << "Minimum cost of salesman will be ";
    cout << ans <<'\n';
    return 0;
}