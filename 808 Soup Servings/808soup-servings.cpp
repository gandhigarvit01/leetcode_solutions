class Solution {
public:
    vector<vector<double>> dp;
    double solve(int i, int j){
        if(i<=0 && j<=0) return 0.5;
        if(i<=0 && j>0)  return 1.0;
        if(j<=0 && i>0)  return 0.0;

        if(dp[i][j]!=-1.0){
            return dp[i][j];
        }

        double p1=0,p2=0,p3=0,p4=0;

        p1 += (0.25)*solve(i-100,j);
        p2 += (0.25)*solve(i-75,j-25);
        p3 += (0.25)*solve(i-50,j-50);
        p4 += (0.25)*solve(i-25,j-75);
        
        return dp[i][j] = p1+p2+p3+p4;
    }
    double soupServings(int n) {
        if(n>=5000) return 1.0;
        dp = vector<vector<double>>(n+1, vector<double>(n+1, -1.0));
        return solve(n,n);
    }
};