// id:374523957
// runtime:56 ms
// memory:27.3 MB
// title:Stack of Plates LCCI
// translatedTitle:堆盘子
// questionId:100195
// time:2022-10-19 16:14:28

class StackOfPlates {
public:
    int cap;
    vector<stack<int>>V;
    StackOfPlates(int cap) {
        this->cap=cap;
    }
    
    void push(int val) {
        if (cap == 0) return;
        if(V.empty()||V.back().size()==cap){
            V.push_back({});
        }
        V.back().push(val);
    }
    
    int pop() {
        if(V.empty())return -1;
        int ret=V.back().top();
        V.back().pop();
        if(V.back().empty())V.pop_back();
        return ret;
    }
    
    int popAt(int index) {
        if(V.size()<=index)return -1;
        int ret=V[index].top();
        V[index].pop();
        if(V[index].empty())V.erase(V.begin()+index);
        return ret;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */