// id:374005146
// runtime:4 ms
// memory:7.9 MB
// title:Map Sum Pairs
// translatedTitle:键值映射
// questionId:677
// time:2022-10-17 23:21:41

struct node{
    node*next[26];
    int xs;
};

class MapSum {
public:
    /** Initialize your data structure here. */
    node*root;
    unordered_map<string,int>mp;
    void add(node*now,const string&s,int val){
        for(char i:s){
            int B=i-'a';
            if(!now->next[B])now->next[B]=new node();
            now=now->next[B];
            now->xs+=val;
        }
    }
    MapSum() {
        root=new node();
    }
    
    void insert(string key, int val) {
        if(!mp.count(key)){
            add(root,key,val);
            mp[key]=val;
        }else{
            int done=mp[key];
            mp[key]=val;
            add(root,key,val-done);
        }
    }
    
    int sum(string s) {
        auto now=root;
        for(char i:s){
            int B=i-'a';
            if(!now->next[B])return 0;
            now=now->next[B];
        }
        return now->xs;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */