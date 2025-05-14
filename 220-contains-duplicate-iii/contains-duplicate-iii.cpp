class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());
        if(t==0 && nums.size()==st.size()) return false;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n && j<i+k+1;j++){
                if(abs((long long)nums[j] - nums[i])<=t)
                    return true;
            }
        }
        return false;
    }
};