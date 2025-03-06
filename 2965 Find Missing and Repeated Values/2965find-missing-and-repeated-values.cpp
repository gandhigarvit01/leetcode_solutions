class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> v(2,0);
        set<int> s;
        int sum = 0;
        int n = grid.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                s.insert(grid[i][j]);
                sum += grid[i][j];
            }
        }
        int k = 0;
        for(int j : s){
            k += j;
        }
        int l = sum-k;
        int a = n*n;
        int r = (a*(a + 1))/2;
        int p = r-k;
        v[0] = l;
        v[1] = p;
        return v;
    }
};