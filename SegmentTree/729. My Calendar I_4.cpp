class MyCalendar {
    set< pair<int, int> > booked;
public:
    MyCalendar() {
    booked = set< pair<int, int> >();
    }
    
    bool book(int start, int end) {
        auto next = booked.lower_bound({start, end});

        if (next != booked.end() && next->first < end) { // next
            return false;
        }

        if (next != booked.begin() && (--next)->second > start) { // prev
            return false;
        }

        booked.insert({start , end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */