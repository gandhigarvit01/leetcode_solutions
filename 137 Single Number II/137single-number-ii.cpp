class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = 0;
        int n = nums.size();
        for(int i=0; i<32; i++){
            int cnt = 0;
            for(int j=0; j<n; j++){
                if(((nums[j]>>i)&1) == 1) cnt++;
            }
            if(cnt%3 != 0){
                num |= (1<<i);
            }
        }
        return num;
    }
};