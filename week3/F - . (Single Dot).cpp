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
const int maxn=3e3+5;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int a[maxn][3],b[maxn][3];
int adj[maxn][maxn];
bool vis[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(adj,0,sizeof(adj));
    memset(vis,0,sizeof(vis));
    int n,m;
    cin>>n>>m;
    vector<int> xx,yy;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++) cin>>a[i][j];
        xx.pb(a[i][0]);
        xx.pb(a[i][1]);
        yy.pb(a[i][2]);
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++) cin>>b[i][j];
        xx.pb(b[i][0]);
        yy.pb(b[i][1]);
        yy.pb(b[i][2]);
    }
    sort(all(xx));
    sort(all(yy));
    for(int i=0;i<n;i++){
        int u=lower_bound(all(xx),a[i][0])-xx.begin();
        int v=lower_bound(all(xx),a[i][1])-xx.begin();
        int w=lower_bound(all(yy),a[i][2])-yy.begin();
        //(u,w)->(v,w)
        if(u>v) swap(u,v);
        for(int x=u+1;x<=v;x++){
            adj[x][w]|=(1<<1);
            adj[x][w+1]|=(1<<3);
        }
    }
    for(int i=0;i<m;i++){
        int u=lower_bound(all(xx),b[i][0])-xx.begin();
        int v=lower_bound(all(yy),b[i][1])-yy.begin();
        int w=lower_bound(all(yy),b[i][2])-yy.begin();
        //(u,v)->(u,w)
        if(v>w) swap(v,w);
        for(int y=v+1;y<=w;y++){
            adj[u][y]|=(1<<0);
            adj[u+1][y]|=(1<<2);
        }
    }
    n=xx.size(),m=yy.size();
    int sx=lower_bound(all(xx),0)-xx.begin(),sy=lower_bound(all(yy),0)-yy.begin();
    queue<pair<int,int>> q;
    q.push({sx,sy});
    vis[sx][sy]=true;
    ll area=0;
    while(!q.empty()){
        int ux=q.front().first,uy=q.front().second;
        q.pop();
        if(ux==0 || ux==n || uy==0 || uy==m){
            area=-1;
            break;
        }
        area+=1LL*(xx[ux]-xx[ux-1])*(yy[uy]-yy[uy-1]);
        for(int i=0;i<4;i++){
            if(adj[ux][uy]&(1<<i)) continue;
            int vx=ux+dx[i],vy=uy+dy[i];
            if(!vis[vx][vy]){
                q.push({vx,vy});
                vis[vx][vy]=true;
            }
        }
    }
    if(area==-1) cout<<"INF\n";
    else cout<<area<<"\n";
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

