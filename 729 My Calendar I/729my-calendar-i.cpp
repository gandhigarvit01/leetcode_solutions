class MyCalendar {
public:
    map<int,int> events;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        events[startTime] += 1;
        events[endTime] -= 1;

        int count = 0;
        for(auto& it : events){
            count += it.second;
            if(count>1){
                events[startTime] -= 1;
                events[endTime] += 1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */