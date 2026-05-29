class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<int>> mpp;
        for(int i=0; i<n; i++){
            string k = strs[i];
            sort(k.begin(),k.end());
            mpp[k].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it : mpp){
            vector<int> vec = it.second;
            vector<string> res;
            for(int x : vec){
                res.push_back(strs[x]);
            }
            ans.push_back(res);
        }
        return ans;
    }
};