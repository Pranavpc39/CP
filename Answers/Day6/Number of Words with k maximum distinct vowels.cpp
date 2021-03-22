#define ll long long int
#define MOD 1000000007



class Solution
{
public:

    ll power(ll x,ll y){
        ll ret = 1ll;
        x%=MOD;
        if(x==0) return 0;
        
        while(y>0){
            if(y&1)
                ret=(ret*x)%MOD;
            y>>=1;
            x=(x*x)%MOD;

        }
        return ret;
    }
    

    int kvowelwords(int N,int K)
    {
        // Write Your Code here
        
        ll dp[N+1][K+1]={0};
        
        ll sum = 1ll;
        
        for(ll i=1;i<=N;i++){
            dp[i][0] = ((21*sum)%MOD);
            sum = dp[i][0];
            for(ll j=1;j<=K;j++){
                if(j>i) dp[i][j] = 0;
                else if(i==j) dp[i][j] = power(5ll,i);
                else
                    dp[i][j] = (dp[i-1][j-1]*5);
                dp[i][j]%=MOD;
                sum+=dp[i][j];
                sum%=MOD;
            }
        }
        
        return (sum);
        
    }
};