class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> mpp;
        unordered_map<int,int> freq;
        for(int i=0; i<n; i++){
            mpp.clear();
            freq.clear();
            for(int j=i; j<n; j++){
                if(mpp.find(nums[j])==mpp.end()){
                    mpp[nums[j]]++;
                    freq[1]++;
                }
                else{
                    int prev_freq = mpp[nums[j]];
                    mpp[nums[j]]++;
                    int new_freq = mpp[nums[j]];
                    freq[prev_freq]--;
                    if(freq[prev_freq]==0){
                        freq.erase(prev_freq);
                    }
                    freq[new_freq]++;
                }
                // checking
                if(freq.size()==1){
                    auto it = freq.begin();
                    int key = it->first;
                    int val = it->second;
                    if(val==1) ans = max(ans, key*val);
                }
                else if(freq.size()==2){
                    auto it = freq.begin();
                    int key1 = it->first;
                    int val1 = it->second;
                    it++;
                    int key2 = it->first;
                    int val2 = it->second;
                    if(key1==2*key2 || key2==2*key1) ans = max(ans, (key1*val1 + key2*val2));
                }
            }
        }
        return ans;
    }
};