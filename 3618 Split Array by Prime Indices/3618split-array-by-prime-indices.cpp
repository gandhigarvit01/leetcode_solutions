class Solution {
public:
    bool prime(int n){
        if(n < 2) return false;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return abs(nums[0] + nums[1]);
        }
        long long total = 0;
        long long primesum = 0;

        for(int i = 0; i < n; i++){
            total += nums[i];
        }
        for(int i = 2; i < n; i++){
            if(prime(i)){
                primesum += nums[i];
            }
        }
        long long remsum = total - primesum;
        return std::abs(remsum - primesum);
    }
};

