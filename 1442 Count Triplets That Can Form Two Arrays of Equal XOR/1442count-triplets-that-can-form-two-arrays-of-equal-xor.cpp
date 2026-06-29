class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=1; i<n; i++){
            arr[i] ^= arr[i-1];
        }
        for(int i=0; i<n-1; i++){
            for(int k=i+1; k<n; k++){
                int a = 0;
                if(i-1>=0) a = arr[i-1];
                int b = arr[k];
                if(a==b) ans += k-i;
            }
        }
        return ans;
    }
};