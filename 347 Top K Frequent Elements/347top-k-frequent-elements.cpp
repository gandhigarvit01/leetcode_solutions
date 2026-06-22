class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(auto it : mpp){
            pq.push({it.second,it.first});
        }
        while(k--){
            auto p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};