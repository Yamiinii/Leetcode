class MyCalendar {
public:
    map<int,int> cal;
MyCalendar() {}
bool book(int start, int end) {
    for(auto i:cal){
       if (start < i.second&& end > i.first ) {
            return false;
        }
    }
    cal[start]=end;
    return 1;
}
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */