class Solution {
public:
    int N;
    double dp[30][30][105];
    double solve(int i, int j, int k){
        if(i < 0 || j < 0 || i >= N || j >= N) return 0;
        if(k==0){
            return 1;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        double rightup=0,rightdown=0,upright=0,upleft=0,downright=0,downleft=0,leftup=0,leftdown=0;
        if(j+2<N && i+1<N){
            rightdown = (1.0/8)*solve(i+1,j+2,k-1);
        }
        if(j+2<N && i-1>=0){
            rightup = (1.0/8)*solve(i-1,j+2,k-1);
        }
        if(j-2>=0 && i+1<N){
            leftdown = (1.0/8)*solve(i+1,j-2,k-1);
        }
        if(j-2>=0 && i-1>=0){
            leftup = (1.0/8)*solve(i-1,j-2,k-1);
        }
        if(j+1<N && i+2<N){
            downright = (1.0/8)*solve(i+2,j+1,k-1);
        }
        if(j-1>=0 && i+2<N){
            downleft = (1.0/8)*solve(i+2,j-1,k-1);
        }
        if(j+1<N && i-2>=0){
            upright = (1.0/8)*solve(i-2,j+1,k-1);
        }
        if(j-1>=0 && i-2>=0){
            upleft = (1.0/8)*solve(i-2,j-1,k-1);
        }
        return dp[i][j][k] = rightup + rightdown + leftup + leftdown + downleft + downright + upright + upleft;
    }

    double knightProbability(int n, int k, int row, int column) {
        N = n;
        for(int i = 0; i < 30; i++)
    for(int j = 0; j < 30; j++)
        for(int k = 0; k < 105; k++)
            dp[i][j][k] = -1.0;

        return solve(row,column,k);
    }
};