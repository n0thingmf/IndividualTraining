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

const int inf=1e5;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n-1;i++){
        if(a[i-1]>(a[i]^a[i+1])){
            cout<<"1\n";
            return 0;
        }
    }
    int ans=inf;
    for(int i=0;i<n-1;i++){
        for(int j=0,l=0;i-j>=0;j++){
            l^=a[i-j];
            for(int k=0,r=0;i+1+k<n;k++){
                r^=a[i+1+k];
                if(l>r){
                    ans=min(ans,j+k);
                }
            }
        }
    }
    if(ans==inf) cout<<"-1\n";
    else cout<<ans<<"\n";
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

