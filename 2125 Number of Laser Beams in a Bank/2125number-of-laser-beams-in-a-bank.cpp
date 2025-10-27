class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size();
        int ans = 0;
        int k = 0;
        int n = bank[0].size();
        for(int i=0; i<m; i++){
            int ones = 0;
            for(int j=0; j<n; j++){
                if(bank[i][j]=='1'){
                    ones++;
                }
            }
            if(ones>0){
                if(k>0){
                    ans += k*ones;
                }
                k = ones;
            }
        }
        return ans;
    }
};