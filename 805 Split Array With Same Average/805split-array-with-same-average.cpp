class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int n1 = n/2;
        int n2 = n - n1;
        int total = 0;
        for(int x : nums) total += x;
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
        for(int i=0; i<n2+1; i++){
            sort(arr2[i].begin(), arr2[i].end());
        }
        for(int i=0; i<=n1; i++){
            for(int s1 : arr1[i]){
                for(int j=0; j<=n2; j++){
                    int x = i + j;
                    if(x!=0 && x!=n && (total*x)%n==0){
                        int s2 = ((total*x)/n)-s1;
                        int idx = lower_bound(arr2[j].begin(), arr2[j].end(), s2) - arr2[j].begin();
                        if(idx!=arr2[j].size() && arr2[j][idx]==s2) return true;
                    }
                }
            }
        }
        return false;
    }
};