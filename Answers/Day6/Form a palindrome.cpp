class Solution{   
public:
    int findMinInsertions(string S){
        // code here 
        
        int n= S.size();
        
        int dp[n][n];
        
        for(int gap = 0;gap<n;gap++){
            for(int i=0;i+gap<n;i++){
                int j = i+gap;
                
                if(i==j)
                    dp[i][j] = 0;
                else if(gap==1){
                    if(S[i]==S[j])
                        dp[i][j] = 0;
                    else
                        dp[i][j] = 1;
                }
                else{
                    if(S[i] == S[j])
                        dp[i][j] = dp[i+1][j-1];
                    else
                        dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;
                }
                
            }
        }
        
        return dp[0][n-1];
        
        
    }
};