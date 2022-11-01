// id:374949673
// runtime:120 ms
// memory:46.3 MB
// title:Continuous Median LCCI
// translatedTitle:连续中值
// questionId:1000028
// time:2022-10-20 21:07:43

class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int>s1,s2;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(s1.empty())s1.insert(num);
        else if(num>*prev(s1.end())){
            s2.insert(num);
        }else{
            s1.insert(num);
        }
        while(s1.size()>s2.size()){
            auto p=*prev(s1.end());
            s1.erase(prev(s1.end()));
            s2.insert(p);
        }
        while(s1.size()<s2.size()){
            auto p=*s2.begin();
            s2.erase(s2.begin());
            s1.insert(p);
        }
    }
    
    double findMedian() {
        if((s1.size()+s2.size())&1)return *prev(s1.end());
        else return (*prev(s1.end())+*s2.begin())/2.0;

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */