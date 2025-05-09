class Solution {
    int n;
private:
    int globalInversions(vector<int>&nums){
        set<int> st;
        int ans = 0;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
            int val = distance(st.upper_bound(nums[i]), st.end());
            ans += val;
        }
        return ans;
    }
    int localInversions(vector<int>&nums){
        int cnt = 0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]) cnt+=1;
        }
        return cnt;
    }
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (abs(nums[i] - i) > 1)
                return false;
        }
        return true;
    }
};