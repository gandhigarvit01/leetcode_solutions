class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string k;
        int m = INT_MAX;
        for(int i=0; i<n; i++){
            m = min(m, (int)strs[i].size());
        }
        for(int i=0; i<m; i++){
            char c = strs[0][i];
            int match = 0;
            for(int j=0; j<n; j++){
                if(strs[j][i]==c) match++;
            }
            if(match==n){
                k.push_back(c);
            }
            else return k;
        }
        return k;
    }
};