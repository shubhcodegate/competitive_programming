#include<iostream>
#include<vector>
using namespace std;

#define fastio()    ios_base::sync_with_stdio(false); cin.tie(NULL);
#define nline "\n"
#define ll long long
#define pb push_back
#define fo(i,l,r) for(int i=l;i<r;i++)
#define rfor(i,l,r) for(int i=r-1;i>=l;i--)
#ifdef shubhcodegate
#define debug(x) cerr << #x << " "; _print(x); cerr << nline;
#else
#define debug(x)
#endif

void _print(int x){cerr << x;}
void _print(string x){cerr << x;}
void _print(float x){cerr << x;}
void _print(double x){cerr << x;}
void _print(ll x){cerr << x;}
void _print(char x){cerr << x;}
void _print(bool x){cerr << x;}
template<class T> void _print(vector<T> x){
    cerr<<"[ ";
    for(auto a : x) { _print(a); cerr<<" ";}
    cerr<<"]";
}



void solve(){
    string s;
    cin >> s;
    if(s.length() > 10) {
        cout << s[0] << s.length() - 2 << s[s.length() - 1]<<nline;
    }
    else {
        cout << s <<nline;
    }
}

int main(){
    fastio();
#ifdef shubhcodegate
    freopen("error.txt", "w", stderr);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}