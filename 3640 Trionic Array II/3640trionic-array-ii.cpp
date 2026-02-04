class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long ans = LLONG_MIN;
        long long curr = nums[0], curr2 = 0;
        int n = nums.size(), p = 0, q = 0;
        for(int i=1; i<n-1; i++){
            if(nums[i]>nums[i-1] && nums[i+1]>nums[i]){          //  increasing 
                if(p==0){
                    if(curr<0) curr = nums[i];
                    else curr += nums[i];
                }
                else{
                    if(curr2<0) curr2 = nums[i];
                    else curr2 += nums[i];
                    curr += nums[i];
                    ans = max(ans,curr);
                }
            }
            else if(nums[i]<nums[i-1] && nums[i+1]<nums[i]){     //  decreasing
                curr += nums[i];
            }
            else if(nums[i]>nums[i-1] && nums[i]>=nums[i+1]){    //  peak
                p++;
                if(p==1) curr += nums[i];
                else if(p==2){
                    curr += nums[i];
                    curr2 += nums[i];
                    ans = max(ans,curr);
                    p = 1, curr = curr2;
                }
            }
            else if(nums[i]<nums[i-1] && nums[i]<nums[i+1]){    //  trough
                q++;
                if(q==1 && p==0) curr = nums[i];
                else{
                    curr += nums[i];
                    curr2 = nums[i];
                }
            }
            else{                                               //  start point
                p = 0, q = 0;
                curr = nums[i];
            }
        }
        if(p>=1 && q>=1 && nums[n-1]>nums[n-2]){
            curr += nums[n-1];
            ans = max(ans,curr);
        }
        return ans;
    }
};