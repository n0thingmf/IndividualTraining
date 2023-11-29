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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> k(n),l(n),r(n);
        ll ans=0;
        int sz1=0;
        vector<pair<int,int>> s1,s2;
        for(int i=0;i<n;i++){
            cin>>k[i]>>l[i]>>r[i];
            int mi=min(l[i],r[i]);
            ans+=mi;
            l[i]-=mi;
            r[i]-=mi;
            if(l[i]>=0){
                sz1++;
                s1.pb({k[i],i});
            }
            if(r[i]>0){
                s2.pb({k[i]+1,i});
            }
        }
        sort(all(s1));
        sort(all(s2));
        priority_queue<int> w;
        for(int i=(int)s1.size()-1;i>=0;i--){
            if(s1[i].first<sz1){
                for(int j=0;j<sz1-s1[i].first && !w.empty();j++){
                    ans+=w.top();
                    w.pop();
                }
                sz1=s1[i].first;
            }
            w.push(l[s1[i].second]);
        }
        if(0<sz1){
            for(int j=0;j<sz1 && !w.empty();j++){
                ans+=w.top();
                w.pop();
            }
        }
        w=priority_queue<int>();
        int sz2=sz1+1;
        for(int i=0;i<(int)s2.size();i++){
            if(sz2<s2[i].first){
                for(int j=0;j<s2[i].first-sz2 && !w.empty();j++){
                    ans+=w.top();
                    w.pop();
                }
                sz2=s2[i].first;
            }
            w.push(r[s2[i].second]);
        }
        if(sz2<=n){
            for(int j=0;j<n-sz2+1 && !w.empty();j++){
                ans+=w.top();
                w.pop();
            }
        }
        cout<<ans<<"\n";
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

