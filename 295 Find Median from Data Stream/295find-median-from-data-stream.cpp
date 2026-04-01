class MedianFinder {
public:
    priority_queue<int, vector<int>> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    MedianFinder() {
    }
    void addNum(int num) {
        if(pq1.empty()){
            pq1.push(num);
        }
        else if(pq2.empty()){
            pq1.push(num);
            int el = pq1.top();
            pq1.pop();
            pq2.push(el);
        }
        else{
            if(pq1.size()==pq2.size()){
                int b = pq2.top();
                if(num>b){
                    pq1.push(b);
                    pq2.pop();
                    pq2.push(num);
                }
                else{
                    pq1.push(num);
                }
            }
            else{
                int a = pq1.top();
                if(num>=a){
                    pq2.push(num);
                }
                else{
                    pq2.push(a);
                    pq1.pop();
                    pq1.push(num);
                }
            }
        }
    }
    double findMedian() {
        double ans;
        if(pq1.size()>pq2.size()){
            ans = (double)pq1.top();
        }
        else{
            ans = ((double)pq1.top() + (double)pq2.top())/2.0;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */