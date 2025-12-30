class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m<3 || n<3){
            return 0;
        }
        int answer = 0;
        vector<int> numbers(16,0);
        for(int i=2; i<m; i++){
            for(int j=2; j<n; j++){
                for(int k=1; k<=9; k++){
                    numbers[k] = 0;
                }
                numbers[grid[i-2][j-2]]++;
                numbers[grid[i-2][j-1]]++;
                numbers[grid[i-2][j]]++;
                numbers[grid[i-1][j-2]]++;
                numbers[grid[i-1][j-1]]++;
                numbers[grid[i-1][j]]++;
                numbers[grid[i][j-2]]++;
                numbers[grid[i][j-1]]++;
                numbers[grid[i][j]]++;

                int ones = 0;
                for(int k=1; k<=9; k++){
                    if(numbers[k]==1){
                        ones++;
                    }
                }
                int r1 = grid[i-2][j-2] + grid[i-2][j-1] + grid[i-2][j];
                int r2 = grid[i-1][j-2] + grid[i-1][j-1] + grid[i-1][j];
                int r3 = grid[i][j-2] + grid[i][j-1] + grid[i][j];
                int c1 = grid[i-2][j-2] + grid[i-1][j-2] + grid[i][j-2];
                int c2 = grid[i-2][j-1] + grid[i-1][j-1] + grid[i][j-1];
                int c3 = grid[i-2][j] + grid[i-1][j] + grid[i][j];
                int d1 = grid[i-2][j-2] + grid[i-1][j-1] + grid[i][j];
                int d2 = grid[i][j-2] + grid[i-1][j-1] + grid[i-2][j];

                bool issumsame = false;
                if(r1==r2 && r2==r3 && r3==c1 && c1==c2 && c2==c3 && c3==d1 && d1==d2){
                    issumsame = true;
                }

                if(issumsame && ones==9){
                    answer++;
                }
            }
        }
        return answer;
    }
};