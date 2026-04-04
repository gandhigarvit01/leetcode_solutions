class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> ans(n,0);
        long long sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int,int>> temp1;
        vector<int> temp2;
        for(int i=0; i<n; i++){
            temp1.push_back({nums1[i],i});
        }
        sort(temp1.begin(),temp1.end());
        for(int i=0; i<n; i++){
            int idx = temp1[i].second;
            temp2.push_back(nums2[idx]);
        }
        sum = 0;
        int l=0;
        ans[temp1[0].second] = 0;
        for(int i=1; i<n; i++){
            int idx = temp1[i].second;
            int curr = temp1[i].first;
            while(temp1[l].first < curr){
                sum += temp2[l];
                pq.push(temp2[l]);
                if(pq.size()>k){
                    sum -= pq.top();
                    pq.pop();
                }
                l++;
            }
            ans[idx] = sum;
        }
        return ans;
    }
};