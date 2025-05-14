class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto value: freq){
            int count = value.second;
            int num = value.first;
            v.push_back({count, num});
        }

        sort(v.rbegin(), v.rend());
        int cnt = 0, ans = 0;
        for(int i=0;i<n;i++){
            if(cnt>=(n/2)) break;
            cnt += v[i].first;
            ans += 1;
        }
        return ans;
    }
};