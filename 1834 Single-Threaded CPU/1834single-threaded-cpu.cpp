class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        int n = tasks.size();
        long long time = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>  pq;     // MIN HEAP ------
        vector<vector<int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({tasks[i][0],tasks[i][1],i}); 
        }
        sort(vec.begin(),vec.end());
        int j = 0;
        while(!pq.empty() || j<n){

            if(pq.empty()){
                time = vec[j][0];
                while(j<n && vec[j][0]==time){
                    pq.push({vec[j][1],vec[j][2]});
                    j++;
                }
            }

            auto p = pq.top();
            pq.pop();
            time += p.first;
            ans.push_back(p.second);

            while(j<n && vec[j][0]<=time){
                pq.push({vec[j][1],vec[j][2]});
                j++;
            }
        }
        return ans;
    }
};