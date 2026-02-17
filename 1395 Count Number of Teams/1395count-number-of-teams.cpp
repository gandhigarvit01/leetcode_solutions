class Solution {
public:
    vector<int> segmintree;
    vector<int> segmaxtree;
    void built(int i, int l, int r, vector<int>& rating){
        if(l==r){
            segmintree[i] = rating[l];
            segmaxtree[i] = rating[l];
            return;
        }
        int mid = (l+r)/2;
        built(2*i+1,l,mid,rating);
        built(2*i+2,mid+1,r,rating);
        segmintree[i] = min(segmintree[2*i+1],segmintree[2*i+2]);
        segmaxtree[i] = max(segmaxtree[2*i+1],segmaxtree[2*i+2]);
    }
    int high,low;
    void findhigh(int i, int l, int r, int start, int end, int val){
        if(r<start || l>end || l>r || segmaxtree[i]<val) return;
        if(l>=start && r<=end && segmintree[i] >= val){
            high += r-l+1;
            return;
        }
        if(l==r) return;
        int mid = (l+r)/2;
        findhigh(2*i+1,l,mid,start,end,val);
        findhigh(2*i+2,mid+1,r,start,end,val);
    }
    void findlow(int i, int l, int r, int start, int end, int val){
        if(r<start || l>end || l>r || segmintree[i]>val) return;
        if(l>=start && r<=end && segmaxtree[i] <= val){
            low += r-l+1;
            return;
        }
        if(l==r) return;
        int mid = (l+r)/2;
        findlow(2*i+1,l,mid,start,end,val);
        findlow(2*i+2,mid+1,r,start,end,val);
    }
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        segmintree.resize(4*n);
        segmaxtree.resize(4*n);
        built(0,0,n-1,rating);
        int ans = 0;
        for(int i=1; i<n-1; i++){
            high = 0, low = 0;
            findhigh(0,0,n-1,0,i-1,rating[i]);
            findlow(0,0,n-1,i+1,n-1,rating[i]);
            ans += high*low;
            high = 0, low = 0;
            findlow(0,0,n-1,0,i-1,rating[i]);
            findhigh(0,0,n-1,i+1,n-1,rating[i]);
            ans += high*low;
        }
        return ans;
    }
};