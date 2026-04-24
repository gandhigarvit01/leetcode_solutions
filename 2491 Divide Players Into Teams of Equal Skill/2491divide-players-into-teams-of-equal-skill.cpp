class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n = skill.size();
        int l=0, r=n-1;
        int target = skill[0] + skill[n-1];
        long long ans = 1LL*skill[0]*skill[n-1];
        l=1, r=n-2;
        while(l<r){
            if((skill[l] + skill[r]) != target) return -1;
            ans += 1LL*skill[l]*skill[r];
            l++;
            r--;
        }
        return ans;
    }
};