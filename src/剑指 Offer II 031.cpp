// id:373892905
// runtime:544 ms
// memory:169.8 MB
// title:最近最少使用缓存
// translatedTitle:最近最少使用缓存
// questionId:1000270
// time:2022-10-17 18:20:00

class LRUCache {
public:
    int cap;
    list<pair<int,int>>V;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            auto pos=mp[key];
            auto [k,v]=*pos;
            V.erase(pos);
            V.push_back({k,v});
            mp[key]=prev(V.end());
            return v;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            V.erase(mp[key]);
            V.push_back({key,value});
            mp[key]=prev(V.end());
        }else{
            if(V.size()==cap){
                auto [k,v]=*V.begin();
                V.erase(V.begin());
                mp.erase(k);
            }
            V.push_back({key,value});
            mp[key]=prev(V.end());
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */