class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        vector<long long> vec(n,0);
        int ht = mountainHeight;
        // pq -
        priority_queue<
        tuple<long long,int,int>, vector<tuple<long long,int,int>>, 
        greater<tuple<long long,int,int>>> pq;

        for(int i=0; i<n; i++){
            pq.push({1LL*workerTimes[i],i,1});
        }
        while(ht>0){
            long long val = get<0>(pq.top());
            int idx = get<1>(pq.top());
            int mul = get<2>(pq.top());
            ht--;
            pq.pop();
            vec[idx] = val;
            mul++;
            val += 1LL*workerTimes[idx]*mul;
            pq.push({val,idx,mul});
        }
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans,vec[i]);
        }
        return ans;
    }
};