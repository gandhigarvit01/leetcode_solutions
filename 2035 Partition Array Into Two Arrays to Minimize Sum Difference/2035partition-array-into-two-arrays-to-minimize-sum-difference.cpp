class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m = n/2;
        int total = 0;
        for(int x : nums) total += x;
        int n1 = m;
        int n2 = m;
        vector<int> arr1[n1+1];
        vector<int> arr2[n2+1];
        for(int mask=0; mask<(1<<n1); mask++){
            int sum = 0;
            int num = 0;
            for(int i=0; i<n1; i++){
                if(mask & (1<<i)){
                    sum += nums[i];
                    num++;
                }
            }
            arr1[num].push_back(sum);
        } 
        for(int mask=0; mask<(1<<n2); mask++){
            int sum = 0;
            int num = 0;
            for(int i=0; i<n2; i++){
                if(mask & (1<<i)){
                    sum += nums[n1+i];
                    num++;
                }
            }
            arr2[num].push_back(sum);
        }
        for(int i=0; i<n2; i++){
            sort(arr2[i].begin(), arr2[i].end());
        }
        int ans = INT_MAX;
        for(int i=0; i<n1; i++){
            for(int s1 : arr1[i]){
                int j = m - i;
                int need = (total/2) - s1;
                int idx = lower_bound(arr2[j].begin(), arr2[j].end(), need) - arr2[j].begin();
                if(idx!=arr2[j].size()){
                    int sum = s1 + arr2[j][idx];
                    int rem = total - sum;
                    ans = min(ans, abs(sum-rem));
                }
                if(idx>0){
                    int sum = s1 + arr2[j][idx-1];
                    int rem = total - sum;
                    ans = min(ans, abs(sum-rem));
                }
            }
        }
        return ans;
    }
};