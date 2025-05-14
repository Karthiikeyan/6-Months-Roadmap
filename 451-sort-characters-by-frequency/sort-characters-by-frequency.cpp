class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int>mpp;
        for(auto str: s){
            mpp[str]++;
        }
        vector<pair<int, char>> ch;
        for(auto it: mpp){
            ch.push_back({it.second, it.first});
        }
        sort(ch.rbegin(), ch.rend());

        string ans = "";
        for(auto it: ch){
            int cnt = it.first;
            char word = it.second;
            while(cnt--) ans+=word;
        }
        return ans;
    }
};