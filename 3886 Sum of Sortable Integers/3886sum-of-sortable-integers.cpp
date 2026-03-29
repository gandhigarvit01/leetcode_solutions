class Solution {
public:
    int n;
    bool solve(vector<int>& nums, int k){
        int i = 0;
        int prev_max = -1;
        int curr_max = -1;
        int curr_min = INT_MAX;
        for(i=0; i<k; i++){
            if(nums[i]<curr_min){
                curr_min = nums[i];
            }
            curr_max = max(curr_max, nums[i]);
        }
        int cnt = 0;
        for(int j=0; j<k; j++){
            int curr = nums[j];
            int nxt = nums[(j+1)%k];
            if(curr>nxt) cnt++;
        }
        if(cnt>1) return false;
        while(i < n){
            prev_max = curr_max;
            curr_max = -1;
            curr_min = INT_MAX;
            for(int j=0; j<k; j++){
                if(nums[i+j]<curr_min){
                    curr_min = nums[i+j];
                }
                curr_max = max(curr_max, nums[i+j]);
            }
            if(curr_min < prev_max) return false;
            cnt = 0;
            for(int j=0; j<k; j++){
                int curr = nums[(i+j)];
                int nxt = nums[i+(j+1)%k];
                if(curr>nxt) cnt++;
            }
            if(cnt>1) return false;
            i = i+k;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        n = nums.size();
        int ans = 0;
        for(int k=1; k<=n; k++){
            if(n % k == 0){
                if(solve(nums,k)) ans += k;
            }
        }
        return ans;
    }
};