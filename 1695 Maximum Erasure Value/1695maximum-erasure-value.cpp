class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=0;
        set<int> st;
        int maxi = 0;
        int sum = 0;
        while(j<n){
            if(st.find(nums[j])==st.end()){
                st.insert(nums[j]);
                sum += nums[j];
                maxi = max(maxi,sum);
                j++;
            }
            else{
                while(i<=j){
                    if(nums[i]!=nums[j]){
                        sum -= nums[i];
                        st.erase(nums[i]);
                        i++;
                    }
                    else{
                        i++;
                        j++;
                        break;
                    }
                }
            }
        }
        return maxi;
    }
};