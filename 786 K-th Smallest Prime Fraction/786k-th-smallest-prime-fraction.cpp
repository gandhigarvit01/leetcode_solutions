class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        typedef pair<float,pair<int,int>> p;
        priority_queue<p, vector<p>, greater<p>> pq;
        int small = 0;
        float val = (float)arr[0]/float(arr[n-1]);
        pq.push({val,{0,n-1}});
        set<pair<int,int>> visited;
        visited.insert({0,n-1});
        while(small<k){
            small++;
            auto v = pq.top();
            pq.pop();
            int l = v.second.first;
            int r = v.second.second;
            if(small==k){
                return {arr[l],arr[r]};
            }
            if(l+1<r && !visited.count({l+1,r})){
                visited.insert({l+1,r});
                float val = (float)arr[l+1]/float(arr[r]);
                pq.push({val,{l+1,r}});
            }
            if(r-1>l && !visited.count({l,r-1})){
                visited.insert({l,r-1});
                float val = (float)arr[l]/float(arr[r-1]);
                pq.push({val,{l,r-1}});
            }
        }
        return {-1,-1};
    }
};