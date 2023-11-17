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

const ll mod=1e9+7;

ll dp[2][1<<17],pw[41];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;
    pw[0]=1;
    for(int i=1;i<=40;i++) pw[i]=pw[i-1]*10%mod;
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    memset(dp[1],0,sizeof(dp[1]));
    int mask=(1<<(x+y+z))-1;
    for(int i=1;i<=10;i++) dp[1][(1<<(i-1))&mask]++;
    //for(int i=0;i<(1<<(x+y+z));i++) if(dp[1][i]>0) cout<<(bitset<17>(i))<<" "<<dp[1][i]<<"\n";
    ll ans=0;
  //  ll cnt=0;
    for(int i=1;i<=n;i++){
        //cout<<((i&1)^1)<<"\n";
        memset(dp[(i&1)^1],0,sizeof(dp[(i&1)^1]));
        for(int j=0;j<(1<<(x+y+z));j++){
            if((j&(1<<(x+y+z-1))) && (j&(1<<(y+z-1))) && (j&(1<<(z-1)))){
                ll res=dp[i&1][j]*pw[n-i]%mod;
                //cout<<res<<"\n";
                ans=(ans+res)%mod;
            }else{
                for(int k=1;k<=10;k++){
                    int next=(j<<k)|(1<<(k-1));
                    next&=mask;
                    //assert(next<(1<<(x+y+z)));
                    dp[(i&1)^1][next]=(dp[(i&1)^1][next]+dp[i&1][j])%mod;
                }
            }
        }
    }
    //cout<<cnt<<"\n";
    /*for(int j=0;j<(1<<17);j++){
        if(j<=(1<<(x+y+z-1)) && ((j>>(x+y+z-1))&1)==1 && ((j>>(y+z-1))&1)==1 && ((j>>(z-1))&1)==1){
            ll res=dp[n&1][j]%mod;
            ans=(ans+res)%mod;
        }
    }*/
    cout<<ans<<"\n";
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

