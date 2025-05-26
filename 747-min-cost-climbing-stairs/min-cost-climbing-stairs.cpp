class Solution {
int mini = 1e7;
private:
    int find(int ind, vector<int>&cost, vector<int>&dp){
        if(ind<0) return 0;
        if(ind==0 || ind==1) return cost[ind];
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind] = cost[ind] + min(find(ind-1, cost, dp), find(ind-2, cost, dp));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> dp(size, -1);
        return min(find(size-1, cost, dp), find(size-2, cost, dp));
    }
};