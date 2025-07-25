class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        int count = 0;
        int sum = 0;
        for(int it : st){
            if(it<0){
                count++;
            }
            else{
                sum += it;
            }
        }
        if(count==st.size()){
            return *st.rbegin();
        }
        return sum;
    }
};