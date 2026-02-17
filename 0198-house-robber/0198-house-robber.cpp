class Solution {
public:
    int Points(int ind, vector<int>& nums, vector<int>&dp){
       if(ind<0) return 0;
       if(dp[ind] != -1) return dp[ind];

       int take = nums[ind]+Points(ind-2, nums, dp);
       int notTake = Points(ind-1, nums, dp);
       return dp[ind] = max(take, notTake);
    }

    int rob(vector<int>& nums) {  
        int n = nums.size();
        // vector<int>dp(n+1, -1);
        // return Points(n-1, nums, dp);  
        //Tabulation
        // if(n == 1) return nums[0];

        // vector<int>dp(n,0);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);

        // for(int i = 2; i < n; i++){
        //     int take = nums[i] + dp[i-2];
        //     int notTake = dp[i-1];
        //     dp[i] = max(take, notTake);
        // }
        // return dp[n-1];

        //Space Optimisation
        if(n == 1) return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for(int i = 2; i<n; i++){
            int take = nums[i]+prev2;
            int notTake = prev1;
            int current = max(take, notTake);
            prev2 = prev1;
            prev1 = current;
        }
             return prev1;
    }
  

};