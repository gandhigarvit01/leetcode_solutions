class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string,int> mpp;
        for(int i=0; i<n; i++){
            mpp[words[i]]++;
        }
        vector<pair<string,int>> vec;
        for(auto it : mpp){
            vec.push_back({it.first,it.second});
        }
        auto lambda = [](pair<string,int> p1, pair<string,int> p2){
            if(p1.second==p2.second){
                return p1.first < p2.first;
            }
            return p1.second > p2.second;
        };
        sort(vec.begin(),vec.end(),lambda);
        int i=0;
        vector<string> ans;
        while(i<k){
            ans.push_back(vec[i].first);
            i++;
        }
        return ans;
    }
};