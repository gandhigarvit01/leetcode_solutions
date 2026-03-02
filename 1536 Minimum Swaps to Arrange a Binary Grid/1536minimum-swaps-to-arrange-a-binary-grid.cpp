class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trail_zeros(n+1,0);
        vector<int> vec(n,0);
        for(int i=0; i<n; i++){
            int zero = 0;
            for(int j=n-1; j>=0; j--){
                if(grid[i][j]==0) zero++;
                else break;
            }
            vec[i] = zero;
            trail_zeros[zero]++;
        }
        int sum = 0;
        for(int i=n; i>=0; i--){
            sum += trail_zeros[i];
            if(sum < n-i) return -1;
        }
        int swaps = 0;
        // calculating swaps - 
        for(int i=0; i<n; i++){
            int required = n-i-1;
            int j = i;
            for(j=i; j<n; j++){
                if(vec[j]>=required) break;
            }
            while(j>i){
                int temp = vec[j];
                vec[j] = vec[j-1];
                vec[j-1] = temp;
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};