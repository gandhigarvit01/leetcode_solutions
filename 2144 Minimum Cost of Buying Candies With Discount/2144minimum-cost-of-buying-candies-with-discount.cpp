class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(),cost.end());
        int total = 0;
        int i = n-1;
        while(i>=0){
            total += cost[i];
            i--;
            if(i>=0) total += cost[i];
            i--; // free item if available;
            i--;
        } 
        return total;
    }
};