class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        st.insert(0);
        st.insert(n-1);
        int maxi = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]>maxi) st.insert(i);
            maxi = max(maxi, nums[i]);
        }
        maxi = nums[n-1];
        for(int i=n-2; i>=0; i--){
            if(nums[i]>maxi) st.insert(i);
            maxi = max(maxi, nums[i]);
        }
        vector<int> vec;
        for(int i=0; i<n; i++){
            if(st.find(i)!=st.end()){
                vec.push_back(nums[i]);
            }
        }
        return vec;
    }
};