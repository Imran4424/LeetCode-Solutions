class MyCalendar {
    map<int, int> booked;
public:
    MyCalendar() {
    booked = map<int, int>();
    }
    
    bool book(int start, int end) {
        auto next = booked.upper_bound(start);

        if (next != booked.end() && next->second < end) { // next
            return false;
        }

        booked[end] = start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */