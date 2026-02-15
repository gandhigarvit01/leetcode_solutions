class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> ans;
        vector<int> bulbs_on(101,0);
        int n = bulbs.size();
        for(int i=0; i<n; i++){
            bulbs_on[bulbs[i]]++;
        }
        for(int i=1; i<=100; i++){
            if(bulbs_on[i]%2 != 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};