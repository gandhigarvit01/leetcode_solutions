class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int left = 0, right = 0, dash = 0;
        for(int i=0; i<n; i++){
            if(moves[i]=='L') left++;
            else if(moves[i]=='R') right++;
            else dash++;
        }
        return abs(left-right) + dash;
    }
};