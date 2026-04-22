class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> vec(26);
        int n = s.size();
        int m = t.size();
        for(int i=0; i<n; i++){
            vec[s[i]-'a']++;
        }
        for(int i=0; i<m; i++){
            vec[t[i]-'a']--;
        }
        int ans = 0;
        for(int i=0; i<26; i++){
            ans += abs(vec[i]);
        }
        return ans;
    }
};