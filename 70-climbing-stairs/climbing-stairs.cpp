class Solution {
private:
    int find(int n, vector<int>&dp){
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = find(n-1, dp) + find(n-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return find(n, dp);
    }
};