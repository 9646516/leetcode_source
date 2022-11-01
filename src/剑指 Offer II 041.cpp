// id:373913203
// runtime:24 ms
// memory:13.5 MB
// title:滑动窗口的平均值
// translatedTitle:滑动窗口的平均值
// questionId:1000292
// time:2022-10-17 19:37:07

class MovingAverage {
public:
    /** Initialize your data structure here. */
    int sz,xs;
    deque<int>q;
    MovingAverage(int size) {
        sz=size;
        xs=0;
    }
    
    double next(int val) {
        xs+=val;
        q.push_back(val);
        if(q.size()>sz){
            xs-=q.front();
            q.pop_front();
        }
        return 1.0*xs/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */