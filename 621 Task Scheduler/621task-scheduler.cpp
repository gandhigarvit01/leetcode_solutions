class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        vector<int> count(26,0);
        for(int i=0; i<m; i++){
            count[tasks[i]-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0; i<26; i++){
            int freq = count[i];
            if(freq>0) pq.push(freq);
        }
        int ans = m;
        while(!pq.empty()){
            int freq = pq.top();
            freq--;
            pq.pop();
            if(freq>0){
                int gap = n;
                vector<int> temp;
                temp.push_back(freq);
                while(gap && !pq.empty()){
                    int freq1 = pq.top();
                    pq.pop();
                    freq1--;
                    if(freq1>0){
                        temp.push_back(freq1);
                    }
                    gap--;
                }
                ans += gap;
                for(auto v : temp){
                    pq.push(v);
                }
            }
        }
        return ans;
    }
};