class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        typedef pair<int,pair<int,int>> p;
        priority_queue<p, vector<p>, greater<p>> pq1;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            pq1.push({nums[i][0],{i,0}});
            maxi = max(maxi,nums[i][0]);
        }
        int a,b;
        a = pq1.top().first;
        b = maxi;
        while(!pq1.empty()){
            int i = pq1.top().second.first;
            int j = pq1.top().second.second;
            pq1.pop();
            if(j<nums[i].size()-1){
                pq1.push({nums[i][j+1],{i,j+1}});
                maxi = max(maxi,nums[i][j+1]);
            }
            else{
                break;
            }
            if(maxi-pq1.top().first < b-a){
                a = pq1.top().first;
                b = maxi;
            }
        }
        return {a,b};
    }
};