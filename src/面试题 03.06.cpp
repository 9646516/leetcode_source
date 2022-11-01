// id:374533636
// runtime:160 ms
// memory:109.7 MB
// title:Animal Shelter LCCI
// translatedTitle:动物收容所
// questionId:100228
// time:2022-10-19 16:38:01

queue<pair<int,int>>st[2];
class AnimalShelf {
public:
    int idx;
    AnimalShelf() {
        idx=0;
        while(!st[0].empty())st[0].pop();
        while(!st[1].empty())st[1].pop();
    }
    
    void enqueue(vector<int> animal) {
        int a=animal[0];
        int b=animal[1];
        st[b].push({idx++,a});
    }
    
    vector<int> dequeueAny() {
        if(st[0].empty()&&st[1].empty())return {-1,-1};
        if(st[0].empty()){
            auto [a,b]=st[1].front();
            st[1].pop();
            return {b,1};
        }
        if(st[1].empty()){
            auto [a,b]=st[0].front();
            st[0].pop();
            return {b,0};
        }
        auto [a1,b1]=st[0].front();
        auto [a2,b2]=st[1].front();
        if(a1<a2){
            st[0].pop();
            return {b1,0};
        }else{
            st[1].pop();
            return {b2,1};
        }

        
    }
    
    vector<int> dequeueDog() {
        if(st[1].empty())return {-1,-1};
        auto [a,b]=st[1].front();
        st[1].pop();
        return {b,1};
    }
    
    vector<int> dequeueCat() {
        if(st[0].empty())return {-1,-1};
        auto [a,b]=st[0].front();
        st[0].pop();
        return {b,0};
    }
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */