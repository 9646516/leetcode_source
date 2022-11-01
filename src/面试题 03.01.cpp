// id:374519827
// runtime:60 ms
// memory:32.1 MB
// title:Three in One LCCI
// translatedTitle:三合一
// questionId:100172
// time:2022-10-19 16:04:38

class TripleInOne {
public:
    int pos[3];
    int sz;
    vector<int>V;
    TripleInOne(int stackSize) {
        pos[0]=pos[1]=pos[2]=0;
        sz=stackSize;
        V.resize(sz*3);
    }
    
    void push(int stackNum, int value) {
        if(pos[stackNum]!=sz){
            int L=sz*stackNum;
            V[L+pos[stackNum]]=value;
            pos[stackNum]++;
        }
    }
    
    int pop(int stackNum) {
        if(pos[stackNum]==0)return -1;
        else {
            int L=sz*stackNum;
            int ret=V[L+pos[stackNum]-1];
            pos[stackNum]--;
            return ret;
        }
    }
    
    int peek(int stackNum) {
        if(pos[stackNum]==0)return -1;
        else {
            int L=sz*stackNum;
            int ret=V[L+pos[stackNum]-1];
            return ret;
        }
    }
    
    bool isEmpty(int stackNum) {
        return pos[stackNum]==0;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */