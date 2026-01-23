class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int maxi = INT_MIN;
        int n = arr.size();
        for(int i=0; i<n; i++){
            maxi = max(maxi,arr[i]);
        }
        if(k>=n) return maxi;
        int total = 0;
        int winner = arr[0];
        for(int i=1; i<n; i++){
            if(winner>arr[i]){
                total++;
                if(total==k){
                    return winner;
                }
            }
            else{
                winner = arr[i];
                total = 1;
                if(total==k) return winner;
            }
        }
        return maxi;
    }
};