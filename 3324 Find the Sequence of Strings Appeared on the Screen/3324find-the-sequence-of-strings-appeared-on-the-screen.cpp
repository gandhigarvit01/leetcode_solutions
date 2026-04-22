class Solution {
public:
    vector<string> stringSequence(string target) {
        int n = target.size();
        string s = "a";
        vector<string> ans;
        ans.push_back(s);
        for(int i=0; i<n; i++){
            while(s[i]<target[i]){
                char c = s[i];
                c++;
                s[i] = c;
                ans.push_back(s);
            }
            s.push_back('a');
            ans.push_back(s);
        }
        ans.pop_back();
        return ans;
    }
};