// id:373585576
// runtime:96 ms
// memory:40.8 MB
// title:数据流中的中位数  LCOF
// translatedTitle:数据流中的中位数
// questionId:100303
// time:2022-10-16 19:02:15

class MedianFinder {
public:
    priority_queue<int>L;
    priority_queue<int,vector<int>,greater<int>>R;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(L.empty()||num<=L.top())L.push(num);
        else {
            R.push(num);
        }
        while((int)L.size()-(int)R.size()>1){
            auto last=L.top();
            L.pop();
            R.push(last);
        }
        while((int)L.size()<(int)R.size()){
            auto last=R.top();
            R.pop();
            L.push(last);
        }
    }
    
    double findMedian() {
        if(L.size()==R.size()){
            return (L.top()+R.top())/2.0;
        }else{
            return L.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */