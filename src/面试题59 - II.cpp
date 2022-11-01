// id:374989021
// runtime:112 ms
// memory:47.9 MB
// title:队列的最大值 LCOF
// translatedTitle:队列的最大值
// questionId:100337
// time:2022-10-20 23:02:11

class MaxQueue {
public:
    deque<pair<int,int>>q;
    deque<pair<int,int>>q2;
    int idx;
    MaxQueue() {
        idx=0;
    }
    
    int max_value() {
        if(q.empty())return -1;
        return q.front().second;
    }
    
    void push_back(int value) {
        q2.push_back({idx,value});
        while(!q.empty()&&q.back().second<=value){
            q.pop_back();
        }
        q.push_back({idx,value});
        idx++;
    }   
    
    int pop_front() {
        if(q2.empty())return -1;
        auto [idx,val]=q2.front();
        q2.pop_front();
        while(!q.empty()&&q.front().first<=idx)q.pop_front();
        return val;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */