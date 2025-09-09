class Solution {
public:
    bool isvalid(int n){
        int zeros = 0;
        while(n>0){
            int rem = n % 10;
            if(rem==0) return false;
            n = n/10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for(int i=1; i<n; i++){
            if(isvalid(i) && isvalid(n-i)){
                ans.push_back(i);
                ans.push_back(n-i);
                return ans;
            }
        }
        return {-1,-1};
    }
};