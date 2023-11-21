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
const int maxn=5001;
ll dp[maxn][maxn];
ll nb[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    nb[0]=1;
    for(int i=2;i<maxn;i+=2){
        nb[i]=0;
        for(int j=2;j<=i;j+=2){
            nb[i]+=nb[i-j]*nb[j-2]%mod;
            nb[i]%=mod;
        }
    }
    memset(dp,0,sizeof(dp));
    int m;
    string s;
    cin>>m>>s;
    int n=s.size();
    dp[0][0]=dp[0][1]=1;
    for(int j=2;j<=m;j++){
        dp[0][j]=dp[0][j-1];
        ll e=2;
        for(int i=2;j-i>=0;i+=2){
            dp[0][j]=(dp[0][j]+dp[0][j-i]*e%mod*nb[i-2])%mod;
            e=e*2%mod;
        }
    }
    for(int i=0;i<=80;i++) cout<<dp[0][i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++){
        dp[i][i-1]=0;
        dp[i][i]=1;
        for(int j=i+1;j<=m;j++){
            dp[i][j]=dp[i-1][j-1];
            ll e=2;
            for(int k=2;j-k>=i;k+=2){
                dp[i][j]=(dp[i][j]+dp[i][j-k]*e%mod*nb[k-2])%mod;
                e=e*2%mod;
            }
        }
    }
    cout<<dp[n][m]<<"\n";
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

