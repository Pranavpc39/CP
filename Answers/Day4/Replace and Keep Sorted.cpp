#include<bits/stdc++.h>
using namespace std;
 
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
    #define eprintf(...) 42
#endif
 
#define endl '\n'
#define ll int64_t
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define yyy cout<<"YES\n"
#define nnn cout<<"NO\n"
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define T int t;cin >> t;while(t--)
 
 
const ll MAX = 1e7 + 7;
const ll mod = 1e9+7;
ll xyp(ll x,ll y){if(y == 0) return 1LL;if(y == 1) return x;if(y % 2){ll p = xyp(x,y - 1);return (x * p) % mod;}ll p = xyp(x,y / 2);return (p * p) % mod;}
ll inv(ll x){return xyp(x,mod - 2);}
ll fact[MAX];void init(){fact[0] = 1;for(ll i = 1;i < MAX;i++){fact[i] = (fact[i - 1] * i) % mod;}}
ll ncr(ll n,ll r){if(r < 0 || n < 0) return 0LL;if(r == 0 || n == r) return 1LL;if(r == 1 || ((n - r) == 1)) return n;ll p = (((fact[n] * inv(fact[r])) % mod) * inv(fact[n - r])) % mod;return p;}
 
void read_arr(int a[],int n){
    FOR(i,0,n) cin>>a[i];
}
 
void write_arr(int a[],int n){
 
    FOR(i,0,n) cout<<a[i]<<" ";
    cout<<'\n';
}
 
 
 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
 
 
clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
 
 
 
 

int n,q,k; 
 
void solve(){
   
	cin>>n>>q>>k;

	int a[n];
	FOR(i,0,n)
		cin>>a[i];

	ll pre[n];

	pre[0] = a[1]-2;

	ll sum = pre[0];

	FOR(i,1,n-1){
		int l = a[i-1],r=a[i+1];
		sum+=(r-l-2);
		pre[i] = sum;
	}

	pre[n-1] = pre[n-2]+k-a[n-2]-1;

	while(q--){
		int x,y;
		ll ans = 0;

		cin>>x>>y;

		x--,y--;
		
		if(x==y){
		    cout<<k-1<<endl;
		    continue;
		}

		ans = pre[y-1]-pre[x];
		
		ans+=(a[x+1]-2);

		ans+=(k-a[y-1]-1);

		cout<<ans<<endl;

	}
   
}
 
 
int main(){
 
    // startTime = clock();
    // #ifdef _DEBUG
    //     freopen("input.txt", "r", stdin);
    //     //    freopen("output.txt", "w", stdout);
    // #endif
    //     // init();
    // T{
        solve();
    // }
 
        // =================================== ****************===========================
 
    // }
}