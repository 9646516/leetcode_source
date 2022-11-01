// id:373914126
// runtime:128 ms
// memory:55.9 MB
// title:最近请求次数
// translatedTitle:最近请求次数
// questionId:1000293
// time:2022-10-17 19:39:29

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