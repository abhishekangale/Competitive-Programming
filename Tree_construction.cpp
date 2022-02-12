#include <bits/stdc++.h>
#define MAX 300004
using namespace std;
 
// Adjacency list to
// represent the graph
vector<int> graph[MAX];
int mod = 1e9 + 7;
 
// Stores the count of subtrees
// possible from given N-ary Tree
int ans = 0;
 
// Utility function to count the number of
// subtrees possible from given N-ary Tree
int countSubtreesUtil(int cur, int par)
{
    // Stores the count of subtrees
    // when cur node is the root
    int res = 1;
 
    // Traverse the adjacency list
    for (int i = 0;
         i < graph[cur].size(); i++) {
 
        // Iterate over every ancestor
        int v = graph[cur][i];
 
        if (v == par)
            continue;
 
        // Calculate product of the number
        // of subtrees for each child node
        res = (res
               * (countSubtreesUtil(
                      v, cur)
                  + 1))
              % mod;
    }
 
    // Update the value of ans
    ans = (ans + res) % mod;
 
    // Return the resultant count
    return res;
}
 
// Function to count the number of
// subtrees in the given tree
void countSubtrees(int N,
                   vector<pair<int, int> >& adj)
{
    // Initialize an adjacency matrix
    for (int i = 0; i < N - 1; i++) {
        int a = adj[i].first;
        int b = adj[i].second;
 
        // Add the edges
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    // Function Call to count the
    // number of subtrees possible
    countSubtreesUtil(1, 1);
 
    // Print count of subtrees
    cout << ans + 1;
}
 
// Driver Code
int main()
{
    int N;
    cin >> N;
 
    vector<pair<int, int> > adj(N-1);
    for(int i = 0; i < N - 1; i++){
        cin >> adj[i].first >> adj[i].second;
    }
 
    countSubtrees(N, adj);
 
    return 0;
}