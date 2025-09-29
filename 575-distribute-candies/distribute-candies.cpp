class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> st;
        for(auto it: candyType){
            st.insert(it);
        }
        if(st.size()<n/2) return st.size();
        return n/2;
    }
};