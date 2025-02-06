class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int c=0;
        int k=0;
        map<int,int> mpp;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                ans=nums[i]*nums[j];
                mpp[ans]++;
            }
        }
        for(auto it:mpp){
            if(it.second>1){
                k = it.second;
                c += k*(k-1)*4;
            }
        }
        return c;

    }
};