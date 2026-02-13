class Solution {
public:
    vector<int> segmintree;
    vector<int> segmaxtree;
    vector<int> lazy;
    void propagate(int i, int l, int r){
        if(lazy[i]!=0){
            segmintree[i] += lazy[i];
            segmaxtree[i] += lazy[i];
            if(l!=r){
                lazy[2*i+1] += lazy[i];
                lazy[2*i+2] += lazy[i];
            }
            lazy[i] = 0;
        }
    }
    void range_update(int start, int end, int val, int i, int l, int r){
        propagate(i,l,r);
        if(l>end || r<start || l>r) return;
        if(l>=start && r<=end){
            lazy[i] += val;
            propagate(i,l,r);
            return;
        }
        int mid = (l+r)/2;
        range_update(start,end,val,2*i+1,l,mid);
        range_update(start,end,val,2*i+2,mid+1,r);
        segmintree[i] = min(segmintree[2*i+1],segmintree[2*i+2]);
        segmaxtree[i] = max(segmaxtree[2*i+1],segmaxtree[2*i+2]);
    }
    int leftest_zero(int i, int l, int r, int start, int end){
        propagate(i,l,r);
        if(l==r){
            if(segmintree[i]==0) return l;
            return -1;
        }
        if(l > end || r < start || l>r) return -1;
        if(segmintree[i]>0 || segmaxtree[i]<0) return -1;
        int mid = (l+r)/2;
        int left = leftest_zero(2*i+1,l,mid,start,end);
        if(left!=-1){
            return left;
        }
        return leftest_zero(2*i+2,mid+1,r,start,end);
    }
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        segmintree.resize(4*n,0);
        segmaxtree.resize(4*n,0);
        lazy.resize(4*n,0);
        unordered_map<int,int> mpp;
        for(int i=0; i<n; i++){
            int val = (nums[i]%2==0)?1:-1;
            if(mpp.find(nums[i])!=mpp.end()){
                int idx = mpp[nums[i]];
                range_update(0,idx,-val,0,0,n-1);
            }

            range_update(0,i,val,0,0,n-1);
            int ans = leftest_zero(0,0,n-1,0,i);
            if(ans!=-1) result = max(result,i-ans+1);
            mpp[nums[i]] = i;
        }
        return result;
    }
};