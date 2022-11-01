// id:373966129
// runtime:44 ms
// memory:19.3 MB
// title:数据流的第 K 大数值
// translatedTitle:数据流的第 K 大数值
// questionId:1000323
// time:2022-10-17 21:43:04

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>q;int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i:nums){
            q.push(i);
            if(q.size()>k)q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>k)q.pop();
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */