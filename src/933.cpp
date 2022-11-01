// id:373924727
// runtime:116 ms
// memory:55.9 MB
// title:Number of Recent Calls
// translatedTitle:最近的请求次数
// questionId:969
// time:2022-10-17 20:06:00

class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {

    }
    
    int ping(int t) {
        q.push(t);
        while(q.front()<t-3000)q.pop();
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */