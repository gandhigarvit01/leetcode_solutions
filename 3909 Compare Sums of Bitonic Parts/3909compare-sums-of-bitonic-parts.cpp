class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int idx;
        for(int i=1; i<n-1; i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                idx = i;
            }
        }
        long long asc_sum = 0;
        long long desc_sum = 0;
        for(int i=0; i<=idx; i++){
            asc_sum += nums[i];
        }
        for(int i=idx; i<n; i++){
            desc_sum += nums[i];
        }
        if(asc_sum < desc_sum) return 1;
        else if(asc_sum > desc_sum) return 0;
        return -1;
    }
};