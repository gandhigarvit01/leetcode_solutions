class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();
        for(int i=1; i<n; i++){
            int curr = s[i]-'0';
            int prev = s[i-1]-'0';
            if(abs(curr-prev) > 2) return false;
        }
        return true;
    }
};