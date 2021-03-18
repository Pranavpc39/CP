class Solution{   
public:
    bool is1winner(int n,int a[]) {
        
        // code here
        
        pair<int,int> dp[n][n];
        
        for(int i=0;i<n;i++){
                dp[i][i] = {a[i],0};
        }
        
        for(int i=0;i<n-1;i++){
            dp[i][i+1] = {max(a[i],a[i+1]),min(a[i],a[i+1])};
        }
        
        
        for(int gap = 2;gap<n;gap++){
            for(int i=0;i<n-gap;i++){
                int j = i+gap;
                
                if(a[i]+dp[i+1][j].second > a[j]+dp[i][j-1].second){
                    dp[i][j].first = a[i]+ dp[i+1][j].second;
                    dp[i][j].second = dp[i+1][j].first;
                }
                else{
                    dp[i][j].first = a[j]+dp[i][j-1].second;
                    dp[i][j].second = dp[i][j-1].first;
                }
                
            }
        }
        
        return dp[0][n-1].first>=dp[0][n-1].second;
        
        
    }
};