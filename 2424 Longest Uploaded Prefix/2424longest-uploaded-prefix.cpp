class LUPrefix {
public:
    vector<int> segmentree;
    void update(int i, int l, int r, int idx){
        if(l==r){
            segmentree[i] = 1;
            return;
        }
        int mid = (l+r)/2;
        if(idx<=mid){
            update(2*i+1,l,mid,idx);
        }
        else update(2*i+2,mid+1,r,idx);
        segmentree[i] = segmentree[2*i+1] + segmentree[2*i+2];
    }
    int find(int i, int l, int r){
        if(l==r){
            return segmentree[i];
        }
        int mid = (l+r)/2;
        if(segmentree[2*i+1]==mid-l+1){
            return segmentree[2*i+1] + find(2*i+2,mid+1,r);
        }
        else return find(2*i+1,l,mid);
    }
    int m;
    LUPrefix(int n) {
        m = n;
        segmentree.resize(4*n,0);
    }
    void upload(int video) {
        update(0,0,m-1,video-1);
    }
    int longest() {
        return find(0,0,m-1);
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */