// id:373883145
// runtime:256 ms
// memory:94.7 MB
// title:插入、删除和随机访问都是 O(1) 的容器
// translatedTitle:插入、删除和随机访问都是 O(1) 的容器
// questionId:1000267
// time:2022-10-17 17:41:33

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int>V;
    unordered_map<int,int>mp;
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(mp.count(val)){
            return 0;            
        }
        V.push_back(val);
        mp[val]=V.size()-1;
        return 1;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.count(val)){
            if(mp[val]!=V.size()-1){
                int last=V.back();
                swap(V[mp[val]],V[V.size()-1]);
                swap(mp[val],mp[last]);
            }
            mp.erase(val);
            V.pop_back();
            return true;
        }
        return false;
    }

    
    /** Get a random element from the set. */
    int getRandom() {
        return V[rand()%V.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */