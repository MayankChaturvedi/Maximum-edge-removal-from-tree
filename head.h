#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define loop(n) for(int i=0;i<n;++i)
#define loop1(n) for(int j=1;j<=n;++j)
#define pb push_back
#define debug(x,n) cout<<n<<" "<<x<<endl;
#define N 1000000007
using namespace std;
class graph{
    int n;
    list<int> *g;
    int* arr;
    int num;
    bool* explored;
public:
    int *count;
    graph(int v);
    void addedge(int x, int y);
    int dfs(int x);
    int dfs(int x,bool b[]);
    int dfs2(int x,bool b[]);
    int ini_dfs();
    int explore(int m);
};