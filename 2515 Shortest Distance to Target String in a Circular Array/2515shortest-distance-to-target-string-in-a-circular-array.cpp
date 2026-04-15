class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int n = words.size();
        vector<int> vec;
        for(int i=0; i<n; i++){
            if(words[i]==target){
                int dist = abs(i-startIndex);
                int mini = min(dist, n-dist);
                ans = min(ans, mini);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};