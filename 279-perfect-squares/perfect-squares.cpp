class Solution {
private:
    int find(int n, vector<int>&dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans = INT_MAX;
        for(int i=1;i*i<=n;i++){
            ans = min(ans, (1 + find(n - (i*i), dp)));
        }
        return dp[n] = ans;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return find(n, dp);
    }
};