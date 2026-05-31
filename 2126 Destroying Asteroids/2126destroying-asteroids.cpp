class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long wt = mass;
        int n = asteroids.size();
        for(int i=0; i<n; i++){
            if(asteroids[i]>wt) return false;
            wt += asteroids[i];
        }
        return true;
    }
};