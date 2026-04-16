class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        unordered_map<int,vector<int>> mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]].push_back(i);
        }
        vector<int> vec(n,0);
        for(int i=0; i<n; i++){
            int idx = i;
            int val = nums[i];
            int dist = INT_MAX;
            auto it = lower_bound(mpp[val].begin(), mpp[val].end(), idx);
            if(it!=mpp[val].begin()){
                it--;
                int v = *it;
                dist = min(dist, abs(idx-v));
                it++;
            }
            else{
                int v = mpp[val][mpp[val].size()-1];
                if(v!=idx){
                    dist = min(dist, n-abs(idx-v));
                }
            }
            it++;
            if(it!=mpp[val].end()){
                int v = *it;
                dist = min(dist, abs(idx-v));
            }
            else{
                int v = mpp[val][0];
                if(v!=idx){
                    dist = min(dist, n-abs(idx-v));
                }
            }
            vec[i] = dist==INT_MAX?-1:dist;
        }
        vector<int> ans(m);
        for(int i=0; i<m; i++){
            ans[i] = vec[queries[i]];
        }
        return ans;
    }
};