class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0;
        int sum = 0;
        int n = arr.size();
        for(int i=0; i<=k-1; i++){
            sum += arr[i];
        }
        int l=0, r=k-1;
        if(sum >= k*threshold) ans++;
        r++;
        l++;
        while(r<n){
            sum -= arr[l-1];
            sum += arr[r];
            if(sum/k >= threshold) ans++;
            r++;
            l++;
        }
        return ans;
    }
};