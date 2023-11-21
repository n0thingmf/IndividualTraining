/**
 * @author Mijail Poccohuanca
 * @tag dynamic programming
 * @idea
 *      - we define dp[i] as the number of ways to go from (1,1) to (p[i].x,p[i].y) but without passing over blocked cells except
 *        the finnish cell.
 *      - we can count the number of ways to go from (1,1) to an arbitrary point (n,m) with the formula comb(n+m-2,n-1)
 *      - we can use the inclusion - exclusion principle to update dp[i]
 *      - we initialize dp[i] = comb(p[i].x+p[i].y-2,p[i].x-1)
 *      - for any p[j] that is contained in the rectangle formed by (1,1) and (p[i].x,p[j].y) we update dp[i]:
 *          dp[i] -= dp[j]*comb(p[i].x+p[i].y-p[j].x-p[j].y,p[i].x-p[j].x)
 *  
 * @complexity O(k^2)
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
#define x first
#define y second
using namespace std;

const ll mod=1e9+7;
const int maxn=2e5;
ll f[maxn+1],fi[maxn+1];

ll comb(int n,int m){
    //assert(m>=0);
    //assert(m<=n);
    return f[n]*fi[n-m]%mod*fi[m]%mod;
}
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
    f[0]=1;
    for(ll i=1;i<=maxn;i++) f[i]=f[i-1]*i%mod;
    fi[maxn]=fpow(f[maxn],mod-2);
    for(ll i=maxn;i>0;i--) fi[i-1]=fi[i]*i%mod;
    //cout<<fi[0]<<"\n";
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<pair<int,int>> p(k);
        for(int i=0;i<k;i++) cin>>p[i].x>>p[i].y;
        sort(all(p));
        vector<ll> dp(k);
        for(int i=0;i<k;i++){
            dp[i]=comb(p[i].x+p[i].y-2,p[i].x-1);
            for(int j=0;j<i;j++){
                if(p[j].x<=p[i].x && p[j].y<=p[i].y){
                    dp[i]-=dp[j]*comb(p[i].y+p[i].x-p[j].x-p[j].y,p[i].x-p[j].x)%mod;
                    dp[i]=(dp[i]+mod)%mod;
                }
            }
        }
        ll ans=comb(n+m-2,n-1);
        for(int i=0;i<k;i++){
            ans-=dp[i]*comb(n+m-p[i].x-p[i].y,n-p[i].x)%mod;
            ans=(ans+mod)%mod;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
