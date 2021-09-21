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
struct Point {
  
    int x, y;
  
    bool operator<(Point p)
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};
  
// Cross product of two vectors OA and OB
// returns positive for counter clockwise
// turn and negative for clockwise turn
int cross_product(Point O, Point A, Point B)
{
    return (A.x - O.x) * (B.y - O.y)
           - (A.y - O.y) * (B.x - O.x);
}
  
// Returns a list of points on the convex hull
// in counter-clockwise order
vector<Point> convex_hull(vector<Point> A)
{
    int n = A.size(), k = 0;
  
    if (n <= 3)
        return A;
  
    vector<Point> ans(2 * n);
  
    // Sort points lexicographically
    sort(A.begin(), A.end());
  
    // Build lower hull
    for (int i = 0; i < n; ++i) {
  
        // If the point at K-1 position is not a part
        // of hull as vector from ans[k-2] to ans[k-1]
        // and ans[k-2] to A[i] has a clockwise turn
        while (k >= 2
               && cross_product(ans[k - 2], 
                            ans[k - 1], A[i]) <= 0)
            k--;
        ans[k++] = A[i];
    }
  
    // Build upper hull
    for (size_t i = n - 1, t = k + 1; i > 0; --i) {
  
        // If the point at K-1 position is not a part
        // of hull as vector from ans[k-2] to ans[k-1]
        // and ans[k-2] to A[i] has a clockwise turn
        while (k >= t
               && cross_product(ans[k - 2], 
                          ans[k - 1], A[i - 1]) <= 0)
            k--;
        ans[k++] = A[i - 1];
    }
  
    // Resize the array to desired size
    ans.resize(k - 1);
  
    return ans;
}
  
// Function to return the distance between two points
double dist(Point a, Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x)
                + (a.y - b.y) * (a.y - b.y));
}
  
// Function to return the perimeter of the convex hull
double perimeter(vector<Point> ans)
{
    double perimeter = 0.0;
  
    // Find the distance between adjacent points
    for (int i = 0; i < ans.size() - 1; i++) {
        perimeter += dist(ans[i], ans[i + 1]);
    }
  
    // Add the distance between first and last point
    perimeter += dist(ans[0], ans[ans.size() - 1]);
  
    return perimeter;
}
Point gg;
int printSubsequences(vector<Point> arr, int index,
                       vector<Point> subarr)
{
    double ans=(double)mod;
    if (index == arr.size())
    {
        int l = subarr.size();
        if (l != 0){
            vector<Point> hehe=subarr;
            hehe.pb(gg);
            ans=min(ans,perimeter(hehe));
        }
            
    }
    else
    {
        printSubsequences(arr, index + 1, subarr);
 
        subarr.push_back(arr[index]);
        printSubsequences(arr, index + 1, subarr);
    }
    return ans;
}

void solve(){
   int n;
   cin>>n;
    vector<Point> points(n);
    for(int i=0;i<n;i++){
        cin>>points[i].x>>points[i].y;
    }
    // int x1,y1;
    cin>>x1>>y1;
    vector<Point> hehehe;
    int ass = printSubsequences(points, 0,hehehe);
    cout<<ass<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cout << fixed << setprecision(10);
    
    int tt=1;
	cin >> tt;
    for (auto case_num = 1; case_num <= tt; ++ case_num) {
        cout << "Case #" << case_num << ": ";
        solve();
    }
}