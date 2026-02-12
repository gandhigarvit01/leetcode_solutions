class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            unordered_map<char,int> mpp;
            for(int j=i; j<n; j++){
                mpp[s[j]]++;
                int freq = mpp.begin()->second;
                int diff = 0;
                for(auto &it : mpp){
                    if(it.second != freq) diff++;
                }
                if(diff==0) ans = max(ans, j-i+1);
            }
        }
        return ans;
    }
};