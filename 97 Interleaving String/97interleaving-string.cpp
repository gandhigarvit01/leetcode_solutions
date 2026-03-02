class Solution {
public:
    int n,m,o;
    vector<vector<int>> dp;
    bool solve(string& s1, string& s2, string& s3, int i, int j, int k){
        if(i==n){
            while(j<m){
                if(s2[j]!=s3[k]) return false;
                j++, k++;
            }
            return true;
        }
        if(j==m){
            while(i<n){
                if(s1[i]!=s3[k]) return false;
                i++, k++;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s3[k] && s2[j]==s3[k]){
            return dp[i][j] = solve(s1,s2,s3,i+1,j,k+1) || solve(s1,s2,s3,i,j+1,k+1);
        }
        else if(s1[i]==s3[k]){
            return dp[i][j] = solve(s1,s2,s3,i+1,j,k+1);
        }
        else if(s2[j]==s3[k]){
            return dp[i][j] = solve(s1,s2,s3,i,j+1,k+1);
        }
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();
        o = s3.size();
        if(o!=m+n) return false;
        if(s1+s2==s3 || s2+s1==s3) return true;
        dp.assign(n+1, vector<int>(m+1, -1));
        return solve(s1,s2,s3,0,0,0);
    }
};