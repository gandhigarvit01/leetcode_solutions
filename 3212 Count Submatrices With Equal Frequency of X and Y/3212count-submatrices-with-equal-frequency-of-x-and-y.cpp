class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int,int>>> vec(m, vector<pair<int,int>>(n, {0,0}));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='X'){
                    vec[i][j].first++;
                }
                else if(grid[i][j]=='Y'){
                    vec[i][j].second++;
                }
                if(j>0){
                    vec[i][j].first += vec[i][j-1].first;
                    vec[i][j].second += vec[i][j-1].second;
                }
            }
        }
        for(int j=0; j<n; j++){
            for(int i=1; i<m; i++){
                vec[i][j].first += vec[i-1][j].first;
                vec[i][j].second += vec[i-1][j].second;
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vec[i][j].first>0 && vec[i][j].first==vec[i][j].second){
                    ans++;
                }
            }
        }
        return ans;
    }
};