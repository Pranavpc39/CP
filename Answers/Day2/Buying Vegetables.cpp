class Solution{
public:
    int minCost(int N, vector<int> cost[]) {
        // code here
        
        int dp[N][3];
        
        for(int i=0;i<3;i++)
            dp[0][i] = cost[0][i];
        
        
        for(int i=1;i<N;i++){
            for(int j=0;j<3;j++){
                
                if(j==0)
                    dp[i][j] = cost[i][j] + min(dp[i-1][1],dp[i-1][2]);
                if(j==1)
                    dp[i][j] = cost[i][j] + min(dp[i-1][0],dp[i-1][2]);
                if(j==2)
                    dp[i][j] = cost[i][j] + min(dp[i-1][1],dp[i-1][0]);
                
                
            }
        }
        
        return min({dp[N-1][0],dp[N-1][1],dp[N-1][2]});
        
    }
};