class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans(amount+1,100000);
        int n = coins.size();
        ans[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<n; j++){
                if(i>=coins[j]){
                    ans[i] = min(ans[i],1+ans[i-coins[j]]);
                }
            }
        }
        return ans[amount]==100000?-1:ans[amount];
    }
};