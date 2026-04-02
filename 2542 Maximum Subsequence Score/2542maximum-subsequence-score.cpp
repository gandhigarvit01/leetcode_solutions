class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({nums1[i],nums2[i]});
        }
        sort(vec.begin(),vec.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
        greater<pair<int,int>>> pq;     // MIN HEAP -----  
        long long sum = 0;
        long long ans = 0;
        int i = n-1;
        for(i=n-1; i>=n-k; i--){
            sum += vec[i].first;
            pq.push({vec[i].second,vec[i].first});
        }
        ans = max(ans, 1LL*sum*pq.top().first);
        while(i>=0){
            auto p = pq.top();
            int val = p.second;
            int multi = p.first;
            pq.pop();
            sum -= val;
            sum += vec[i].first;
            pq.push({vec[i].second,vec[i].first});
            ans = max(ans, 1LL*sum*pq.top().first);
            i--;
        } 
        return ans; 
    }
};