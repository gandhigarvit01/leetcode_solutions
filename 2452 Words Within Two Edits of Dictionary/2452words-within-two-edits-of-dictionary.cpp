class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries.size();
        int m = dictionary.size();
        vector<string> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int edits = 0;
                string s = queries[i];
                string t = dictionary[j];
                for(int k=0; k<s.size(); k++){
                    if(s[k]!=t[k]) edits++;
                    if(edits > 2) break;
                }
                if(edits <= 2){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};