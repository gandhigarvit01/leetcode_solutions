class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr;
        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                arr.push_back(nums[i]);
            }
        }
        int m = arr.size();
        if(m==0) return nums;
        int l = k%m;
        if(l==0) return nums;
        vector<int> arr2(m);
        for(int i=0; i<m; i++){
            arr2[i] = arr[(i+l)%m];
        }
        int j = 0;
        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                nums[i] = arr2[j];
                j++;
            }
        }
        return nums;
    }
};