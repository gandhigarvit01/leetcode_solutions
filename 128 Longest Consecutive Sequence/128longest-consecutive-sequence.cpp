class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        set<int> s;
        for(int i=0; i<n; i++){
            s.insert(nums[i]);
        }
        int k=1,m=1;
        auto it1=s.begin();
        auto it2=next(s.begin(),1);
        while(it2!=s.end()){
            if(*it2-*it1==1){
                k++;
                m=max(m,k);
            }
            else{
                k=1;
            }
            it1++;
            it2++;
        }
        return m;
    }
};