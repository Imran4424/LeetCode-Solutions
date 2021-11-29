class MyCalendar {
    map<int, int> booked;
public:
    MyCalendar() {
    booked = map<int, int>();
    }
    
    bool book(int start, int end) {
        auto next = booked.lower_bound(start);

        if (next != booked.end() && next->first < end) { // next
            return false;
        }

        if (next != booked.begin() && (--next)->second > start) { // prev
            return false;
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