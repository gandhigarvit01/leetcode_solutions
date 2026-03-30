class Solution {
public:
    int mod = 1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,pair<int,int>> mpp;
        for(int i=0; i<n; i++){
            if(mpp.find(nums[i])!=mpp.end()){
                mpp[nums[i]].second = i;
            }
            else{
                mpp[nums[i]] = {i,i};
            }
        }
        set<pair<int,int>> st;
        for(auto it : mpp){
            st.insert(it.second);
        }
        vector<pair<int,int>> vec;
        for(auto it : st){
            if(vec.empty()){
                vec.push_back(it);
            }
            else{
                auto p = vec.back();
                int first = p.first;
                int last = p.second;
                if(it.first>last){
                    vec.push_back(it);
                }
                else{
                    vec.pop_back();
                    vec.push_back({first,max(it.second,last)});
                }
            }
        }
        int m = vec.size();
        vector<int> power(m);
        power[0] = 1;
        for(int i=1; i<m; i++){
            power[i] = ((power[i-1]% mod) * 2)% mod;
        }
        return power[m-1];
    }
};