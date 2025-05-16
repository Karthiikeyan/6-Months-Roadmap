class Solution {
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char, vector<int>> mpp;
        int siz = votes[0].size();
        for(char i='A';i<='Z';i++){
            vector<int> temp(siz, 0);
            mpp[i] = temp;
        }
        int n = votes.size();
        for(int i=0;i<n;i++){
            string s = votes[i];
            for(int j=0;j<siz;j++){
                mpp[s[j]][j]++;
            }
        }

        string ans = votes[0];
        sort(ans.begin(), ans.end(), [&](char &a, char &b){
            for(int i=0;i<siz;i++){
                if(mpp[a][i] == mpp[b][i]) continue;
                else if(mpp[a][i] > mpp[b][i]) return true;
                else return false;
            }
            return a < b;
        });
        return ans;
    }
};