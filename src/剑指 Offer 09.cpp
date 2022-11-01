// id:373274606
// runtime:296 ms
// memory:101 MB
// title:用两个栈实现队列 LCOF
// translatedTitle:用两个栈实现队列
// questionId:100273
// time:2022-10-15 19:18:40

class CQueue {
public:
    stack<int>l,r;
    CQueue() {

    }
    
    void appendTail(int value) {
        r.push(value);
    }
    
    int deleteHead() {
        if(l.empty()&&r.empty())return -1;
        else{
            if(l.empty()){
                while(!r.empty()){
                    l.push(r.top());
                    r.pop();
                }
            }
            int ret=l.top();
            l.pop();
            return ret;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */