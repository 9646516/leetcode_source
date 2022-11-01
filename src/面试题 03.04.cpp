// id:374524924
// runtime:0 ms
// memory:6.7 MB
// title:Implement Queue using Stacks LCCI
// translatedTitle:化栈为队
// questionId:100170
// time:2022-10-19 16:16:58

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int>L,R;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        R.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(L.empty()){
            while(!R.empty()){
                int now=R.top();
                R.pop();
                L.push(now);
            }
        }
        int ret=L.top();
        L.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if(L.empty()){
            while(!R.empty()){
                int now=R.top();
                R.pop();
                L.push(now);
            }
        }
        int ret=L.top();
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return L.empty()&&R.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */