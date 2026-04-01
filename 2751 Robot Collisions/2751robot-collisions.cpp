class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<tuple<int,int,char>> vec;
        int n = positions.size();
        for(int i=0; i<n; i++){
            int pos = positions[i];
            int health = healths[i];
            char dir = directions[i];
            vec.push_back({pos,health,dir});
        }
        sort(vec.begin(),vec.end());
        stack<tuple<int,int,char>> st;
        for(int i=0; i<n; i++){
            int  pos = get<0>(vec[i]);
            int  health = get<1>(vec[i]);
            char dir = get<2>(vec[i]);
            if(st.empty()){
                st.push({pos,health,dir});
            }
            else{
                if(dir=='R' || get<2>(st.top())=='L'){
                    st.push({pos,health,dir});
                }
                else{
                    while(!st.empty() && get<2>(st.top())=='R' &&
                    health > get<1>(st.top())){
                        health--;
                        st.pop();
                    }
                    if(st.empty()){
                        st.push({pos,health,dir});
                    }
                    else if(get<2>(st.top())=='L'){
                        st.push({pos,health,dir});
                    }
                    else if(health == get<1>(st.top())){
                        st.pop();
                    }
                    else if(get<1>(st.top()) > health){
                        int pos2 = get<0>(st.top());
                        int health2 = get<1>(st.top());
                        int dir2 = get<2>(st.top());
                        health2--;
                        st.pop();
                        st.push({pos2,health2,dir2});
                    }
                }
            }
        }
        unordered_map<int,int> mpp;
        while(!st.empty()){
            auto t = st.top();
            int pos = get<0>(t);
            int health = get<1>(t);
            mpp[pos] = health;
            st.pop();
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(mpp.find(positions[i])!=mpp.end()){
                ans.push_back(mpp[positions[i]]);
            }
        }
        return ans;
    }
};