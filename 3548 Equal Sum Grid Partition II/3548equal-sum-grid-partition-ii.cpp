class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // pre_sum vector ----------------------------------------------
        vector<vector<long long>> pre(m, vector<long long>(n,0));
        long long total = 0;
        unordered_map<long long,vector<pair<int,int>>> mpp;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mpp[grid[i][j]].push_back({i,j});
                total += grid[i][j];
                pre[i][j] = grid[i][j];
                if(i>0) pre[i][j] += pre[i-1][j];
                if(j>0) pre[i][j] += pre[i][j-1];
                if(i>0 && j>0) pre[i][j] -= pre[i-1][j-1];
            }
        }
        if(m==1){
            for(int j=0; j<n-1; j++){
                long long l_s = pre[0][j];
                long long r_s = total - l_s;
                if(l_s==r_s) return true;
                if(l_s>r_s && (l_s-grid[0][0]==r_s || l_s-grid[0][j]==r_s)) return true;
                if(r_s>l_s && (r_s-grid[0][n-1]==l_s || r_s-grid[0][j+1]==l_s)) return true; 
            }
            return false;
        }
        if(n==1){
            for(int i=0; i<m-1; i++){
                long long t_s = pre[i][0];
                long long b_s = total - t_s;
                if(t_s==b_s) return true;
                if(t_s>b_s && (t_s-grid[0][0]==b_s || t_s-grid[i][0]==b_s)) return true;
                if(b_s>t_s && (b_s-grid[m-1][0]==t_s || b_s-grid[i+1][0]==t_s)) return true;
            }
            return false;
        }
        // horizontal cut -----------------------------------------------
        long long top_sum, bottom_sum, xtra;
        for(int i=0; i<m-1; i++){
            top_sum = pre[i][n-1];
            bottom_sum = total - top_sum;
            if(top_sum==bottom_sum) return true;
            else if(top_sum > bottom_sum){
                if(i==0){
                    if(top_sum-grid[0][0]==bottom_sum || top_sum-grid[0][n-1]==bottom_sum) return true;
                }
                else{
                    xtra = top_sum - bottom_sum;
                    if(mpp.find(xtra)!=mpp.end()){
                        int k = mpp[xtra].size();
                        for(int idx=0; idx<k; idx++){
                            int x = mpp[xtra][idx].first;
                            if(x<=i) return true;
                        }
                    }
                }  
            }
            else{
                if(i==m-2){
                    if(top_sum==bottom_sum-grid[m-1][0] || top_sum==bottom_sum-grid[m-1][n-1]) return true;
                }
                else{
                    xtra = bottom_sum - top_sum;
                    if(mpp.find(xtra)!=mpp.end()){
                        int k = mpp[xtra].size();
                        for(int idx=0; idx<k; idx++){
                            int x = mpp[xtra][idx].first;
                            if(x>i) return true;
                        }
                    }
                }
            }
        }
        // vertical cut -------------------------------------------------------
        long long left_sum, right_sum;
        for(int j=0; j<n-1; j++){
            left_sum = pre[m-1][j];
            right_sum = total - left_sum;
            if(left_sum==right_sum) return true;
            else if(left_sum > right_sum){
                if(j==0){
                    if(left_sum-grid[0][0]==right_sum || left_sum-grid[m-1][0]==right_sum) return true;
                }
                else{
                    xtra = left_sum - right_sum;
                    if(mpp.find(xtra)!=mpp.end()){
                        int k = mpp[xtra].size();
                        for(int idx=0; idx<k; idx++){
                            int y = mpp[xtra][idx].second;
                            if(y<=j) return true;
                        }
                    }
                }  
            }
            else{
                if(j==n-2){
                    if(left_sum==right_sum-grid[0][n-1] || left_sum==right_sum-grid[m-1][n-1]) return true;
                }
                else{
                    xtra = right_sum - left_sum;
                    if(mpp.find(xtra)!=mpp.end()){
                        int k = mpp[xtra].size();
                        for(int idx=0; idx<k; idx++){
                            int y = mpp[xtra][idx].second;
                            if(y>j) return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};