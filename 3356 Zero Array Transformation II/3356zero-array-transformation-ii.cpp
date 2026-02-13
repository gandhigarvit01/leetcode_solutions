class Solution {
public:
    int n,q;
    bool check(vector<int>& nums, vector<vector<int>>& queries, int idx){
        vector<int> vec(n,0);
        for(int i=0; i<=idx; i++){
            int start = queries[i][0];
            int end = queries[i][1]+1;
            int val = queries[i][2];
            vec[start] -= val;
            if(end<n){
                vec[end] += val;
            }
        }
        for(int i=1; i<n; i++){
            vec[i] += vec[i-1];
        }
        for(int i=0; i<n; i++){
            if(nums[i]+vec[i]>0){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        q = queries.size();
        int zeros = 0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) zeros++;
        }
        if(zeros==n) return 0;
        int ans = INT_MAX;
        int l=0, r=q-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(nums,queries,mid)){
                ans = min(ans,mid+1);
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};