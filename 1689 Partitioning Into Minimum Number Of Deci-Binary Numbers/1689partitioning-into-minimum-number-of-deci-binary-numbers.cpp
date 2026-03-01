class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        int m = n.size();
        for(int i=0; i<m; i++){
            int val = n[i]-'0';
            ans = max(ans,val);
        }
        return ans;
    }
};