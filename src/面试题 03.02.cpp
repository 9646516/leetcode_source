// id:374520317
// runtime:24 ms
// memory:14.6 MB
// title:Min Stack LCCI
// translatedTitle:栈的最小值
// questionId:100169
// time:2022-10-19 16:05:47

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>s1,s2;
    MinStack() {

    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty())s2.push(x);
        else s2.push(min(x,s2.top()));
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */