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

const int maxn=20;
int dp[1<<maxn];
int w[40];
long long adj[40];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        memset(adj,0,sizeof(adj));
        for(int i=0;i<n;i++) cin>>w[i],adj[i]|=(1LL<<i);
        memset(dp,-1,sizeof(dp));
        int n1=min(n,maxn),n2=n-n1,max1=(1<<n1)-1;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            adj[u]|=(1LL<<v);
            adj[v]|=(1LL<<u);
        }
        int q;
        cin>>q;
        while(q--){
            int nq;
            cin>>nq;
            ll mask=0;
            for(int i=0;i<nq;i++){
                int xd;
                cin>>xd;
                mask|=(1LL<<xd);
            }
            auto bt=[&](ll msk,auto &&bt){
                if(msk==0) return 0;
                int mb=63-__builtin_clzll(msk);
                if(mb<n1 && dp[msk]!=-1)
                    return dp[msk];
                }
                int ans=max(bt(msk&(~adj[mb]),bt)+w[mb],bt(msk^(1LL<<mb),bt));
                if(mb<n1) dp[msk]=ans;
                return ans;
            };
            cout<<bt(mask,bt)<<"\n";

        }
        if(t) cout<<"\n";
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

