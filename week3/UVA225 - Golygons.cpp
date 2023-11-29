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
#define point complex<long long>
#define x real()
#define y imag()
using namespace std;

int n,ans;
const int maxn=400;
bool tab[maxn][maxn],vis[maxn][maxn];
point dir[4];
string s,name="ensw";
void bt(int pos,int d,point now){
    if(pos==n){
        if(now.x==0 && now.y==0){
            cout<<s<<"\n";
            ans++;
        }
        return;
    }
    if(vis[now.x+200][now.y+200]) return;
    vis[now.x+200][now.y+200]=true;
    for(int i=0;i<4;i++){
        if(pos!=0 && (i==d || i==3-d)) continue;
        bool ok=true;
        point next=now;
        for(int j=0;j<=pos;j++){
            next=next+dir[i];
            if(tab[200+next.x][200+next.y]){
                ok=false;
                break;
            }
        }
        if(ok){
            s.pb(name[i]);
            bt(pos+1,i,next);
            s.popb();
        }
    }
    vis[now.x+200][now.y+200]=false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    dir[0]=point(1,0);
    dir[1]=point(0,1);
    dir[2]=point(0,-1);
    dir[3]=point(-1,0);
    int t;
    cin>>t;
    while(t--){
        memset(tab,0,sizeof(tab));
        int m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            tab[200+u][200+v]=true;
        }
        ans=0;
        bt(0,-1,point(0,0));
        cout<<"Found "<<ans<<" golygon(s).\n";
        cout<<"\n";
    }
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

