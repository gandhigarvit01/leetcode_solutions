class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        typedef pair<int,pair<int,int>> p;
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<p, vector<p>, greater<p>> pq;
        set<pair<int,int>> visited;
        pq.push({nums1[0]+nums2[0],{0,0}});
        visited.insert({0,0});
        while(k>0){
            auto it = pq.top();
            pq.pop();
            int i = it.second.first;
            int j = it.second.second;
            ans.push_back({nums1[i],nums2[j]});
            if(i+1<n){
                if(!visited.count({i+1,j})){
                    pq.push({nums1[i+1]+nums2[j],{i+1,j}});
                    visited.insert({i+1,j});
                }
            }
            if(j+1<m){
                if(!visited.count({i,j+1})){
                    pq.push({nums1[i]+nums2[j+1],{i,j+1}});
                    visited.insert({i,j+1});
                }
            }
            k--;
        }
        return ans;
    }
};