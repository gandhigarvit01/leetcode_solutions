class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> mpp;
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            mpp[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        if(mpp.find(value)==mpp.end()) return 0;
        auto& vec = mpp[value];
        int l = lower_bound(vec.begin(), vec.end(), left) - vec.begin();
        int r = upper_bound(vec.begin(), vec.end(), right) - vec.begin();
        return r-l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */