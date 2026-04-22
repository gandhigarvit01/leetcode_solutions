class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int,int,int>> vec;
        for(int i=0; i<n; i++){
            int num = nums[i];
            int sum = 0;
            while(num>0){
                int rem = num % 10;
                sum += rem;
                num = num/10;
            }
            vec.push_back({sum,nums[i],i});
        }
        sort(vec.begin(),vec.end());
        int swaps = 0;
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            int idx = get<2>(vec[i]);
            int val = get<1>(vec[i]);
            mpp[val] = idx;
        }
        for(int i=0; i<n; i++){
            int val = get<1>(vec[i]);
            int idx = mpp[val];
            int curr = nums[i];
            if(i != idx){
                swaps++;
                mpp[curr] = idx;
                nums[idx] = curr;
                nums[i] = val;
            }
        }
        return swaps;
    }
};