class Solution {
public:
    int digsum(int n){
        int sum=0;
        int rem=0;
        while(n>0){
            rem= n%10;
            sum += rem;
            n=n/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        map<int,multiset<int>> mpp;
        int n=nums.size();
        for(int i=0; i<n; i++){
            mpp[digsum(nums[i])].insert(nums[i]);
        }
        int maxi=0,cs=0;
        for(auto it:mpp){
            if(it.second.size()>1){
                auto l=it.second.end();
                l--;
                cs += *l;
                l--;
                cs += *l;
                maxi=max(maxi,cs);
                cs=0;
            }
        }
        if(maxi>0)
        return maxi;
        else
        return -1;
    }
};