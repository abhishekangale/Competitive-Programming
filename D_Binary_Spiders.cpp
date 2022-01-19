#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
 
// template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
 
struct TrieNode
{
    // Stores binary representation
    // of numbers
    TrieNode *child[2];
 
    // Stores count of elements
    // present in a node 
    int cnt;
     
    // Function to initialize
    // a Trie Node
    TrieNode() {
        child[0] = child[1] = NULL;
        cnt = 0;
    }
};
 
 
// Function to insert a number into Trie
void insertTrie(TrieNode *root, int N) {
     
    // Traverse binary representation of X.
    for (int i = 31; i >= 0; i--) {
         
        // Stores ith bit of N
        bool x = (N) & (1 << i);
         
        // Check if an element already
        // present in Trie having ith bit x.
        if(!root->child[x]) {
             
            // Create a new node of Trie.
            root->child[x] = new TrieNode();
        }
         
        // Update count of elements
        // whose ith bit is x
        root->child[x]->cnt+= 1;
         
        // Update root.
        root= root->child[x];
    }
}
 
 
// Function to count elements
// in Trie whose XOR with N
// exceeds K
int cntGreater(TrieNode * root,
                int N, int K)
{
     
    // Stores count of elements
    // whose XOR with N exceeding K
    int cntPairs = 0;
     
    // Traverse binary representation
    // of N and K in Trie
    for (int i = 31; i >= 0 &&
                     root; i--) {
                                    
        // Stores ith bit of N                        
        bool x = N & (1 << i);
         
        // Stores ith bit of K
        bool y = K & (1 << i);
         
        // If the ith bit of K is 1
        if (y) {
             
            // Update root.
            root =
                root->child[1 - x];
        }
         
        // If the ith bit of K is 0
        else{
             
            // If an element already
            // present in Trie having
            // ith bit (1 - x)
            if (root->child[1 - x]) {
                 
                // Update cntPairs
                cntPairs +=
                root->child[1 - x]->cnt;
            }
             
            // Update root.
            root = root->child[x];
        }
    }
    return cntPairs;
}
 
// Function to count pairs that
// satisfy the given conditions.
int cnt(vi arr, int N,
                             int K) {
     
    // Create root node of Trie
    TrieNode *root = new TrieNode();
     
    // Stores count of pairs that
    // satisfy the given conditions
    int cntPairs = 0;
     
    // Traverse the given array.
    for(int i = 0;i < N; i++){
         
        // Update cntPairs
        cntPairs += cntGreater(root,
                           arr[i], K);
         
        // Insert arr[i] into Trie.
        insertTrie(root, arr[i]);
    }
    
    return cntPairs;
}


void solve(){
    int n,l;
    cin >> n >> l;
    vi a(n);
    for(auto &i:a)cin >> i;
    int num = cnt(a, n , l);
    cout << num << '\n';
    
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << fixed << setprecision(10);
    
    int tt=1;
    //cin >> tt;
    
    while(tt--){
        solve();
    }
}