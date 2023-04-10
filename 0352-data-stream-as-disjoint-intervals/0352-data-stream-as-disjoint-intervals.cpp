class SummaryRanges {
set<int>s;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>intervals;
        if(s.empty()){
            return {};
        }
        int start=-1,end1=-1,last=-1,cur=-1;
        for (auto q:s) {
            cur=q;
            if (start==-1) {
                start=end1=cur;
            } else if (cur == end1+1) {
                end1=cur;
            } else {
                intervals.push_back({start,end1});
                start=end1=cur;
            }
        }
        intervals.push_back({start,end1});
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */