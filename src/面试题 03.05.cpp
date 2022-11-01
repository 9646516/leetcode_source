// id:374528016
// runtime:220 ms
// memory:45.6 MB
// title:Sort of Stacks LCCI
// translatedTitle:栈排序
// questionId:100173
// time:2022-10-19 16:24:32

class SortedStack {
public:
    stack<int>s;
    SortedStack() {

    }
    
    void push(int val) {
        static stack<int>s2;
        while(!s.empty()&&s.top()<val){
            s2.push(s.top());
            s.pop();
        }
        s.push(val);
        while(!s2.empty()){
            s.push(s2.top());
            s2.pop();
        }
    }
    
    void pop() {
        if(!s.empty())s.pop();
    }
    
    int peek() {
        if(s.empty())return -1;
        return s.top();
    }
    
    bool isEmpty() {
        return s.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */