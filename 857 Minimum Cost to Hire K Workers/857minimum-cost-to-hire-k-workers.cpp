class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double ans = 0.0;
        typedef pair<double,int> p;
        priority_queue<p> pq; /// MAX HEAP;
        vector<pair<int,double>> vec;
        for(int i=0; i<n; i++){
            int qual = quality[i];
            int wag = wage[i];
            double ratio = (double)wag/(double)qual;      // ratio to be minimised;
            vec.push_back({qual,ratio}); 
        }
        sort(vec.begin(),vec.end());
        int i = 0;
        double sum = 0;
        for(i=0; i<k; i++){
            sum += vec[i].first;
            pq.push({vec[i].second,vec[i].first});
        }
        ans = 1.0*sum*pq.top().first;
        while(i <= n-1){
            auto v = pq.top();
            pq.pop();
            sum -= v.second;
            sum += vec[i].first;
            pq.push({vec[i].second,vec[i].first});
            ans = min(ans, 1.0*sum*pq.top().first);
            i++;
        }
        return ans;
    }
};