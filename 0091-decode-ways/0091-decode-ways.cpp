class Solution {
public:
    //Recursion
    int countDecode(int ind, string s, vector<int>&dp){
        if(ind == s.length()) return 1;
        if(s[ind] == '0') return 0;
        if(dp[ind] != -1) return dp[ind];
        int count = countDecode(ind+1, s, dp);
        if(ind+1 < s.length() && (s[ind] =='1' || (s[ind] == '2' && s[ind+1] <= '6'))){
            count += countDecode(ind+2, s, dp);
        } 
        return dp[ind] = count;
    }

    int numDecodings(string s) {
        int len = s.length();
        if(s[0] == '0') return 0;
        //vector<int>dp(len+1, 0);
        //dp[len] = 1;
        //dp[len-1] = s[len-1] == '0' ? 0:1;
        // vector<int>dp(len, -1);
        // return countDecode(0, s, dp);
        int next1 = 1;
        int next2 = 1;
        for(int ind = len-1; ind>=0; ind--){
            int current = 0;
            if(s[ind] != '0'){
              
                current = next1;
                if(ind+1 < s.length() && (s[ind] =='1' || (s[ind] == '2' && s[ind+1] <= '6'))){
                current += next2;
        } 
            }
            next2 = next1;
            next1 = current;
        }
        return next1;
    }
};