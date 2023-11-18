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
#define point complex<long long>
#define x real()
#define y imag()
using namespace std;

long long cross(point a,point b){
    return imag(conj(a)*b);
}
long long dot(point a,point b){
    return real(conj(a)*b);
}
long long n2(point a){
    return a.x*a.x+a.y*a.y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;
    int t;
    cin>>t;
    while(t--){
        point p[4];
        for(int i=0;i<4;i++){
            int u,v;
            cin>>u>>v;
            p[i]=point(u,v);
        }
        /*ll cs1=cross(p[2]-p[0],p[1]-p[0]),cs2=cross(p[0]-p[2],p[3]-p[2]);
        if(cs1*cs2>=0){
            ll cs=cs2*cross(p[1]-p[0],p[2]-p[3]);
            if(cs>0) cout<<"Hero\n";
            else if(cs<0) cout<<"Heroine\n";
            else cout<<"0\n";
        }else{
            cout<<"other\n";
        }*/
        ll d1=dot(p[2]-p[0],p[1]-p[0]),d2=dot(p[0]-p[2],p[3]-p[2]);
        if(d1*d2>=0){
            ll c1,c2;
            if(d1>0 || d2>0) c1=d1*d1*n2(p[3]-p[2]),c2=d2*d2*n2(p[1]-p[0]);
            else c1=d2*d2*n2(p[1]-p[0]),c2=d1*d1*n2(p[3]-p[2]);
            if(c1==c2) cout<<"0\n";
            else if(c1>c2) cout<<"Hero\n";
            else cout<<"Heroine\n";
    
        }else{
            if(d1>d2) cout<<"Hero\n";
            else cout<<"Heroine\n";
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

