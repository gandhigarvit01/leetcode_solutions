class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        typedef pair<int,int> p;
        vector<bool> marked(n);
        int mark = 0;
        priority_queue<p, vector<p>, greater<p>> pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i],i});
        }
        while(mark<n){
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(!marked[idx]){
                score += val;
                marked[idx] = true;
                mark++;
                if(idx-1>=0 && !marked[idx-1]){
                    mark++;
                    marked[idx-1] = true;
                }
                if(idx+1<n && !marked[idx+1]){
                    mark++;
                    marked[idx+1] = true;
                }
            }
        }
        return score;
    }
};