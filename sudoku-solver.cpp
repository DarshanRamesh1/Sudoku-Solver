#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <sstream>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define pf push_front
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
 
using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
template<class T> using pbds =tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
 
//-----------computational geometry--------------------
//(x1,y1) (x2,y2)  vector representation of AB->(x2-x-y1)
//AB.BC=|AB||BC|cos@  AB(x1,y1) BC(x2,y2) AB.BC=x1*x2+y1*y2
//ABxBC=|AB||BC|sin@    vecA(x1,y1) vecB(x2,y2)  vecA x vecB=x1*y2-y1*x2
//area of parallelogram=AxB=|B||Asin@| (magnitude)
//area of triangle = AxB/2 
//dist btw 2 pts- sqrt((x2-x1)^2 + (y2-y1)^2)
//perpendicular distance of point(C) from line(AB) (ABxAC)/|AB| Base->AB Height->|AC|sin@
//dist of point C to line segment AB, if(AB.AC)=-ve i.e. @>=90 so near A (AC is ans)
//else if(AB.BC)=+ve C is near pt B (BC is ans)
//else if both pts contradict point C is in btw AB so perpendicular dist is ans
 
using namespace std;
void init_code()
{
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
}
#define N 9

bool isSafe(int grid[N][N], int row, int col, int num)
{
    // check in row
    for (int i = 0; i < 9 ; i++)
    {
        if (grid[row][i] == num)
        {
            return false;
        }
    }
    
    // check in column
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }
 
    int ROW = row - row % 3, COL = col - col % 3;
    
    // check in 3*3 box
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + ROW][j + COL] == num)
                return false;
        }
    }
    // if all is safe num can be places there
    return true;
}

bool solveSudoku(int grid[N][N], int row, int col)
{
    if (row==N - 1 && col==N)
        return true;
 
    if (col == N) 
    {
        row++;
        col=0;
    }
    // if number is already present no need to check
    if (grid[row][col]>0)
        return solveSudoku(grid, row, col + 1);
    
    // check for all numbers from 1 to 9 if its safe
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}

int main() 
{
    //init_code();
    ll t=1;
    //cin>>t;
    while(t--)
    {
        int grid[N][N];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                cin>>grid[i][j];
        }
        if (solveSudoku(grid,0,0))
        {
            for (int i=0;i<N;i++)
            {
                for (int j=0;j<N;j++)
                {
                    cout<<grid[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        else
            cout << "no solution  exists " << endl;
    }   
    return 0;
}  
