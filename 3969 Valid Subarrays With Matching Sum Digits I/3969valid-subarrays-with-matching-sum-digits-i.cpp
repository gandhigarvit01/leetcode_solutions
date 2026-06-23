class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        long long sum = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum%10 == x){
                    string s = to_string(sum);
                    if(s[0]-'0' == x) ans++;
                }
            }
        }
        return ans;
    }
};