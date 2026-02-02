class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long ans = 0;
        ans += nums[0];
        multiset<int> ms1,ms2;
        for(int i=1; i<=1+dist; i++){
            ms1.insert(nums[i]);
        }
        int cnt = 1;
        for(auto it = ms1.begin(); it!=ms1.end(); ){
            if(cnt<=k-1){
                ans += *it;
                cnt++;
                it++;
            }
            else{
                ms2.insert(*it);
                it = ms1.erase(it);
            }
        }
        long long curr = ans;
        for(int i=2; i<=n-1-dist; i++){
            int pre = nums[i-1];
            auto it1 = ms1.find(pre);
            if(it1!=ms1.end()){
                ms1.erase(it1);
                curr -= pre;
                if(ms2.empty() || nums[i+dist]<=*ms2.begin()){
                    ms1.insert(nums[i+dist]);
                    curr += nums[i+dist];
                }
                else{
                    auto it = ms2.begin();
                    ms1.insert(*it);
                    curr += *it;
                    ms2.erase(it);
                    ms2.insert(nums[i+dist]);
                }
            }
            else{
                auto it2 = ms2.find(pre);
                if(it2!=ms2.end()) ms2.erase(it2);

                if(nums[i+dist]<=*ms1.rbegin()){
                    auto it = prev(ms1.end());
                    curr -= *it;
                    ms2.insert(*it);
                    ms1.erase(it);
                    ms1.insert(nums[i+dist]);
                    curr += nums[i+dist];
                }
                else{
                    ms2.insert(nums[i+dist]);
                }
            }
            ans = min(ans,curr);
        }
        return ans;
    }
};