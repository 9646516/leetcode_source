// id:374874594
// runtime:96 ms
// memory:38.2 MB
// title:LRU Cache LCCI
// translatedTitle:LRU 缓存
// questionId:1000026
// time:2022-10-20 17:04:57

class LRUCache {
    list<pair<int,int>>V;
    map<int,list<pair<int,int>>::iterator>mp;
    int cap;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(!mp.count(key))return -1;
        auto pos=mp[key];
        auto [k,v]=*pos;
        V.erase(pos);
        V.push_back({k,v});
        mp[key]=prev(V.end());
        return v;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            auto pos=mp[key];
            auto [k,v]=*pos;
            V.erase(pos);
            V.push_back({key,value});
            mp[key]=prev(V.end());
        }else{
            if(V.size()==cap){
                auto [k,v]=V.front();
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