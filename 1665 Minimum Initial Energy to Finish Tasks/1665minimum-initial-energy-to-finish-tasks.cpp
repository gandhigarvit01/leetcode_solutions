class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[1]==b[1]) return a[0] > b[0];
        return a[1] > b[1];
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        vector<vector<int>> vec;
        for(auto v : tasks){
            int initial = v[1];
            int rem = v[1] - v[0];
            vec.push_back({initial,rem});
        }
        sort(vec.begin(), vec.end(), comp);
        int ans = 0, curr = 0;
        int n = vec.size();
        for(int i=0; i<n; i++){
            if(curr >= vec[i][0]) curr -= (vec[i][0]-vec[i][1]);
            else{
                int need = vec[i][0] - curr;
                ans += need;
                curr = vec[i][1];
            }
        }
        return ans;
    }
};