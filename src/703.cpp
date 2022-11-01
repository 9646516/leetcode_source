// id:373967437
// runtime:32 ms
// memory:19.4 MB
// title:Kth Largest Element in a Stream
// translatedTitle:数据流中的第 K 大元素
// questionId:789
// time:2022-10-17 21:46:07

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