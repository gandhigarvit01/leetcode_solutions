class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(m!=n) return false;
        bool ans = false;
        for(int i=0; i<n; i++){
            int match = 0;
            for(int j=0; j<n; j++){
                if(s[(j+i)%n]==goal[j]) match++;
            }
            if(match==n) return true;
        }
        return false;
    }
};