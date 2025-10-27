class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        int n = operations.size();
        for(int i=0; i<n; i++){
            if(operations[i][1]=='-'){
                ans--;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};