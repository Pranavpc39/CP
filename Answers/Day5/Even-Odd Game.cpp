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
 
 
 
int n;
 
void solve(){
   
	cin>>n;
	ll a[n];

	priority_queue<ll> p1,p2;

	FOR(i,0,n){
		cin>>a[i];

		if(a[i]&1)
			p2.push(a[i]);
		else
			p1.push(a[i]);
	}

	ll alice =0 ,bob=0;
	FOR(i,0,n){

		if(i&1){

			if(!p2.empty()){

				if(!p1.empty() && p1.top()>p2.top())
					p1.pop();

				else{
					bob+=p2.top();
					p2.pop();
				}
			}
			else{
				p1.pop();
			}

		}
		else{
			if(!p1.empty()){

				if(!p2.empty() && p2.top()>p1.top())
					p2.pop();

				else{
					alice+=p1.top();
					p1.pop();
				}
			}
			else{
				p2.pop();
			}
		}

	}

	if(alice>bob)
		cout<<"Alice\n";
	else if(bob>alice)
		cout<<"Bob\n";
	else
		cout<<"Tie\n";
   
}
 
 
int main(){
 
    // startTime = clock();
    // #ifdef _DEBUG
    //     freopen("input.txt", "r", stdin);
    //     //    freopen("output.txt", "w", stdout);
    // #endif
    //     // init();
    T{
        solve();
    }
 
        // =================================== ****************===========================
 
    // }
}