/**
 * @author Mijail Poccohuanca
 * @tag pingeonhole principle, brute force
 * @idea
 *      - the coordinates are less than 10^5 then the manhatan distance of two points will be in the range [0,2*10^5]
 *      - for n points there are n*(n-1)/2 posible pair of points, then if this value is greater than 2*10^5+1(number of possible values of the manhatan distance) by the pigeonhole principle there will be at least two pair of points with equal manhatan distance, in this case we print YES and finish the program;
 *      - if n*(n-1)/2 < 2*10^5+1 we just brute force over all pairs
 * @complexity O(N^2) with N^2 < 2*10^5 + 1
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
#define point pair<int,int>
#define x first
#define y second

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<point> p(n);
        for(int i = 0; i < n; i++) cin>>p[i].x>>p[i].y;
        if(n*(n-1)/2 > 2*m+1) cout<<"YES\n";
        else{
            set<int> d;
            bool found=false;
            for(int i = 0; i < n && !found; i++){
                for(int j = i+1; j < n && !found; j++){
                    int md=abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y);
                    if(d.count(md)) found=true;
                    else d.insert(md);
                }
            }
            if(found) cout<<"YES\n";
            else cout<<"NO\n";
        }
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

