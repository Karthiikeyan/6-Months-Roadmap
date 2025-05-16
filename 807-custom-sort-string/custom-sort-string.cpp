class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.size();
        vector<int> index(26, 26);
        for(int i=0;i<n;i++){
            index[order[i]-'a'] = i;
        }

        sort(s.begin(), s.end(), [&](char a, char b) {
            return index[a - 'a'] < index[b - 'a'];
        });

        return s;
    }
};