class Solution {
public:
    int mod = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int sum = 0;
        vector<int> vec;
        for(int i=0; i<n; i++){
            sum = 0;
            for(int j=i; j<n; j++){
                sum = (sum + nums[j]) % mod;
                vec.push_back(sum);
            }
        }
        sort(vec.begin(),vec.end());
        int ans = 0;
        for(int i=left-1; i<=right-1; i++){
            ans = (ans + vec[i]) % mod;
        }
        return ans;
    }
};