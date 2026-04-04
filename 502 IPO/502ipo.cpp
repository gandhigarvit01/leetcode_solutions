class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> vec;
        int n = capital.size();
        for(int i=0; i<n; i++){
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(),vec.end());
        int i=0;
        priority_queue<int> pq;
        while(k){
            while(i<n && vec[i][0]<=w){
                pq.push(vec[i][1]);
                i++;
            }
            if(pq.empty()){
                return w;
            }
            w += pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};