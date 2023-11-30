/**
 * @author Mijail Poccohuanca
 * @tag all spanning trees, Kirchoff theorem
 * @idea
 *      - we run a dfs over all unvisited vertices considering A[i][j] == 1 as an edge to find the connected components assining them an id, if we find a cycle(the connected component it's not a tree) we print 0 and end the program.
 *      - we build a new adjacency matrix with the ids of the connected components (like compressing a connected component as a vertex), the new graph can have multiedges, a spanning tree over this graph will be a tree in the original graph
 *      - then we build a laplacian matrix of the new adjacency matrix
 *      - finally we use the Kirchoff theorem to count the number of spanning trees over a multigraph calculating the determinant of the laplacian matrix
 *      - we use gaussian elimination modulo 10^9+7 to calculate the determinant
 * @complexity O(N^3)
 */
#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define popb pop_back
#define all(A) A.begin(),A.end()
#define rall(A) A.rbegin(),A.rend()
#define dic unordered_map
#define bpc __builtin_popcountll//numero de bits para long long
#define bclz __builtin_clzll//leading zeros para ll
#define max_bit(A) 31-__builtin_clz(A)

using namespace std;
const ll mod = 1e9+7;
const int maxn = 300;
int adj[maxn][maxn], id[maxn], n, m=0;
ll A[maxn][maxn];
bool dfs(int u, int p, int _id){
    id[u] = _id;
    for(int v = 0; v < n; v++){
        if(v != p && adj[u][v] == 1){
            if(id[v] == _id) return false;
            if(!dfs(v, u, _id)) return false;
        }
    }
    return true;
}

ll fpow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1) ans = ans*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}
ll solve(){
    for(int i = 0; i < m-1; i++)
        for(int j = 0; j < m-1; j++) A[i][j] = (A[i][j]%mod + mod)%mod;
    for(int i = 0; i < m-1; i++){
        ll inv = fpow(A[i][i], mod-2);
        for(int j = i+1; j < m-1; j++){
            ll fact = (mod - A[j][i])%mod;
            fact = fact*inv%mod;
            for(int k = i; k < m-1; k++){
                A[j][k] = (A[j][k] + fact*A[i][k]%mod)%mod;
            }
        }
    }
    ll ans = 1;
    for(int i = 0; i < m-1; i++) ans = ans*A[i][i]%mod;
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(id, -1, sizeof(id));
    memset(A, 0, sizeof(A));
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>adj[i][j];
    for(int i = 0; i < n; i++){
        if(id[i] == -1){
            if(!dfs(i, -1, m++)){
                cout << "0\n";
                return 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(id[i] != id[j] && adj[i][j] == -1){
                A[id[i]][id[j]]--;
                A[id[i]][id[i]]++;
            }
        }
    }
    cout << solve() << "\n";
    return 0;
    // you should actually read the stuff at the bottom
}

/* stuff you should look for
    * int overflow, array bounds
    * bitwise and boolean operations
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/

