class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        int even = 0;
        int odd = 0;
        for(int x=0; x<=k-1; x++){
            for(int y=0; y<=k-1; y++){
                even = 0;
                odd = 0;
                if(x!=y){
                    for(int i=0; i<n; i++){
                        if(i%2==0){
                            int rem1 = nums[i]%k;
                            even += min(abs(rem1-x), k-abs(rem1-x));
                        }
                        else{
                            int rem2 = nums[i]%k;
                            odd += min(abs(rem2-y), k-abs(rem2-y));
                        }
                    }
                    ans = min(ans, even+odd);
                }
            }
        }
        return ans;
    }
};