class Solution {
public:
    int quickselect(vector<int>& nums, int L, int R){
        int i = L+1, j = R;
        int piv = nums[L];
        while(i<=j){
            if(nums[i]<piv && nums[j]>piv){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(nums[i]>=piv) i++;
            if(nums[j]<=piv) j--;
        }
        swap(nums[L],nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        int L = 0;
        int R = n-1;

        int piv_idx;
        while(true){
            piv_idx = quickselect(nums, L, R);
            if(piv_idx==k-1){
                break;
            }
            else if(piv_idx>k-1){
                R = piv_idx-1;
            }
            else{
                L = piv_idx+1;
            }
        }
        return nums[piv_idx];
    }
};