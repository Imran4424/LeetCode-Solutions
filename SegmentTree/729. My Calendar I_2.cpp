class MyCalendar {
    map<int, int> booked;
public:
    MyCalendar() {
    booked = map<int, int>();
    }
    
    bool book(int start, int end) {
        for (auto it = booked.begin(); it != booked.end(); it++) {
            int startP = it->first;
            int endP = it->second;
            
            if (start < endP && end > startP) {
                return false;
            }
        }

        booked[start] = end;

        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */