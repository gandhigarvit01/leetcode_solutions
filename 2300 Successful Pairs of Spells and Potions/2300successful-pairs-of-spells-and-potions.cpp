class Solution {
public:
    int find(vector<int> &potions, long long success, int p){
        int l=0, r=potions.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if((1LL*p)*potions[mid]>=success){
                r=mid-1;
            }
            else{
                l = mid+1;
            }
        }
        
        return r;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n);
        sort(potions.begin(), potions.end());
        for(int i=0; i<n; i++){
            int k = find(potions,success,spells[i]);
            pairs[i] = m-k-1;
        }
        return pairs;
    }
};