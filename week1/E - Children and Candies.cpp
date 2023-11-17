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
const ll maxn=400;
//ll cb[maxn+1][maxn+1];
ll dp[maxn+1][maxn+1];
ll pw[maxn+1][maxn+1];
void init(){
    /*for(int i=0;i<=maxn;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || i==j) cb[i][j]=1;
            else cb[i][j]=(cb[i-1][j]+cb[i-1][j-1])%mod;
        }
    }*/
    for(int i=0;i<=maxn;i++){
        pw[i][0]=1;
        for(int j=1;j<=maxn;j++){
            pw[i][j]=pw[i][j-1]*i%mod;
        }
    }
}
ll fpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;
    init();
    int n,c;
    cin>>n>>c;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<vector<ll>> psum(n,vector<ll>(c+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<=c;j++){
            for(int x=a[i];x<=b[i];x++){
                psum[i][j]=(psum[i][j]+pw[x][j])%mod;
            }
        }
    }
    for(int j=0;j<=c;j++){
        dp[0][j]=psum[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=c;j++){
            dp[i][j]=0;
            for(int k=0;k<=j;k++){
                dp[i][j]+=dp[i-1][j-k]*psum[i][k]%mod;
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[n-1][c]<<"\n";
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

