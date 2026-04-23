class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n,0);
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            mpp[A[i]]++;
            mpp[B[i]]--;
            for(auto it : mpp){
                if(it.second==0){
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};