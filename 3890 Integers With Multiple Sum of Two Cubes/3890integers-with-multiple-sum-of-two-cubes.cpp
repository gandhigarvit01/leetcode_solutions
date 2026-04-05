class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int,int> mp;
        int limit = cbrt(n);
        for(int a=1; a<=limit; a++){
            long long a3 = 1LL*a*a*a;
            for(int b=a; b<=limit; b++){
                long long sum = a3 + 1LL*b*b*b;
                if(sum > n) break;
                mp[(int)sum]++;
            }
        }
        vector<int> ans;
        for(auto &it : mp) {
            if(it.second>=2) {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};