class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s;
        int n = words.size();
        for(int i=0; i<n; i++){
            int m = words[i].size();
            int total = 0;
            for(int j=0; j<m; j++){
                int val = words[i][j]-'a';
                total += weights[val];
            }
            total = total%26;
            total = 25-total;
            char c = 'a' + total;
            s.push_back(c);
        }
        return s;
    }
};