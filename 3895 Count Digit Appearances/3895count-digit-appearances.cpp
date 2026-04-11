class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int m = nums[i];
            while(m>0){
                int rem = m % 10;
                m = m/10;
                if(rem==digit) ans++;
            }
        }
        return ans;
    }
};