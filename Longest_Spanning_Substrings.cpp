#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
 
template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset Operations: order_of_key(k) -> Number of elements strictly smaller than k, find_by_order(k) -> kth element in the set
 
#define ull unsigned long long int
#define int long long int
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vd vector<double>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define vvi vector<vi>
#define vvll vector<vll>
#define vvb vector<vb>
#define vs vector<string>
#define pull pair<ull, ull>
#define F first
#define S second
#define m_p make_pair
 
const long double PI = 3.141592653589793238462643383279502884197169399;
 
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res.push_back(static_cast<char>('0' + v[i]));
    }
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifndef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif
 
// Find Set LSB = (x&(-x)), isPowerOfTwo = (x & (x-1))
 
const int mod = 1e9 + 7;

int lcs(string a,string b,int n,int m)
{
	int dp[n+1][m+1];
    // Building the table in bottom-up manner
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			else if(a[i-1]==b[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}

	return dp[n][m];
} 

 
// Function to find index of max-weight
// vertex from set of unvisited vertices
int findMaxVertex(bool visited[], int weights[],int V)
{
 
    // Stores the index of max-weight vertex
    // from set of unvisited vertices
    int index = -1;
 
    // Stores the maximum weight from
    // the set of unvisited vertices
    int maxW = 0;
 
    // Iterate over all possible
    // nodes of a graph
    for (int i = 0; i < V; i++) {
 
        // If the current node is unvisited
        // and weight of current vertex is
        // greater than maxW
        if (visited[i] == false
            && weights[i] > maxW) {
 
            // Update maxW
            maxW = weights[i];
 
            // Update index
            index = i;
        }
    }
    return index;
}
 
// Utility function to find the maximum
// spanning tree of graph
void printMaximumSpanningTree(vector<vector<int>> graph,
                              int parent[],int V)
{
 
    // Stores total weight of
    // maximum spanning tree
    // of a graph
    int MST = 0;
 
    // Iterate over all possible nodes
    // of a graph
    for (int i = 1; i < V; i++) {
 
        // Update MST
        MST += graph[i][parent[i]];
    }
 
    cout << "Weight of the maximum Spanning-tree "
         << MST << '\n'
         << '\n';
 
    cout << "Edges \tWeight\n";
 
    // Print the Edges and weight of
    // maximum spanning tree of a graph
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
    }
}
 
// Function to find the maximum spanning tree
int maximumSpanningTree(vector<vector<int>> graph,int V)
{
 
    // visited[i]:Check if vertex i
    // is visited or not
    bool visited[V];
 
    // weights[i]: Stores maximum weight of
    // graph to connect an edge with i
    int weights[V];
 
    // parent[i]: Stores the parent node
    // of vertex i
    int parent[V];
 
    // Initialize weights as -INFINITE,
    // and visited of a node as false
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        weights[i] =0;
    }
 
    // Include 1st vertex in
    // maximum spanning tree
    weights[0] = INT_MAX;
    parent[0] = -1;
 
    // Search for other (V-1) vertices
    // and build a tree
    for (int i = 0; i < V - 1; i++) {
 
        // Stores index of max-weight vertex
        // from a set of unvisited vertex
        int maxVertexIndex
            = findMaxVertex(visited, weights, V);
 
        // Mark that vertex as visited
        visited[maxVertexIndex] = true;
 
        // Update adjacent vertices of
        // the current visited vertex
        for (int j = 0; j < V; j++) {
 
            // If there is an edge between j
            // and current visited vertex and
            // also j is unvisited vertex
            if (graph[j][maxVertexIndex] != 0
                && visited[j] == false) {
 
                // If graph[v][x] is
                // greater than weight[v]
                if (graph[j][maxVertexIndex] > weights[j]) {
 
                    // Update weights[j]
                    weights[j] = graph[j][maxVertexIndex];
 
                    // Update parent[j]
                    parent[j] = maxVertexIndex;
                }
            }
        }
    }
    for(int i:weights) cout<<i<<" ";
    // Print maximum spanning tree
    return *max_element(weights,weights+V);
}

void solve(){
    int n;
    cin>>n;
    vector<string> a(n);
    for(auto &i:a)cin>>i;
    int ans=INT_MIN;
    vvi graph(n,vi (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n && j!=i;j++){
            int x=lcs(a[i],a[j],a[i].size(),a[j].size());
            graph[i][i]=0;
            graph[j][j]=0;
            graph[i][j]=x;
            graph[j][i]=x;
        }
    }

    int f=maximumSpanningTree(graph,n);
    cout<<f<<'\n';
    
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << fixed << setprecision(10);
    
    int tt=1;
    cin >> tt;
    
    while(tt--){
        solve();
    }
}