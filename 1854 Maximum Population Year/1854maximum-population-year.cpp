class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<pair<int,int>> pop;
        for(auto& vec : logs){
            pop.push_back({vec[0],1});
            pop.push_back({vec[1],-1});
        }
        sort(pop.begin(),pop.end());
        int ans = 0, year = 0, curr = 0;
        int n = pop.size();
        for(int i=0; i<n; i++){
            if(pop[i].second==1){
                curr += 1;
            }
            else{
                curr -= 1;
            }
            if(curr>ans){
                ans = curr;
                year = pop[i].first;
            }
        }
        return year;
    }
};