class Solution {
public:
    bool isprime(int n){
        if(n<2) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            if(i%2==0){
                int k = nums[i];
                while(!isprime(k)){
                    k++;
                    ans++;
                }
            }
            else{
                if(isprime(nums[i])){
                    if(nums[i]==2) ans+=2;
                    else ans++;
                }
            }
        }
        return ans;
    }
};