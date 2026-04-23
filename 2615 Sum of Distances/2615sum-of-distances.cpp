class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre(n);
        unordered_map<int,pair<int,int>> mpp;  // maps value with its last index and its freq before;
        for(int i=0; i<n; i++){
            int val = nums[i];
            if(mpp.find(val)==mpp.end()){
                pre[i] = 0;
                mpp[val] = {i,1};
            }
            else{
                int idx = mpp[val].first;
                int freq = mpp[val].second;
                pre[i] = pre[idx] + 1LL*freq*(i-idx);
                mpp[val] = {i,freq+1};
            }
        }
        vector<long long> suff(n);
        mpp.clear();
        for(int i=n-1; i>=0; i--){
            int val = nums[i];
            if(mpp.find(val)==mpp.end()){
                suff[i] = 0;
                mpp[val] = {i,1};
            }
            else{
                int idx = mpp[val].first;
                int freq = mpp[val].second;
                suff[i] = suff[idx] + 1LL*freq*(idx-i);
                mpp[val] = {i,freq+1};
            }
        }
        for(int i=0; i<n; i++){
            pre[i] += suff[i];
        }
        return pre;
    }
};