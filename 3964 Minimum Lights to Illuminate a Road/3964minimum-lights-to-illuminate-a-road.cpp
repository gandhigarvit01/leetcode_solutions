class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            if(lights[i]!=0){
                int l = max(0,i-lights[i]);
                int r = min(n-1,i+lights[i]);
                vec.push_back({l,r});
            }
        }
        sort(vec.begin(),vec.end());
        int start = -1, end = -1;
        for(int i=0; i<vec.size(); i++){
            start = max(start,vec[i].first);
            end = max(end,vec[i].second);
            for(int j=start; j<=end; j++){
                lights[j] = 1;
            }
            start = max(start,end+1);
        }
        int count = 0;
        int continued = 0;
        for(int i=0; i<n; i++){
            if(lights[i]==0){
                if(continued==0){
                    count++;
                    continued = 1;
                }
                else if(continued==1) continued++;
                else continued = 0;
            }
            else{
                continued = 0;
            }
        }
        return count;
    }
};