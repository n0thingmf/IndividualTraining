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
const int maxn=1e5;
int stl[maxn][17],str[maxn][17];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;
    int n;
    cin>>n;
    int m=max_bit(n);
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin>>x[i];
    int l,q;
    cin>>l>>q;
//    cout<<"kek\n";
    for(int i=0;i<n;i++){
        str[i][0]=upper_bound(all(x),x[i]+l)-x.begin()-1;
        stl[i][0]=lower_bound(all(x),x[i]-l)-x.begin();
//        cout<<str[i][0]<<" "<<stl[i][0]<<"\n";
    }

    for(int k=1;k<=m;k++){
        for(int i=0;i<n;i++){
            str[i][k]=str[str[i][k-1]][k-1];
            stl[i][k]=stl[stl[i][k-1]][k-1];
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        a--,b--;
        if(a<b){
            int lo=1,hi=n;
            while(lo<hi){
                int mi=(lo+hi)>>1;
                int now=a,e=0;
                while(e<=max_bit(mi)){
                    if(mi&(1<<e)) now=str[now][e];
                    e++;
                }
                if(b<=now) hi=mi;
                else lo=mi+1;
            }
            cout<<lo<<"\n";
        }else{
            int lo=1,hi=n;
            while(lo<hi){
                int mi=(lo+hi)>>1;
                int now=a,e=0;
                while(e<=max_bit(mi)){
                    if(mi&(1<<e)) now=stl[now][e];
                    e++;
                }
                if(b>=now) hi=mi;
                else lo=mi+1;
            }
            cout<<lo<<"\n";
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

