class Solution {

private:
    int solve(int n, vector<int>&dp){
        //Recursion
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        for(int i = 1; i*i <= n; i++){
            ans = min(ans, 1 + solve(n - i*i, dp));
        }
        return dp[n]= ans;
    }

public:
    int numSquares(int n) {
        // For recursion and Memorization
        // vector<int>dp(n+1, -1);
        // return solve(n, dp);


        //Tabulation
        vector<int>dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j*j <= i; j++){
              dp[i] = min(dp[i], 1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};