class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        set<int> s;
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        int k=0,m=0;
        auto it1 = s.begin();
        auto it2 = next(s.begin(),1);
        while(it2!=s.end()){
            k= *it2-*it1;
            m = max(m,k);
            it1++;
            it2++;
        }
        return m;
    }
};