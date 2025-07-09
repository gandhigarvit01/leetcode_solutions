class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(),costs.end());
        int bars = 0;
        for(int i=0; i<n; i++){
            if(coins>=costs[i]){
                bars ++;
                coins -= costs[i];
            }
        }
        return bars;
    }
};