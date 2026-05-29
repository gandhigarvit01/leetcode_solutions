class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> mpp;
        int l=0, r=0;
        int ans = INT_MIN;
        while(r<n){
            char ch = s[r];
            if(mpp[ch]==0){
                mpp[ch]++;
                r++;
                ans = max(ans, r-l);
            }
            else{
                while(s[l]!=ch){
                    mpp[s[l]]--;
                    l++;
                }
                l++;
                r++;
                ans = max(ans, r-l);
            }
        }
        return ans==INT_MIN?0:ans;
    }
};