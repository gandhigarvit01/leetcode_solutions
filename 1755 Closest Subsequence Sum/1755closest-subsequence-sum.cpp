class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;
        int n1 = n/2;
        int n2 = n - n1;
        for(int mask=0; mask<(1<<n1); mask++){
            int sum = 0;
            for(int i=0; i<n1; i++){
                if(mask & (1<<i)){
                    sum += nums[i];
                }
            }
            arr1.push_back(sum);
        }
        for(int mask=0; mask<(1<<n2); mask++){
            int sum = 0;
            for(int i=0; i<n2; i++){
                if(mask & (1<<i)){
                    sum += nums[n1+i];
                }
            }
            arr2.push_back(sum);
        }
        sort(arr2.begin(),arr2.end());
        int ans = INT_MAX;
        for(int i=0; i<(1<<n1); i++){
            int x = arr1[i];
            int need = goal - x;
            int idx = lower_bound(arr2.begin(), arr2.end(), need) - arr2.begin();
            int val;
            if(idx!=(1<<n2)){
                val = arr2[idx];
                ans = min(ans, abs((x+val)-goal));
            }
            if(idx>0){
                val = arr2[idx-1];
                ans = min(ans, abs((x+val)-goal));
            }
        }
        return ans;
    }
};