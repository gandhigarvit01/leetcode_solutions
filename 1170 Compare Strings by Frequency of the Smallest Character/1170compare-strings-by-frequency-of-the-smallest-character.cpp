class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = queries.size();
        int m = words.size();
        vector<int> vec1(n,0);
        vector<int> vec2(m,0);
        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            string s = queries[i];
            vector<int> vec(26,0);
            for(int j=0; j<s.size(); j++){
                vec[s[j]-'a']++;
            }
            for(int j=0; j<26; j++){
                if(vec[j]!=0){
                    vec1[i] = vec[j];
                    break;
                }
            }
        }
        for(int i=0; i<m; i++){
            string s = words[i];
            vector<int> vec(26,0);
            for(int j=0; j<s.size(); j++){
                vec[s[j]-'a']++;
            }
            for(int j=0; j<26; j++){
                if(vec[j]!=0){
                    vec2[i] = vec[j];
                    break;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vec2[j] > vec1[i]) ans[i]++;
            }
        }
        return ans;
    }
};