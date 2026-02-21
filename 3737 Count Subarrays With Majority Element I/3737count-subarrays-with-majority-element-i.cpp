class Solution {
public:
    vector<int> segmentree;
    void build(int i, int l, int r, vector<int>& nums, int target){
        if(l==r){
            if(nums[l]==target) segmentree[i] = 1;
            else segmentree[i] = 0;
            return;
        }
        int mid = (l+r)/2;
        build(2*i+1,l,mid,nums,target);
        build(2*i+2,mid+1,r,nums,target);
        segmentree[i] = segmentree[2*i+1] + segmentree[2*i+2];
    }
    int solve(int i, int l, int r, int start, int end){
        if(start>r || l>end || l>r) return 0;
        if(l>=start && r<=end) return segmentree[i];
        int mid = (l+r)/2;
        int left = solve(2*i+1,l,mid,start,end);
        int right = solve(2*i+2,mid+1,r,start,end);
        return left + right;
    }
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        segmentree.resize(4*n);
        build(0,0,n-1,nums,target);
        int result = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int ans = solve(0,0,n-1,i,j);
                if(ans > (j-i+1)/2) result++;
            }
        }
        return result;
    }
};