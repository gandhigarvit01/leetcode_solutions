class Solution {
public:
    int gcd(int a, int b){
        while(b!=0){
            int r = a%b;
            a=b;
            b=r;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi,nums[i]);
            nums[i] = gcd(maxi,nums[i]);
        }
        sort(nums.begin(),nums.end());
        int l=0, r=n-1;
        while(l<r){
            ans += gcd(nums[l],nums[r]);
            l++;
            r--;
        }
        return ans;
    }
};