class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0, y = 0;
        int xor_all = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            xor_all ^= nums[i];
        }
        long long mask = 1LL*xor_all & (-1LL*xor_all);
        for(int i=0; i<n; i++){
            if((mask & nums[i]) == 0){
                x ^= nums[i];
            }
            else y ^= nums[i];
        }
        return {x,y};
    }
};