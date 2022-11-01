// id:373299796
// runtime:20 ms
// memory:14.7 MB
// title:包含min函数的栈 LCOF
// translatedTitle:包含min函数的栈
// questionId:100302
// time:2022-10-15 20:54:34

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>s,s2;
    MinStack() {}
    
    void push(int x) {
        s.push(x);
        if(!s2.empty())s2.push(std::min(s2.top(),x));
        else s2.push(x);
    }
    
    void pop() {
        s.pop();
        s2.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */