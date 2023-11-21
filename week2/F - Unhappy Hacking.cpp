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
ll fpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin>>m;
    string s;
    cin>>s;
    int n=s.size();
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=m;j++){
            if(j==0) dp[j][i]=(dp[j][i]+dp[j][i-1])%mod;
            if(j+1<=m) dp[j][i]=(dp[j][i]+dp[j+1][i-1])%mod;
            if(j>0) dp[j][i]=(dp[j][i]+2*dp[j-1][i-1])%mod;
        }
    }
    ll i2=fpow(2,mod-2);
    cout<<dp[n][m]*fpow(i2,n)%mod<<"\n";
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

